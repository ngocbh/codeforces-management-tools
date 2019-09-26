import csc

URL='https://codeforces.com/group/Ir5CI6f3FD/contest/251769/standings'

USER_FORMAT=r'^44'
# USER_FORMAT=r'.*' #get all participant

csc.crawl_standings(URL,'data/standings.csv', USER_FORMAT)