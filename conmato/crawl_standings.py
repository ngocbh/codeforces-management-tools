from __future__ import absolute_import
from pyquery import PyQuery as pq

from conmato.utils import *
from conmato.parameters import *
# from conmato.check_plagiarism import *
from conmato.contest import get_contest_name

import requests
import pandas as pd
import re
import os
import time
import hashlib, random
import urllib, json


CODEFORCES_URI = 'https://codeforces.com'
CRAWLED = set()

session = requests.Session()


def get_standings(contest_id, usernames=None, user_format=None):
    # print('get_standings user_format = ', user_format)
    """
        usernames is list of usernames
        ex: usernames = ['abasf', 'adfjsdfkas']
    """
    if usernames != None:
        for i in range(len(usernames)):
            usernames[i] = usernames[i].lower()

    rint = random.randint(100000,999999)
    current_time = int(time.time())

    parameters = {}
    parameters['apiKey'] = USER_KEY
    parameters['contestId'] = contest_id
    # if not usernames or len(usernames) != 0:
    #   usernames_str = ''
    #   for i in range(len(usernames)):
    #       usernames_str +=  usernames[i]
    #       if i != len(usernames)-1:
    #           usernames_str += ';'
    #   parameters['handles'] = usernames_str
    parameters['showUnofficial'] = 'false'
    parameters['time'] = current_time
    urlparameters = ''
    for i, (key, value) in enumerate(parameters.items()):
        urlparameters += str(key) + '=' + str(value)
        if i != len(parameters) - 1:
            urlparameters += '&'

    sigstr = '{}/contest.standings?{}#{}'.format(rint, urlparameters, USER_SECRET)
    apiSig = hashlib.sha512(sigstr.encode('utf-8')).hexdigest()

    api = 'https://codeforces.com/api/contest.standings?{}&apiSig={}{}'.format(urlparameters,rint, apiSig)

    response = requests.get(api)
    resdict = json.loads(response.text)
    if resdict['status'] != 'OK':
        logger.warning('get_standings:{}'.format(resdict['comment']))
        return None

    standings = {}
    standings['contest'] = resdict['result']['contest']
    standings['problems'] = []
    for problem in resdict['result']['problems']:
        standings['problems'].append({'index': problem['index'], 'name': problem['name']})

    standings['penalty'] = 0
    standings['rows'] = []
    for row in resdict['result']['rows']:
        used_row = {}
        used_row['handles'] = ''
        for i in range(len(row['party']['members'])):
            used_row['handles'] += row['party']['members'][i]['handle']
            if i != len(row['party']['members']) - 1:
                used_row['handles'] += ','

        used_row['type'] = row['party']['participantType']
        used_row['rank'] = row['rank']
        used_row['points'] = row['points']
        used_row['penalty'] = row['penalty']
        standings['penalty'] += int(row['penalty'])
        used_row['bestSubmissionTimeSeconds'] = 0
        used_row['problemResults'] = row['problemResults']
        for pr in row['problemResults']:
            if 'bestSubmissionTimeSeconds' in pr:
                used_row['bestSubmissionTimeSeconds'] += pr['bestSubmissionTimeSeconds']
        if 'lastSubmissionTimeSeconds' in row:
            used_row['lastSubmissionTimeSeconds'] = row['lastSubmissionTimeSeconds']
        else:
            used_row['lastSubmissionTimeSeconds'] = 0

        if user_format and re.match(user_format, used_row['handles']):
            if usernames != None:
                if used_row['handles'].lower() in usernames:
                    standings['rows'].append(used_row)
            else:
                standings['rows'].append(used_row)
        else:
            standings['rows'].append(used_row)
    # print(json.dumps(standings, indent=2))
    return standings


def get_standings_to_dataframe(contest_id, usernames=None, penalty=True, get_name=False):
    standings = get_standings(contest_id, usernames)
    data = []
    column_names = ['#', 'Who', '=']
    if penalty:
        column_names.append('Penalty')
    prob_indexes = []
    for prob in standings['problems']:
        column_names.append(prob['index'])
        prob_indexes.append(prob['index'])

    for row in standings['rows']:
        data_row = {}
        data_row['#'] = row['rank']
        data_row['Who'] = row['handles']
        data_row['='] = row['points']
        if penalty == True:
            if standings['penalty'] == 0:
                data_row['Penalty'] = row['bestSubmissionTimeSeconds']
            else:
                data_row['Penalty'] = row['penalty']
        for i, prob in enumerate(row['problemResults']):
            data_row[prob_indexes[i]] = prob['points']
        data.append(data_row)

    df = pd.DataFrame(data, columns=column_names)
    df.name = standings['contest']['name']
    if penalty:
        df = df.sort_values(by=['=','Penalty'],ascending=[False,True])

    if get_name:
        return df, standings['contest']['name']
    else:
        return df

def get_standings_to_csv(contest_id, usernames=None, penalty=True, outdir=WORKING_DIR):
    df, contest_name = get_standings_to_dataframe(contest_id, usernames, penalty, get_name=True)
    filepath = os.path.join(outdir, 'results/{}.csv'.format(contest_name.replace(' ','-')))
    create_dir(filepath)
    df.to_csv(filepath, index=True)
    print('Done!! {}'.format(filepath))
    return df


def get_pages(doc):
    page_links = []
    for elem in doc('div').filter('.custom-links-pagination').children():
        if pq(doc(elem).find('a')).attr['href'] is not None:
            page_links.append(pq(doc(elem).find('a')).attr['href'])
    return page_links


def parse_column_names(doc):
    column_names = [doc(elem).text() for elem in doc('th')]
    return column_names


def calculate_penalty(times):
    if times == '?':
        return 0

    factor = [1, 60, 24]
    times_splitted = times.split(':')
    times_splitted.reverse()
    penalty = 0
    for index in range(len(times_splitted)):
        penalty += int(times_splitted[index]) * factor[index]

    return penalty


def parse_score(text):
    if text == '':
        return 0, 0
    elif text.isnumeric():
        try:
            score = int(text)
        except ValueError:
            score = float(text)
        return float(text), 0
    elif ' ' in text and text[0] != '*':
        splitted_text = text.split(' ')
        try:
            score = int(splitted_text[0])
        except ValueError:
            score = float(splitted_text[0])
        return float(splitted_text[0]), calculate_penalty(splitted_text[1])
    else:
        return text, 0


def regex_filter(val, regex):
    return True if val and re.search(regex, val) else False


def crawl_participant(session, url, data, column_names, penalty):
    response = session.get(url)
    doc = pq(response.text)
    table = doc('div').filter('.datatable')

    for row_e in table.find('tr'):
        if pq(table(row_e)).attr['participantid'] is not None:
            row = table(row_e)
            row_data = []
            sum_pen = 0
            for elem in row('td'):
                score, pen = parse_score(row(elem).text())
                sum_pen += pen
                row_data.append(score)
            if penalty:
                row_data.append(sum_pen)

            if len(row_data) != len(column_names):
                raise Exception(
                    'Different column_names size and row_data size')
            else:
                data.append(row_data)

    print('Crawled page: {}'.format(url))
    print('Time to sleep {}s'.format(TIMESLEEP))
    time.sleep(TIMESLEEP)
    CRAWLED.add(url)

    page_links = get_pages(doc)
    for link in page_links:
        url = '{}{}'.format(CODEFORCES_URI, link)
        if url not in CRAWLED:
            crawl_participant(session, url, data, column_names, penalty)

# crawl_checked a standings url
def crawl_standings(session, url, filepath, user_format=r'.*', penalty=True, only_dir=False, group_id=GROUP_ID):
    if url.isnumeric():
        url = get_standings_url(url)

    print('Crawling : {}'.format(url))
    error = False
    data = []
    column_names = []
    response = session.get(url)
    if url != response.url:
        error = True

    doc = pq(response.text)
    row = doc('div').filter('.datatable').find('tr')
    contest_id = get_contest_id(url)
    column_names = parse_column_names(doc(row[0]))
    if penalty:
        column_names.append('Penalty')

    crawl_participant(session, url, data, column_names, penalty)

    df = None
    df = pd.DataFrame(data, columns=column_names)

    if penalty:
        column_names.remove('Penalty')
        column_names.insert(3, 'Penalty')
        df = df[column_names]

    try:
        if error:
            raise Exception('')
        df.Who.unique()
        df = df.drop_duplicates()

        if penalty:
            df = df.sort_values(by=['=', 'Penalty'], ascending=[False, True])
        df = df[df.Who.apply(lambda x: True if re.search(
            user_format, x) else False)]
        if only_dir:
            filepath = os.path.join(
                filepath, 'results/{}.csv'.format(contest_id))
        create_dir(filepath)
        df.to_csv(filepath, index=False)
        print('Done!! {}'.format(filepath))
        return df
    except:
        nor = "I cannot recognize this site {}, please check those cases:\n\
			1. maybe it isn't the standings of codeforces.\n \
			2. you should make your contest public before.\n \
			3. login.\n \
			4. turn on manage permission for the account used to login".format(url)
        print(nor)
        if only_dir:
            filepath = os.path.join(filepath, 'results/{}.csv'.format(url))
        create_dir(filepath)
        with open(filepath, mode='w') as f:
            f.write(nor)
        return None


def crawl_standings_for_merge(ss, url, user_format=r'.*', penalty=True, group_id=GROUP_ID):
    if url.isnumeric():
        url = get_standings_url(url)

    print('Crawling : {}'.format(url))
    error = False
    data = []
    response = ss.get(url)
    if url != response.url:
        error = True

    doc = pq(response.text)
    row = doc('div').filter('.datatable').find('tr')
    contest_name = get_contest_name(ss, url, group_id)

    column_names = parse_column_names(doc(row[0]))
    if penalty:
        column_names.append('Penalty')

    crawl_participant(ss, url, data, column_names, penalty)

    df = None
    df = pd.DataFrame(data, columns=column_names)

    if penalty:
        column_names.remove('Penalty')
        column_names.insert(3, 'Penalty')
        df = df[column_names]

    try:
        if error:
            raise Exception('')
        df.Who.unique()
        df = df.drop_duplicates()

        if penalty:
            df = df.sort_values(by=['=', 'Penalty'], ascending=[False, True])
        df = df[df.Who.apply(lambda x: True if re.search(
            user_format, x) else False)]
        df = df[['Who', '=']]
        df = df.rename(columns={'Who': 'UserId'})
        df = df.rename(columns={'=': contest_name})
        return df
    except:
        nor = "I cannot recognize this site {}, please check those cases:\n\
			1. maybe it isn't the standings of codeforces.\n \
			2. you should make your contest public before.\n \
			3. login.\n \
			4. turn on manage permission for the account used to login".format(url)
        print(nor)
        return None

# crawl_checked list of standings urls
def qcrawl(session, urls, user_format, penalty, outdir=WORKING_DIR, group_id=GROUP_ID):
    for url in urls:
        crawl_standings(session, url, outdir, user_format,
                        penalty, only_dir=True, group_id=group_id)


def main():
    logger.info("Running crawl_standing.py...")


if __name__ == '__main__':
    main()
