from __future__ import absolute_import
from pyquery import PyQuery as pq

import requests
import pandas as pd
import re, os
import time

CODEFORCES_URI='https://codeforces.com'
LOGIN_URL='https://codeforces.com/enter?back=%2F'
CRAWLED=set()
s = requests.Session()

def get_pages(doc):
	page_links = []
	for elem in doc('div').filter('.custom-links-pagination').children():
		if pq(doc(elem).find('a')).attr['href'] != None:
			page_links.append(pq(doc(elem).find('a')).attr['href'])
	return page_links

def parse_column_names(doc):
	column_names = []
	for elem in doc('th'):
		column_names.append(doc(elem).text())
	return column_names


def calc_pen(s):
	factor = [1,60,24]
	sa = s.split(':')
	sa.reverse()

	pen = 0;
	for i in range(len(sa)):
		pen += int(sa[i])*factor[i];

	return pen


def parse_score(text):
	if text == '':
		return 0, 0
	elif text.isnumeric():
		try:
			score = int(text)
		except:
			score = float(text)
		return float(text), 0
	elif ' ' in text:
		ts = text.split(' ');
		try:
			score = int(ts[0])
		except:
			score = float(ts[0])
		return float(ts[0]), calc_pen(ts[1])
	else:
		return text, 0

def regex_filter(val, regex):
	if val:
		mo = re.search(regex,val)
		if mo:
			return True
		else:
			return False
	else:
		return False

def crawl_participant(URL, data, column_names, penalty):
	response = s.get(URL)
	doc = pq(response.text)
	table = doc('div').filter('.datatable')

	for row_e in table.find('tr'):
		if pq(table(row_e)).attr['participantid'] != None:
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
				raise Exception('Different column_names size and row_data size')
			else:
				data.append(row_data)

	print('Crawled page: {}'.format(URL))
	print('Time to sleep 0.2s')
	time.sleep(0.2)
	CRAWLED.add(URL)

	page_links = get_pages(doc)
	for link in page_links:
		url = '{}{}'.format(CODEFORCES_URI, link)
		if url not in CRAWLED:
			crawl_participant(url, data, column_names, penalty)

def crawl_standings(URL, filepath, user_format=r'.*', penalty=True, only_dir=False):
	print('Crawling : {}'.format(URL))
	error = False
	data  = []
	column_names = []
	response = s.get(URL)
	if URL != response.url:
		error = True;

	doc = pq(response.text)
	row = doc('div').filter('.datatable').find('tr')
	contest_name = ''
	contest_name = doc('div').filter('.contest-name').find('a').text()
	contest_name = contest_name.replace(' ','-').replace('\n','')
	column_names = parse_column_names(doc(row[0]))
	if penalty:
		column_names.append('Penalty')

	crawl_participant(URL, data, column_names, penalty)

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

		df = df.sort_values(by=['=','Penalty'],ascending=[False,True])
		df = df[df.Who.apply(lambda x: True if re.search(user_format,x) else False)]
		if only_dir:
			filepath = os.path.join(filepath, contest_name + '.csv')
		df.to_csv(filepath, index=False)
		print('Done!! {}'.format(filepath))
	except:
		nor = "I cannot recognize this site {}, please check those cases:\n\
			1. maybe it isn't the standings of codeforces.\n \
			2. you should make your contest public before.\n \
			3. login.\n \
			4. turn on manage permission for the account used to login".format(URL)
		print(nor)
		if only_dir:
			filepath = os.path.join(filepath, URL + '.csv')
		with open(filepath, mode='w') as f:
			f.write(nor)
		return

	

def qcrawl(urls, user_format, penalty, outdir):
	for url in urls:
		crawl_standings(url, outdir, user_format, penalty, only_dir=True)


def login(usename, password):
	print('Login...')
	payload = {
		"handleOrEmail": usename,
		"password": password,
		"csrf_token": "",
		"bfaa": '1ef059a32710a29f84fbde5b5500d49c',
		"action": 'enter',
		"ftaa": 'uf8qxh8b5vphq6wna4',
		"_tta": 569
	}
	response = s.get(LOGIN_URL)
	doc = pq(response.text)
	payload['csrf_token'] = doc('input').attr('value')

	response2 = s.post(
		LOGIN_URL, 
		data = payload, 
		headers = dict(referer=LOGIN_URL)
	)

	print("Login successfully")

if __name__ == '__main__':
	# URL='https://codeforces.com/group/Ir5CI6f3FD/contest/251769/standings'
	# USER_FORMAT=r'*'
	# crawl_standings(URL,'../data/standings.csv')
	# login('74164707NgocBH','123456789')
	URL='https://codeforces.com/group/Ir5CI6f3FD/contest/255647/standings'

	USER_FORMAT=r'^44'
	# USER_FORMAT=r'.*' #get all participant

	# OUTPUT_FILE='../data/standings_midterm1_689544.csv'
	PENALTY=True

	crawl_standings(URL, OUTPUT_FILE, USER_FORMAT, PENALTY)
	# print(DATA)
