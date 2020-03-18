import conmato
import os
import pandas as pd
import sys                


# List of urls of contests
print(sys.argv)
if (len(sys.argv) != 3):
	print("please insert only 2 arguments")
	exit(0);
EXCEL_LINK = sys.argv[1]
URL = sys.argv[2]

# filter for each class . use r'.*' for all participants.
USER_FORMAT=r'.*' #get all participants
# USER_FORMAT=r'^44' #get participants like 44******* 

# Would you like to use the submission time to rank participants?
PENALTY=True

# username and password of an admin in codeforces group
# use your account and turn on manage permission for all contests that you want to crawl standings
USERNAME=''
PASSWORD=''

# directory of output file
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
OUTDIR = os.path.join(WORKING_DIR, 'data/results')

# dont change it
ss = conmato.CSession()
ss.login(USERNAME,PASSWORD)


df = conmato.crawl_standings_for_merge(ss, URL, USER_FORMAT, PENALTY)
print(df)

student_list = pd.read_excel(EXCEL_LINK)
student_list['UserId'] = student_list['UserId'].str.replace(' ', '')
student_list['UserId'] = student_list['UserId'].str.replace('\n', '')

df = pd.merge(student_list, df, how='left', on='UserId')
df.to_excel(EXCEL_LINK, index=False, header=True)
