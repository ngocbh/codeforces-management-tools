from __future__ import absolute_import
from pyquery import PyQuery as pq
from lxml import html

from conmato.utils import *
from conmato.parameters import *
from conmato.csession import *
# from .check_plagiarism import *

import requests
import pandas as pd
import re
import os
import codecs
import random
import time
from tqdm import tqdm

def get_contest_name(session, contest_id, group_id=GROUP_ID):
    if not contest_id.isnumeric():
        contest_id = get_contest_id(contest_id)
    url = get_standings_url(contest_id, group_id)
    response = session.get(url)
    doc = pq(response.text)
    contest_name = doc('div').filter('.contest-name').find('a').text()
    contest_name = contest_name.replace(' ', '-').replace('\n', '')
    return contest_name


def get_contests(session, group_id=GROUP_ID):
    '''
            usage:	session = conmato.CSession()
                    conmato.get_contests(session)
            return:
                    a dictionary of contest_id as key and contest_name as value
                    example:
                    {'269187': 'Training 2 - EXHSEARCH - 20192'}
    '''
    url = GROUP_URL.format(group_id)
    response = session.get(url)
    doc = pq(response.text)
    table = doc('table').not_('.rtable').not_('.table-form')
    ret = {}
    for tr in pq(table.children()[1:])('tr'):
        contest_id = pq(tr).attr('data-contestid')
        logger.info(contest_id)
        if contest_id is None:
            continue
        contest_name = pq(tr).children().eq(0).remove('a').text()
        ret[contest_id] = contest_name
    return ret


def toggle_manager_mode(session, contest_id, group_id=GROUP_ID, mode='true'):
    url = GROUP_URL.format(group_id)
    response = session.get(url)
    doc = pq(response.text)
    csrf_token = doc('span').attr['data-csrf']
    payload = {
        "csrf_token": csrf_token,
        "contestId": contest_id,
        "newValue": mode,
        # "action": 'toggleMashupContestManagerMode',
    }
    headers = {}
    # headers['Host'] = 'codeforces.com'
    # headers['Accept-Encoding'] = 'gzip, deflate, br'
    # headers['Connection'] = 'keep-alive'

    headers['Accept'] = 'application/json, text/javascript, */*; q=0.01'
    headers['X-Csrf-Token'] = csrf_token
    headers['X-Requested-With'] = 'XMLHttpRequest'
    headers['User-Agent'] = 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.110 Safari/537.36'
    headers['Content-Type'] = 'application/x-www-form-urlencoded; charset=UTF-8'
    headers['Sec-Fetch-Site'] = 'same-origin'
    headers['Sec-Fetch-Mode'] = 'cors'
    headers['Sec-Fetch-Dest'] = 'empty'
    response = session.post(
        '{}/{}'.format(DATA_URL.format(group_id), 'mashup'),
        headers=headers,
        data=payload
    )
    print('response.text = ', response.text)
    if response.status_code == 200:
        return True
    else:
        logger.error(
            'toggle_manager_mode: an error while toggling manager mode')
        return False


def get_managed_contests(session, group_id=GROUP_ID, mode='true'):
    '''
            get contests and toggle manager mode for all contest
            usage:	session = conmato.CSession()
                            conmato.get_managed_contests(session)
            return:
                            a dictionary of contest_id as key and contestname as value
                            example:
                            {'269187': 'Training 2 - EXHSEARCH - 20192'}
    '''
    url = GROUP_URL.format(group_id)
    response = session.get(url)
    doc = pq(response.text)
    table = doc('table').not_('.rtable').not_('.table-form')
    ret = {}
    for tr in pq(table.children()[1:])('tr'):
        contest_id = pq(tr).attr('data-contestid')
        if contest_id is None:
            continue
        contest_name = pq(tr).children().eq(0).remove('a').text()
        ret[contest_id] = contest_name
        toggle_manager_mode(session, contest_id, group_id, mode)
    return ret

def get_username(data):
    return data.text()

def get_problem(data):
    try:
        return data.text().split(' ')[0]
    except ValueError or IndexError:
        return 'unknown'

def get_language(data):
    lang = data.text().lower()
    if 'c11' in lang or 'clang' in lang:
        return 'c'
    elif 'c++' in lang or 'clang++' in lang:
        return 'cc'
    elif 'java' in lang or 'javascript' not in lang:
        return 'java'
    elif 'javascript' in lang or 'js' in lang:
        return 'javascript'
    elif 'fpc' in lang or 'pascal' in lang:
        return 'pascal'
    elif 'python' in lang or 'pypy' in lang:
        return 'python'
    elif 'c#' in lang:
        return 'csharp'
    elif 'perl' in lang:
        return 'perl'
    return 'cc'

def get_score(data):
    if data('span').filter('.verdict-format-points').text().isnumeric():
        return data('span').filter('.verdict-format-points').text()
    return '0'

def get_code(session, data):
    # submission_url = 'https://codeforces.com/group/Ir5CI6f3FD/contest/255647/submission/62598185'
    submission_url = '{}{}'.format(CODEFORCES_URI, data('a').attr['href'])

    try:
        response = session.get(submission_url)
    except ConnectionError or ConnectionRefusedError:
        raise Exception(
            'Too many requests, Codeforces has rejected requests, please increase TIMESLEEP parameter in '
            'parameters.py file')

    tree2 = html.fromstring(response.text)
    doc = pq(response.text)
    try:
        pq(tree2.xpath('//*[@id="pageContent"]/div[3]/pre'))
        code = tree2.xpath('//*[@id="pageContent"]/div[3]/pre/text()')[0]
        return code
    except:
        raise Exception(
            'Too many requests, Codeforces has rejected requests, please increase TIMESLEEP parameter in parameters.py file')

def get_next_page(document):
    page_links = []
    iter_pagination = iter(document('div').filter('.pagination'))
    next(iter_pagination)
    links = document(next(iter_pagination))('a').filter('.arrow')
    for elem in links:
        if pq(elem).attr['href'] is not None:
            page_links.append(pq(elem).attr['href'])
    return page_links[-1]

CRAWLED = set()
def get_all_submission(session, url, output_dir, group_id=GROUP_ID, page=1, user_format=None):
    if url.isnumeric():
        contest_id = url
        url = get_status_url(contest_id, group_id=group_id)
    else:
        contest_id = get_contest_id(url)
    logger.info("Downloading submission from page {}...".format(url))
    response = session.get(url)
    if url != response.url:
        logger.error("url != response url in get_all_submission")

    doc = pq(response.text)
    table = doc('div').filter('.datatable')
    for row_e in tqdm(table.find('tr'), desc='Getting page '+str(page), unit=' submissions'):
        if pq(table(row_e)).attr['data-submission-id'] is not None:
            # crawl_checked submission data
            data = {'code': '', 'username': '', 'lang': '', 'score': '', 'problem': ''}
            iter_cell = iter(table(row_e)('td'))
            cell = next(iter_cell)
            code_cell = table(cell)
            next(iter_cell)
            cell = next(iter_cell)
            data['username'] = get_username(table(cell))
            # Check user-format
            if user_format != None and not re.match(user_format, data['username']):
                continue
            cell = next(iter_cell)
            data['problem'] = get_problem(table(cell))
            cell = next(iter_cell)
            data['lang'] = get_language(table(cell))
            cell = next(iter_cell)
            data['score'] = get_score(table(cell))
            filename = 'submission_{}/{}/{}_{}.{}'.format(contest_id, data['problem'], data['username'], data['score'],
                                                          data['lang'])
            filepath = os.path.join(output_dir, filename)

            # create directory
            create_dir(filepath)

            # check if the submission has the highest score
            is_highest_score = True
            working_dir = os.path.dirname(filepath)
            for file in os.listdir(working_dir):
                rer = re.compile(
                    '.*{}_(?P<score>\\d+).{}'.format(data['username'], data['lang']))
                rer = rer.match(file)
                if rer:
                    score = rer.group('score')
                    if int(score) < int(data['score']):
                        os.remove(os.path.join(working_dir, file))
                    else:
                        is_highest_score = False

            # dump new file
            if is_highest_score:
                with codecs.open(filepath, encoding='utf8', mode='w') as output:
                    data['code'] = get_code(session, code_cell)
                    output.write(data['code'])
                    sleep_duration = random.uniform(
                        float(TIMESLEEP) / 2, TIMESLEEP)
                    time.sleep(sleep_duration)

    logger.info("Downloaded submissions in {}".format(url))
    sleep_duration = random.uniform(float(TIMESLEEP) / 2, TIMESLEEP)
    logger.info(
        "Sleep in {}s to prevent Codeforces from rejecting requests...".format(TIMESLEEP))
    time.sleep(sleep_duration)

    # next page
    CRAWLED.add(url)
    next_page = get_next_page(doc)
    url = '{}{}'.format(CODEFORCES_URI, next_page)
    if url not in CRAWLED:
        get_all_submission(session, url, output_dir, group_id, page+1, user_format)
