from __future__ import absolute_import
from pyquery import PyQuery as pq
from lxml import html

from .utils import *
from .parameters import *
from .mossum import *
from .crawl_standings import *

import requests
import pandas as pd
import re, os
import time, codecs
import mosspy
import random 

CRAWLED=set()

def get_next_page(doc):
	page_links = []
	iter_pagination = iter(doc('div').filter('.pagination'))
	next(iter_pagination)
	listlinks = doc(next(iter_pagination))('a').filter('.arrow')
	for elem in listlinks:
		if pq(elem).attr['href'] != None:
			page_links.append(pq(elem).attr['href'])
	return page_links[-1]

def get_code(ss, data):
	submission_url = '{}{}'.format(CODEFORCES_URI,data('a').attr['href'])
	# submission_url = 'https://codeforces.com/group/Ir5CI6f3FD/contest/255647/submission/62598185'
	response = ss.get(submission_url)
	tree2 = html.fromstring(response.text)
	doc = pq(response.text)
	try:
		pq(tree2.xpath('//*[@id="pageContent"]/div[3]/pre'))
		code = tree2.xpath('//*[@id="pageContent"]/div[3]/pre/text()')[0]
		return code
	except:
		raise Exception('Too many requests, Codeforces has rejected requests, please increase TIMESLEEP parameter in parameters.py file')

def get_username(data):
	return data.text()

def get_problem(data):
	try:
		return data.text().split(' ')[0]
	except:
		return 'unk'

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

def get_all_submission(ss, url, outdir,groupID=GROUP_ID):
	if url.isnumeric():
		contestID = url
		url = get_status_url(contestID,groupID=groupID)
	else:
		contestID = get_contest_id(url)
	print('Downloading submission from page {}...'.format(url))
	response = ss.get(url)
	if url != response.url:
		error = True;

	doc = pq(response.text)
	table = doc('div').filter('.datatable')
	# print(table)
	
	for row_e in table.find('tr'):
		if pq(table(row_e)).attr['data-submission-id'] != None:
			# print(table(row_e))
			# crawl submission data
			data = {'code': '', 'username': '', 'lang': '', 'score': '', 'problem': ''}
			iter_cell = iter(table(row_e)('td'))
			cell = next(iter_cell)
			code_cell = table(cell)
			next(iter_cell)
			cell = next(iter_cell)
			data['username'] = get_username(table(cell))
			cell = next(iter_cell)
			data['problem'] = get_problem(table(cell))
			cell = next(iter_cell)
			data['lang'] = get_language(table(cell))
			cell = next(iter_cell)
			data['score'] = get_score(table(cell))
			filename = 'submission/{}/{}/{}_{}.{}'.format(contestID,data['problem'],data['username'],data['score'],data['lang'])
			filepath = os.path.join(outdir, filename)

			# create directory
			create_dir(filepath)

			# check if the submission has the highest score
			isBest = True
			wdir = os.path.dirname(filepath)
			for file in os.listdir(wdir):
				rer = re.compile('.*{}_(?P<score>\\d+).{}'.format(data['username'], data['lang']))
				rer = rer.match(file)
				if rer:
					score = rer.group('score')
					if int(score) < int(data['score']):
						os.remove(os.path.join(wdir,file))
					else:
						isBest = False

			# dump new file		
			if isBest:
				with codecs.open(filepath, encoding='utf8', mode='w') as f:
					data['code'] = get_code(ss, code_cell)
					f.write(data['code'])
					se = random.uniform(float(TIMESLEEP)/2, TIMESLEEP)
					time.sleep(se)
			# break

	print('Downloaed submissions in {}'.format(url))
	se = random.uniform(float(TIMESLEEP)/2, TIMESLEEP)
	print('Let me sleep {}s to prevent Codeforces rejecting requests...'.format(TIMESLEEP))
	time.sleep(se)
	# return
	# next page
	CRAWLED.add(url)
	next_page = get_next_page(doc)
	url = '{}{}'.format(CODEFORCES_URI, next_page)
	if url not in CRAWLED:
		get_all_submission(ss, url, outdir, groupID)

def send2moss(contestID, outdir, problem_dir, problem, lang):
	moss = mosspy.Moss(USERID, lang)
	moss.setIgnoreLimit(100000000)
	wdir = os.path.join(problem_dir, problem)
	rex = re.compile('.*\\.{}$'.format(lang))

	number_of_file = 0
	for filename in os.listdir(wdir):
		if rex.match(filename):
			filepath = os.path.join(wdir, filename)
			try:
				moss.addFile(filepath, '{}_{}_{}'.format(contestID, problem, filename))
				number_of_file += 1
			except:
				print('File {} is empty, check it again'.format(filepath))
			
			print('{}_{}_{}'.format(contestID, problem, filename))

	if number_of_file < 2:
		return None, None
	print("Checking plagiarism on problem {} and language {}...".format(problem, lang))
	res_url = moss.send()
	print ("Report Url: " + res_url)
	# create directory
	report_file = os.path.join(outdir,"report/{}/{}_{}.html".format(contestID,problem,lang))
	create_dir(report_file)
	moss.saveWebPage(res_url, report_file)
	print("Saved report to {}".format(report_file))
	name = '{}_{}_{}'.format(contestID, problem, lang)
	return name, res_url

def check_problem(contestID, outdir, problem_dir, problem):
	ret = {}
	wdir = os.path.join(problem_dir, problem)
	for lang in LANGUAGES:
		try: 
			name, url = send2moss(contestID, outdir, problem_dir, problem, lang)
			if url != None:
				ret[name] = url
		except:
			logger.error('send2moss:get an error while requesting to MOSS, MOSS server maybe under maintenance, try later')

	return ret

def check_plagiarism(ss, contestID, outdir=WORKING_DIR, groupID=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT):
	if not contestID.isnumeric():
		contestID = get_contest_id(contestID)

	
	get_all_submission(ss, contestID, outdir, groupID=groupID)

	urls = {}

	problem_dir = os.path.join(outdir, 'submission/{}'.format(contestID))
	for problem in os.listdir(problem_dir):
		urls.update(check_problem(contestID, outdir, problem_dir, problem))

	row_list = summarize(urls, os.path.join(outdir, 'report/{}'.format(contestID)), min_lines=min_lines, min_percent=min_percent)
	print('Checked plagiarism')
	return row_list

def compute_total_score(row, problem_list):
	ret = 0
	for problem in problem_list:
		ret += row[problem]
	return ret

def crawl_checked_standings(ss, contestID, outdir=WORKING_DIR, groupID=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT):
	df, contest_name = get_standings_to_csv(contestID, outdir=outdir)

	filepath = os.path.join(outdir, 'report/{}/{}.csv'.format(contestID,contestID))
	create_dir(filepath)
	df.to_csv(filepath, index=True)

	row_list = check_plagiarism(ss, contestID, outdir, groupID=groupID, min_lines=min_lines, min_percent=min_percent)
	for row in row_list:
		if not df.loc[(df['Who'] == row['username']), row['problem']].any():
			continue
		if df.loc[(df['Who'] == row['username']), row['problem']].values[0] == float(row['score']):
			df.loc[(df['Who'] == row['username']), row['problem']] = -1
		else: 
			print('An error occurred while updating score of {} on problem {} to'.format(row['username'], row['problem']))

	problem_list = []
	start = 0
	for i, column in enumerate(df.columns.values):
		if column == '=' or column == 'Penalty':
			start = i
	problem_list = list(df.columns.values[start+1:])
	df['='] = df.apply(lambda row: compute_total_score(row, problem_list), axis=1)
	if 'Penalty' in df.columns.values:
		df = df.sort_values(by=['=','Penalty'],ascending=[False,True])
	else:
		df = df.sort_values(by=['='],ascending=[False])

	df = df.reset_index(drop=True)

	filepath = os.path.join(outdir, 'results/{}-checked.csv'.format(contestID))
	create_dir(filepath)
	df.to_csv(filepath, index=True)
	filepath = os.path.join(outdir, 'report/{}/{}-checked.csv'.format(contestID,contestID))
	create_dir(filepath)
	df.to_csv(filepath, index=True)
	print('Done!!! results was stored at {}'.format(filepath))
	


if __name__ == "__main__":
	ss = CSession()
	# ss.login('74164707NgocBH','123456789')
	# get_all_submission(ss, '255647', '../data')
	urls = check_plagiarism(ss, '255647', '../data')
	

