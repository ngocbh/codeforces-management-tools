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

conmato.member.is_manager(group_id=GROUP_ID, username='', password='')
conmato.member.get_all_members(session, group_id=GROUP_ID)
conmato.member.get_pending_participants(session, group_id=GROUP_ID)
conmato.member.confirm_joining(session, member, action, group_id=GROUP_ID)
conmato.member.confirm_all_participants(session, action, user_format=USER_FORMAT, group_id=GROUP_ID)
remove_participants(session, member, group_id=GROUP_ID)
conmato.member.remove_all_participants(session, user_format='.*', group_id=GROUP_ID)

conmato.contest.get_managed_contests(session, group_id=GROUP_ID) # get all contests and toggle manager mode for all contests
conmato.contest.toggle_manager_mode(session, contest_id, group_id=GROUP_ID)
conmato.contest.get_contests(session, group_id=GROUP_ID)
conmato.contest.get_contest_name(session, contest_id, group_id=GROUP_ID)

# get standings used codeforces api
conmato.get_standings(contest_id, usernames=None) # usernames is list of user example usernames=['43152676NgocDM','45164787LanPD']

conmato.get_standings_to_dataframe(contest_id, usernames=None, penalty=True, get_name=False) # if get_name = True -> return dataframe, contestname else return dataframe

conmato.get_standings_to_csv(contest_id, usernames=None, penalty=True, outdir=WORKING_DIR) # create file csv in outdir, return dataframe, contestname 

# check plagiarism
conmato.check_plagiarism(session, contest_id, output_dir=WORKING_DIR, group_id=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT)
conmato.crawl_checked_standings(session, contest_id, output_dir=WORKING_DIR, group_id=GROUP_ID, min_lines=MIN_LINES, min_percent=MIN_PERCENT)


# Deprecated apis
conmato.crawl_standings_for_merge(ss, url, user_format=r'.*', penalty=True, group_id=GROUP_ID) # see How to crawl standings for an existing student list
conmato.crawl_standings(session, url, filepath, user_format=r'.*', penalty=True, only_dir=False, group_id=GROUP_ID) # crawl standing for url
conmato.qcrawl(session, urls, user_format, penalty, outdir=WORKING_DIR, group_id=GROUP_ID) # crawl list standings in urls
```

### How to crawl standings

```shell
python3 crawl_original_standings.py
```
The results will be stored in ```data/results```
Change parameters in crawl_original_standings.py:

```python
import conmato
import os


# Would you like to use the submission time to rank participants?
PENALTY=True


# A list of user usernames = ['abc', 'def']
USERNAMES=None # None to get all participants

contest_id = '256575'

conmato.get_standings_to_csv(contest_id, usernames=USERNAMES, penalty=PENALTY)

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


