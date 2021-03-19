from __future__ import absolute_import
from pyquery import PyQuery as pq

from .utils import *
from .parameters import *
from .csession import *
# from .check_plagiarism import *

import requests
import pandas as pd
import re
import os
import time


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
