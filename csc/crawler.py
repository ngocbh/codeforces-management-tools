from __future__ import absolute_import
from pyquery import PyQuery as pq

import requests
import pandas as pd
import re
import time

CODEFORCES_URI='https://codeforces.com'

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
		return int(text), 0
	elif ' ' in text:
		ts = text.split(' ');
		return int(ts[0]), calc_pen(ts[1])
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
	print('Time to sleep 0.5s')
	time.sleep(0.5)
	CRAWLED.add(URL)

	page_links = get_pages(doc)
	for link in page_links:
		url = '{}{}'.format(CODEFORCES_URI, link)
		if url not in CRAWLED:
			crawl_participant(url, data, column_names, penalty)

def crawl_standings(URL, filepath, user_format=r'.*', penalty=True):
	print('Crawling : {}'.format(URL))
	data  = []
	column_names = []
	response = s.get(URL)
	doc = pq(response.text)
	row = doc('div').filter('.datatable').find('tr')
	column_names = parse_column_names(doc(row[0]))
	if penalty:
		column_names.append('Penalty')

	crawl_participant(URL, data, column_names, penalty)

	df = pd.DataFrame(data, columns=column_names)

	if penalty:
		column_names.remove('Penalty')
		column_names.insert(3, 'Penalty')
		df = df[column_names]

	df.Who.unique()
	df = df.drop_duplicates()

	df = df.sort_values(by=['=','Penalty'],ascending=[False,True])
	df = df[df.Who.apply(lambda x: True if re.search(user_format,x) else False)]
	

	df.to_csv(filepath, index=False)
	print('Done!! {}'.format(filepath))



if __name__ == '__main__':
	URL='https://codeforces.com/group/Ir5CI6f3FD/contest/251769/standings'
	USER_FORMAT=r'*'
	crawl_standings(URL,'../data/standings.csv')

	# print(DATA)
