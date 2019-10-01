import csc

URL='https://codeforces.com/group/Ir5CI6f3FD/contest/251769/standings'

USER_FORMAT=r'.*'
# USER_FORMAT=r'.*' #get all participant

OUTPUT_FILE='data/standings.csv'

csc.crawl_standings(URL, OUTPUT_FILE, USER_FORMAT)