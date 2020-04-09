from __future__ import absolute_import
from pyquery import PyQuery as pq

from .utils import *
from .parameters import *
from .check_plagiarism import *

import requests
import pandas as pd
import re, os
import time


def get_contest_name(ss, contestID, groupID=GROUP_ID):
	if not contestID.isnumeric():
		contestID = get_contest_id(contestID)
	url = get_standings_url(contestID, groupID)
	response = ss.get(url)
	doc = pq(response.text)
	contest_name = doc('div').filter('.contest-name').find('a').text()
	contest_name = contest_name.replace(' ','-').replace('\n','')
	return contest_name



def get_contests(ss, groupID=GROUP_ID):
	'''
		usage:	ss = conmato.CSession()
				conmato.get_contests(ss)
		return:
				a dictionary of contestid as key and contestname as value
				example:
				{'269187': 'Training 2 - EXHSEARCH - 20192'}
	'''
	url = GROUP_URL.format(groupID)
	response = ss.get(url)
	doc = pq(response.text)
	table = doc('table').not_('.rtable').not_('.table-form')
	ret = {}
	for tr in pq(table.children()[1:])('tr'):
		contestid = pq(tr).attr('data-contestid')
		if contestid == None:
			continue
		contestname = pq(tr).children().eq(0).remove('a').text()
		ret[contestid] = contestname
	return ret

def toggle_manager_mode(ss, contestid, groupID=GROUP_ID):
	url = GROUP_URL.format(groupID)
	response = ss.get(url)
	doc = pq(response.text)
	csrf_token = doc('span').attr['data-csrf']
	payload = {
		"csrf_token": csrf_token,
		"contestId": contestid,
		"newValue": 'true',
		"action": 'toggleMashupContestManagerMode',
	}
	
	response = ss.post(
		'{}/{}'.format(DATA_URL.format(groupID),'mashup'), 
		data = payload
	)
	if response.status_code == 200:
		return True
	else:
		logger.error('toggle_manager_mode: an error while toggling manager mode')
		return False


def get_managed_contests(ss, groupID=GROUP_ID):
	'''
		get contests and toggle manager mode for all contest
		usage:	ss = conmato.CSession()
				conmato.get_managed_contests(ss)
		return:
				a dictionary of contestid as key and contestname as value
				example:
				{'269187': 'Training 2 - EXHSEARCH - 20192'}
	'''
	url = GROUP_URL.format(groupID)
	response = ss.get(url)
	doc = pq(response.text)
	table = doc('table').not_('.rtable').not_('.table-form')
	ret = {}
	for tr in pq(table.children()[1:])('tr'):
		contestid = pq(tr).attr('data-contestid')
		if contestid == None:
			continue
		contestname = pq(tr).children().eq(0).remove('a').text()
		ret[contestid] = contestname
		toggle_manager_mode(ss, contestid, groupID)
	return ret