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
				
class CSession(requests.Session):
	def login(self, username='', password=''):
		'''
			usage: 	You should only log in once for a session
					ss = CSession.Session()
					ss.login(username, password)
			return: 
				"Please provide username and password before using."
				'Login failed, wrong username or password'
				'Login failed while logging in by defalut user'
				"Login successfully"
		'''
		if username == '' or password == '':
			return "Please provide username and password before using."

		response = self.get(MEMBERS_URL)
		doc = pq(response.text)
		members = {}
		for e in doc('table').eq(1).children():
			username_tmp = pq(e)('td').eq(0).text()
			mtype_tmp = pq(e)('td').eq(1).text()
			members[username_tmp] = mtype_tmp

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

		response = self.post(
			LOGIN_URL, 
			data = payload, 
			headers = dict(referer=LOGIN_URL)
		)

		doc = pq(response.text)
		username_again = doc('div').filter('.lang-chooser').children().eq(1).children().eq(0).text()
		if username_again == 'Enter' or username != username_again:
			return 'Login failed, wrong username or password'

		self.cookies.clear()

		response = self.get(LOGIN_URL)
		doc = pq(response.text)
		payload['csrf_token'] = doc('input').attr('value')
		payload['handleOrEmail'] = decode(DEFAULT_USERNAME)
		payload['password'] = decode(DEFAULT_PASSWORD)

		response = self.post(
			LOGIN_URL, 
			data = payload, 
			headers = dict(referer=LOGIN_URL)
		)

		doc = pq(response.text)
		username_again = doc('div').filter('.lang-chooser').children().eq(1).children().eq(0).text()
		if username_again == 'Enter' or username_again != decode(DEFAULT_USERNAME):
			return 'Login failed while logging in by defalut user'

		return "Login successfully"