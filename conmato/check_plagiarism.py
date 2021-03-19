from __future__ import absolute_import
from pyquery import PyQuery as pq
from lxml import html

from .utils import *
from .parameters import *
from .mossum import *
from .crawl_standings import *
from .csession import *

import requests
import pandas as pd
import re
import os
import time
import codecs
import mosspy
import random
from tqdm import tqdm

CRAWLED = set()


def get_next_page(document):
    page_links = []
    iter_pagination = iter(document('div').filter('.pagination'))
    next(iter_pagination)
    links = document(next(iter_pagination))('a').filter('.arrow')
    for elem in links:
        if pq(elem).attr['href'] is not None:
            page_links.append(pq(elem).attr['href'])
    return page_links[-1]


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


def send_to_moss(contest_id, output_dir, problem_dir, problem, lang):
    moss = mosspy.Moss(USERID, lang)
    moss.setIgnoreLimit(100000000)
    working_dir = os.path.join(problem_dir, problem)
    rex = re.compile('.*\\.{}$'.format(lang))

    number_of_file = 0
    for filename in os.listdir(working_dir):
        if rex.match(filename):
            filepath = os.path.join(working_dir, filename)
            try:
                moss.addFile(filepath, '{}_{}_{}'.format(
                    contest_id, problem, filename))
                number_of_file += 1
            except:
                logger.error(
                    "File {} is empty, check it again".format(filepath))

            logger.info("{}_{}_{}".format(contest_id, problem, filename))

    if number_of_file < 2:
        return None, None

    print("Checking plagiarism on problem {} and language {}...".format(problem, lang))
    res_url = moss.send()
    print("Report Url: " + res_url)
    # create directory
    report_file = os.path.join(
        output_dir, "../plagiarism_report_{}/{}_{}.html".format(contest_id, problem, lang))
    create_dir(report_file)
    moss.saveWebPage(res_url, report_file)
    print("Saved report to {}".format(report_file))
    name = '{}_{}_{}'.format(contest_id, problem, lang)
    return name, res_url


def check_problem(contest_id, output_dir, problem_dir, problem):
    result = {}
    for lang in LANGUAGES:
        try:
            name, url = send_to_moss(
                contest_id, output_dir, problem_dir, problem, lang)
            if url is not None:
                result[name] = url
        except ConnectionError or ConnectionAbortedError:
            logger.error(
                'send_to_moss:get an error while requesting to MOSS, MOSS server maybe under maintenance, try later')

    return result


def check_plagiarism(session, contest_id, output_dir=WORKING_DIR, group_id=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT, is_cli=False):
    if not contest_id.isnumeric():
        contest_id = get_contest_id(contest_id)
    if is_cli:
        problem_dir = output_dir
    else:
        get_all_submission(session, contest_id, output_dir, group_id=group_id)
        problem_dir = os.path.join(output_dir, 'submission/{}'.format(contest_id))

    urls = {}

    for problem in os.listdir(problem_dir):
        urls.update(check_problem(
            contest_id, output_dir, problem_dir, problem))
    row_list = summarize(urls, os.path.join(
        output_dir, '../plagiarism_report_{}'.format(contest_id)), min_lines=min_lines, min_percent=min_percent)
    print('Checked plagiarism')
    return row_list


def compute_total_score(row, problem_list):
    total_score = 0
    for problem in problem_list:
        total_score += row[problem]
    return total_score


def crawl_checked_standings(session, contest_id, output_dir=WORKING_DIR, group_id=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT, is_cli=False):
    # contest_name = get_contest_name(session, contest_id)
    # df = crawl_standings(session, contest_id, output_dir, only_dir=True)
    df = get_standings_to_dataframe(contest_id)
    
    filepath = os.path.join(
        output_dir, '../plagiarism_stadings_report_{}/{}.csv'.format(contest_id, contest_id))
        # output_dir, 'report/{}/{}.csv'.format(contest_id, contest_id))
    create_dir(filepath)
    df.to_csv(filepath, index=True)

    row_list = check_plagiarism(session, contest_id, output_dir,
                                group_id=group_id, min_lines=min_lines, min_percent=min_percent, is_cli=is_cli)
    for row in tqdm(row_list):
        if not df.loc[(df['Who'] == row['username']), row['problem']].any():
            continue
        if df.loc[(df['Who'] == row['username']), row['problem']].values[0] == float(row['score']):
            df.loc[(df['Who'] == row['username']), row['problem']] = -1
        else:
            print(
                'An error occurred while updating score of {} on problem {} to'.format(row['username'], row['problem']))

    problem_list = []
    start = 0
    for index, column in enumerate(df.columns.values):
        if column == '=' or column == 'Penalty':
            start = index
    problem_list = list(df.columns.values[start + 1:])
    df['='] = df.apply(lambda row: compute_total_score(
        row, problem_list), axis=1)
    if 'Penalty' in df.columns.values:
        df = df.sort_values(by=['=', 'Penalty'], ascending=[False, True])
    else:
        df = df.sort_values(by=['='], ascending=[False])

    df = df.reset_index(drop=True)

    # filepath = os.path.join(
    #     output_dir, 'results/{}-checked.csv'.format(contest_id))
    # create_dir(filepath)
    # df.to_csv(filepath, index=True)
    # filepath = os.path.join(
    #     output_dir, 'report/{}/{}-checked.csv'.format(contest_id, contest_id))
    # create_dir(filepath)
    # df.to_csv(filepath, index=True)
    filepath = os.path.join(
        output_dir, '../plagiarism_stadings_report_{}/{}-checked.csv'.format(contest_id, contest_id))
    create_dir(filepath)
    df.to_csv(filepath, index=True)
    print('Done!!! results was stored at {}'.format(filepath))

    


if __name__ == "__main__":
    logger.info("Running check_plagiarism.py...")
    session = CSession()
    # session.login('74164707NgocBH','123456789')
    # get_all_submission(session, '255647', '../data')
    urls = check_plagiarism(session, '255647', '../data')
