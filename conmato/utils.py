from __future__ import absolute_import
from pyquery import PyQuery as pq
from .parameters import *

import requests
import pandas as pd
import re, os
import datetime


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


def create_dir(filepath):
	wdir = os.path.dirname(filepath)
	if not os.path.exists(wdir):
		try:
			os.makedirs(wdir)
		except OSError as exc: # Guard against race condition
			if exc.errno != errno.EEXIST:
				raise
				
class CSession(requests.Session):
	def login(self, username, password):
		print('Login...')
		if username == '********' or password == '********':
			raise Exception('Please provide username and password before using.')
			
		payload = {
			"handleOrEmail": username,
			"password": password,
			"csrf_token": "",
			"bfaa": '1ef059a32710a29f84fbde5b5500d49c',
			"action": 'enter',
			"ftaa": 'uf8qxh8b5vphq6wna4',
			"_tta": 569
		}
		response = self.get(LOGIN_URL)
		doc = pq(response.text)
		payload['csrf_token'] = doc('input').attr('value')

		response2 = self.post(
			LOGIN_URL, 
			data = payload, 
			headers = dict(referer=LOGIN_URL)
		)

		print("Login successfully")