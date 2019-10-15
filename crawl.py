import csc

URL='https://codeforces.com/group/Ir5CI6f3FD/contest/255647/standings'

USER_FORMAT=r'^44'
# USER_FORMAT=r'.*' #get all participant

OUTPUT_FILE='data/standings_midterm1_689544.csv'
PENALTY=True

csc.crawl_standings(URL, OUTPUT_FILE, USER_FORMAT, PENALTY)