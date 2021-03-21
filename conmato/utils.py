from __future__ import absolute_import
from pyquery import PyQuery as pq
from conmato.parameters import *
# from conmato.csession import CSession

import requests
import pandas as pd
import re
import os
import datetime
import logging
import pickle
import sys
from getpass import getpass

# logging.basicConfig(filename=LOGGING_FILE,level=logging.level)
from logging.handlers import RotatingFileHandler
import errno

def create_dir(filepath):
    wdir = os.path.dirname(filepath)
    if not os.path.exists(wdir):
        try:
            os.makedirs(wdir)
        except OSError as exc: # Guard against race condition
            if exc.errno != errno.EEXIST:
                raise Exception("something happends while creating folder")

create_dir(LOGGING_FILE)
create_dir(DATA_DIR)

logging.basicConfig(
    handlers=[
        RotatingFileHandler(
            filename=LOGGING_FILE,
            mode='w',
            maxBytes=512000,
            backupCount=4
        )
    ],
    level=logging.INFO,
    format='%(levelname)s %(asctime)s %(message)s',
    datefmt='%m/%d/%Y %I:%M:%S %p'
)

logger = logging.getLogger('my_logger')

def date_str():
    return datetime.datetime.today().strftime('%d-%m-%Y_%H%M%S')


def get_standings_url(contest_id, group_id=GROUP_ID):
    return STANDINGS_URL.format(group_id, contest_id)


def get_status_url(contest_id, group_id=GROUP_ID):
    return STATUS_URL.format(group_id, contest_id)


def get_contest_id(url):
    contest_id = ''

    if url.isnumeric():
        return url

    x = re.match(r'.*contest/(?P<contest_id>\d+)/standings.*', url)
    if x is not None:
        contest_id = x.group('contest_id')

    x = re.match(r'.*contest/(?P<contest_id>\d+)/status.*', url)
    if x is not None:
        contest_id = x.group('contest_id')

    x = re.match(r'.*contest/(?P<contest_id>\d+)/.*', url)
    if x is not None:
        contest_id = x.group('contest_id')

    x = re.match(r'.*contest/(?P<contest_id>\d+)', url)
    if x is not None:
        contest_id = x.group('contest_id')

    if contest_id.isnumeric():
        return contest_id
    else:
        raise Exception('An error occur when getting contest id')

def decode(encode_data):
    decoded = ''
    for char in encode_data:
        decoded += chr(ord(char) ^ 5)
    return decoded

def clear_logging_file():
    open(LOGGING_FILE, 'w').close()

def to_df(list_of_dict):
    return pd.DataFrame(list_of_dict)

def standing_to_df(standings):
    prob_names = [p['index']+'('+p['name']+')' for p in standings['problems']]
    standing_list = []
    for row in standings['rows']:
        a_standing = {'Who':row['handles']}
        for i, prob in enumerate(row['problemResults']):
            a_standing[prob_names[i]] = prob['points']
        standing_list.append(a_standing)
    standing_df = pd.DataFrame(standing_list)
    return standing_df
