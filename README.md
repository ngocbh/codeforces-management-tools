# codeforces-standings-crawler

### Requirements
```python3``` (or ```python```), ```pip```. To install requirements

```
pip install -r requirements.txt
```

### How to run

```
python3 crawl.py
```

Change parameters in crawl.py:

```
# List url of contests
URLS = [
'http://codeforces.com/group/Ir5CI6f3FD/contest/263142/standings',
'http://codeforces.com/group/Ir5CI6f3FD/contest/261501/standings',
]

# filter for each class . use r'.*' for all participants.
USER_FORMAT=r'.*' #get all participants
# USER_FORMAT=r'^44' #get participants like 44******* 

# Would you like to use the submission time to rank participants?
PENALTY=True

# username and password of an admin in codeforces group
# use your account and turn on manage permission for all contests that you want to crawl standings
USERNAME='74164707NgocBH'
PASSWORD='123456789'

# directory of output file
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
OUTDIR = os.path.join(WORKING_DIR, 'data')

# dont change it
csc.login(USERNAME,PASSWORD)
csc.qcrawl(URLS, USER_FORMAT, PENALTY, OUTDIR)

```