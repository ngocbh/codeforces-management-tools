from __future__ import absolute_import
from pyquery import PyQuery as pq

from conmato.utils import *
from conmato.parameters import *
from conmato.mossum import *
from conmato.crawl_standings import *
from conmato.csession import *
from conmato.contest import get_all_submission

import requests
import pandas as pd
import re
import os
import time
import mosspy
from tqdm import tqdm


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
        output_dir, "plagiarism_report_{}/{}_{}.html".format(contest_id, problem, lang))
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


def check_plagiarism(session, contest_id, input_dir=WORKING_DIR, group_id=GROUP_ID, min_lines=MIN_LINES, 
    min_percent=MIN_PERCENT, is_cli=False, output_dir=WORKING_DIR):
    if not contest_id.isnumeric():
        contest_id = get_contest_id(contest_id)
    if is_cli:
        problem_dir = input_dir
    else:
        get_all_submission(session, contest_id, input_dir, group_id=group_id)
        problem_dir = os.path.join(input_dir, 'submission/{}'.format(contest_id))

    urls = {}

    for problem in os.listdir(problem_dir):
        urls.update(check_problem(
            contest_id, output_dir, problem_dir, problem))
    row_list = summarize(urls, os.path.join(
        output_dir, 'plagiarism_report_{}'.format(contest_id)), min_lines=min_lines, min_percent=min_percent)
    print('Checked plagiarism')
    return row_list


def compute_total_score(row, problem_list):
    total_score = 0
    for problem in problem_list:
        total_score += row[problem]
    return total_score


def crawl_checked_standings(session, contest_id, input_dir=WORKING_DIR, group_id=GROUP_ID, 
    min_lines=MIN_LINES, min_percent=MIN_PERCENT, is_cli=False, output_dir=WORKING_DIR):
    # contest_name = get_contest_name(session, contest_id)
    # df = crawl_standings(session, contest_id, output_dir, only_dir=True)
    df = get_standings_to_dataframe(contest_id)
    
    filepath = os.path.join(
        output_dir, 'plagiarism_stadings_report_{}/{}.csv'.format(contest_id, contest_id))
        # output_dir, 'report/{}/{}.csv'.format(contest_id, contest_id))
    create_dir(filepath)
    df.to_csv(filepath, index=True)

    row_list = check_plagiarism(session, contest_id, input_dir,
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
        output_dir, 'plagiarism_stadings_report_{}/{}-checked.csv'.format(contest_id, contest_id))
    create_dir(filepath)
    df.to_csv(filepath, index=True)
    print('Done!!! results was stored at {}'.format(filepath))

    


if __name__ == "__main__":
    logger.info("Running check_plagiarism.py...")
    session = CSession()
    # session.login('74164707NgocBH','123456789')
    # get_all_submission(session, '255647', '../data')
    urls = check_plagiarism(session, '255647', '../data')
