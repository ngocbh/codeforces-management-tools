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


