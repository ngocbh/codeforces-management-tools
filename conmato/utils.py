from __future__ import absolute_import
from pyquery import PyQuery as pq
from .parameters import *

import requests
import pandas as pd
import re, os
import datetime
import logging

# logging.basicConfig(filename=LOGGING_FILE,level=logging.level)
from logging.handlers import RotatingFileHandler

logging.basicConfig(handlers=[RotatingFileHandler(filename=LOGGING_FILE,
                     mode='w', maxBytes=512000, backupCount=4)], level=logging.INFO,
                     format='%(levelname)s %(asctime)s %(message)s', 
                    datefmt='%m/%d/%Y%I:%M:%S %p')

logger = logging.getLogger('my_logger')

def date_str():
    return datetime.datetime.today().strftime('%d-%m-%Y_%H%M%S')

def get_standings_url(contestID):
	return STANDINGS_URL.format(contestID)

def get_status_url(contestID):
	return STATUS_URL.format(contestID)

def get_contest_id(url):
	contestid = ''

	if url.isnumeric():
		return url

	x = re.match(r'.*contest/(?P<contestid>\d+)/standings.*', url)
	if x != None:
		contestid = x.group('contestid')

	x = re.match(r'.*contest/(?P<contestid>\d+)/status.*', url)
	if x != None:
		contestid = x.group('contestid')

	x = re.match(r'.*contest/(?P<contestid>\d+)/.*', url)
	if x != None:
		contestid = x.group('contestid')

	x = re.match(r'.*contest/(?P<contestid>\d+)', url)
	if x != None:
		contestid = x.group('contestid')

	if contestid.isnumeric():
		return contestid
	else:
		raise Exception('An error occur when getting contest id')

def decode(s):
	ret = ''
	for e in s:
		ret += chr(ord(e)^5)
	return ret

def create_dir(filepath):
	wdir = os.path.dirname(filepath)
	if not os.path.exists(wdir):
		try:
			os.makedirs(wdir)
		except OSError as exc: # Guard against race condition
			if exc.errno != errno.EEXIST:
				raise

def clear_logging_file():
	open(LOGGING_FILE, 'w').close()
