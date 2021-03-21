from __future__ import absolute_import

from pyquery import PyQuery as pq

from conmato.utils import *
from conmato.parameters import *

import requests
import pandas as pd
import re
import os
import codecs
import time
import datetime
import pydot


class Results:
    def __init__(self, name, matches):
        self.name = name
        self.matches = matches


class Match:
    def __init__(self, first, second, lines, url, html):
        self.first = first
        self.second = second
        self.lines = lines
        self.url = url
        self.html = html

    @property
    def percent(self):
        return max(self.first.percent, self.second.percent)


class File:
    def __init__(self, name, percent):
        self.name = name
        self.percent = percent

    def __str__(self):
        return '{}_{}'.format(self.name, self.percent)

    def __hash__(self):
        return hash(self.name)


class Filter:
    def __init__(self, min_percent, min_lines):
        filters = ['filter', 'filteri', 'filterx', 'filterxi']
        for f in filters:
            setattr(self, f, None)
        self.min_percent = min_percent
        self.min_lines = min_lines

    def include(self, match):
        first = match.first.name
        second = match.second.name
        if (self.filter is not None and (first not in self.filter or second not
                                         in self.filter)):
            return False
        if (self.filteri is not None and (first not in self.filteri and second
                                          not in self.filteri)):
            return False
        if (self.filterx is not None and (first in self.filterx and second in
                                          self.filterx)):
            return False
        if (self.filterxi is not None and (first in self.filterxi or second in
                                           self.filterxi)):
            return False
        return match.lines > self.min_lines and (match.first.percent > self.min_percent or
                                                 match.second.percent > self.min_percent)


def parse_col(col):
    name, per = col.split()
    m = re.match(TRANSFORMER, name)
    if m:
        if m.groups():
            name = '_'.join(m.groups())
        else:
            name = m.group()
    per = int(re.search(r'\d+', per).group())
    return File(name, per)


def get_basefile(url):
    response = requests.get(url)
    doc = pq(response.text)
    pq(doc('tr')[1:]).remove()
    pq(doc('table')[1:]).remove()
    return doc


def get_results(basefile, name, moss_url):
    resp = requests.get(moss_url)
    # print(resp.text)
    doc = pq(resp.text)

    matches = []
    for row in doc('table')('tr')[1:]:
        try:
            row = pq(row)
            first, second, lines = map(lambda x: pq(x).text(), pq(row('td')))
            first = parse_col(first)
            second = parse_col(second)
            lines = int(lines)
            url = row('a').attr['href']
            row_html = pq(row)
            if re.search(r'\d+_\w_.*_\d+\.\w+', first.name):
                matches.append(Match(first, second, lines, url, row_html))
        except:
            pass

    fil = Filter(MIN_PERCENT, MIN_LINES)
    matches = list(filter(fil.include, matches))
    for match in matches:
        basefile('table').append(match.html)
    return Results(name, matches)


def merge_results(results):
    name = '+'.join(map(lambda x: x.name, results))
    matches = []
    for result in results:
        matches.extend(result.matches)
    return Results(name, matches)


def link_color(ratio):
    high = 0xE9, 0x01, 0x01
    low = 0xFF, 0xE3, 0x05

    # Normalized ratio
    if MIN_PERCENT != 100:
        min_ratio = MIN_PERCENT / 100
        ratio = (ratio - min_ratio) / (1 - min_ratio)

    color = [h * ratio + l * (1 - ratio) for h, l in zip(high, low)]
    return '#' + ''.join(hex(int(c))[2:].zfill(2) for c in color)


def image(results, outdir, index=None):
    format_name = 'png'
    show_loops = False
    hide_labels = True
    graph = pydot.Dot(graph_type='graph')

    print('Generating image for %s' % results.name)
    for m in results.matches:
        ratio = m.percent / 100
        color = link_color(ratio)
        extra_opts = {
            'color': color,
            'penwidth': 3,
        }
        if not hide_labels:
            extra_opts.update({
                'label': '{0}% ({1})'.format(m.percent, m.lines),
                'labelURL': m.url,
                'url': m.url,
                'fontcolor': color,
            })
        if m.first.name != m.second.name or show_loops:
            graph.add_edge(pydot.Edge(
                m.first.name, m.second.name, **extra_opts))

    filename = '%s.%s' % ('virtualization', format_name)
    filepath = os.path.join(outdir, filename)

    if os.path.exists(filename):
        os.remove(filename)

    graph.write(filepath, format=format_name)
    if format_name == 'xlib':
        os.remove(filepath)
    print('DONE')


def summarize(urls, outdir, min_lines=MIN_LINES, min_percent=MIN_PERCENT):
    print('Summarizing...')
    all_res = []
    if len(urls) == 0:
        print('Nothing to summarize')
        return

    basefile = None
    for name, url in urls.items():
        if not basefile:
            basefile = get_basefile(url)
        # res = get_results(basefile, name, url,
        #                   min_lines=min_lines, min_percent=min_percent)
        res = get_results(basefile, name, url)
        all_res.append(res)

    filepath = os.path.join(outdir, 'summarized_report.html')
    with codecs.open(filepath, encoding='utf8', mode='w') as f:
        f.write(basefile.outerHtml())

    punishments = set()
    merged = merge_results(all_res)
    for match in merged.matches:
        punishments.add(match.first.__str__())
        punishments.add(match.second.__str__())
    # print(type(match.first.__str__()))

    column_names = ['username', 'problem', 'score', 'new-score', 'similarity']
    row_list = []
    for name in punishments:
        try:
            rer = re.match(
                r'(?P<contest_id>\d+)_(?P<problem>\w)_(?P<username>.*)_(?P<score>\d+)\.(?P<lang>\w+)_(?P<percent>\d+)',
                name.__str__())
            d = {}
            d['username'] = rer.group('username')
            d['problem'] = rer.group('problem')
            d['score'] = rer.group('score')
            d['similarity'] = rer.group('percent')
            d['new-score'] = NEW_SCORE
            row_list.append(d)
        except:
            pass

    df = pd.DataFrame(row_list, columns=column_names)
    filepath = os.path.join(outdir, 'punishments.csv')
    df.to_csv(filepath, index=False)

    try:
        if VIRTUALIZATION:
            image(merged, outdir)
    except:
        print('An error while generating the picture, please check pydot and graphviz installation.')
    return row_list
#
