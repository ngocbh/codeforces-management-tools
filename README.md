# codeforces-management-tools
* Crawl Codeforces's standings.
* Check plagiarism.
* Create new standings that have plagiarism test.

Check document in vietnamese [here](https://github.com/ngocjr7/codeforces-management-tools/blob/master/README-vi.md)
### Requirements
```python3``` (or ```python```), ```pip```. To install requirements

```shell
pip install -r requirements.txt
```

### APIs
```python
ss = conmato.CSession() # create codeforces session, inherited request.Session()
ss.login(username='',password='') # login to codeforces and save cookie to ss
ss.get_logged_username() # get current username logging in codeforces
ss.get() # get and log
ss.post() # post

conmato.member.is_manager(groupID=GROUP_ID, username='', password='')
conmato.member.get_all_members(ss, groupID=GROUP_ID)
conmato.member.get_pending_participants(ss, groupID=GROUP_ID)
conmato.member.confirm_all_participants(ss, action, user_format=USER_FORMAT, groupID=GROUP_ID)
conmato.member.remove_all_participants(ss, user_format='.*', groupID=GROUP_ID)

conmato.contest.get_managed_contests(ss, groupID=GROUP_ID) # get all contests and toggle manager mode for all contests
conmato.contest.toggle_manager_mode(ss, contestid, groupID=GROUP_ID)
conmato.contest.get_contests(ss, groupID=GROUP_ID)
conmato.contest.get_contest_name(ss, contestID, groupID=GROUP_ID)

# get standings used codeforces api
conmato.get_standings(contestID, usernames=None) # usernames is list of user example usernames=['43152676NgocDM','45164787LanPD']

conmato.get_standings_to_dataframe(contestID, usernames=None, penalty=True, get_name=False) # if get_name = True -> return dataframe, contestname else return dataframe

conmato.get_standings_to_csv(contestID, usernames=None, penalty=True, outdir=WORKING_DIR) # create file csv in outdir, return dataframe, contestname 

# check plagiarism
conmato.check_plagiarism(ss, contestID, outdir=WORKING_DIR, groupID=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT)
conmato.crawl_checked_standings(ss, contestID, outdir=WORKING_DIR, groupID=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT)


# Outdate apis
conmato.crawl_standings_for_merge(ss, URL, user_format=r'.*', penalty=True,groupID=GROUP_ID) # see How to crawl standings for an existing student list
conmato.crawl_standings(ss, URL, filepath, user_format=r'.*', penalty=True, only_dir=False, groupID=GROUP_ID) # crawl standing for url
conmato.qcrawl(ss, urls, user_format, penalty, outdir=WORKING_DIR, groupID=GROUP_ID) # crawl list standings in urls
```

### How to crawl standings

```shell
python3 crawl_original_standings.py
```
The results will be stored in ```data/results```
Change parameters in crawl_original_standings.py:

```python
# List url of contests
URLS = [
'263142',
'261501'
]

# filter for each class . use r'.*' for all participants.
USER_FORMAT=r'.*' #get all participants
# USER_FORMAT=r'^44' #get participants like 44******* 

# Would you like to use the submission time to rank participants?
PENALTY=True

# username and password of an admin in codeforces group
# use your account and turn on manage permission for all contests that you want to crawl standings
USERNAME='********'
PASSWORD='********'

# directory of output file
WORKING_DIR = os.path.dirname(os.path.abspath(__file__))
OUTDIR = os.path.join(WORKING_DIR, 'data')

# dont change it
csc.login(USERNAME,PASSWORD)
csc.qcrawl(URLS, USER_FORMAT, PENALTY, OUTDIR)

```

### How to crawl standings for an existing student list
Config your crawl_standings_for_merge.py, change USERNAME and PASSWORD to your Codeforces account
```shell
python3 crawl_standings_for_merge.py your_student_list.xlsx standing_url
```
* your_student_list.xlsx must have a 'UserId' column which contains the information of student Codeforces accounts
* standing_url is a ranking URL of a Codeforces contest

The total score result will be stored in the last column of ```your_student_list.xlsx```




### How to check plagiarism

```shell
python3 check_plagiarism.py
```
The results will be stored in ```data/report/contestID```
Change parameters in check_plagiarism.py:

```python
import conmato

contestID = '257806' # the contestID which you need to check

ss = conmato.CSession()

# username and password of an admin in codeforces group
# use your account and turn on manage permission for all contests that you want to crawl standings
ss.login('********','********')

conmato.check_plagiarism(ss, contestID)
# conmato.crawl_checked_standings(ss, contestID)
```


### How to create new standings.

```shell
python3 crawl_checked_standings.py.py
```
The results will be stored in ```data/report/contestID```
Change parameters in crawl_checked_standings.py:

```python
import conmato

contestID = '257806' # the contestID which you need to check

ss = conmato.CSession()

# username and password of an admin in codeforces group
# use your account and turn on manage permission for all contests that you want to crawl standings
ss.login('********','********')

# conmato.check_plagiarism(ss, contestID)
conmato.crawl_checked_standings(ss, contestID)
```


