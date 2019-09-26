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

Parameters:

```
#link to contest standings
URL='https://codeforces.com/group/Ir5CI6f3FD/contest/251769/standings' 

# filter for each class . r'.*' for all participant.
USER_FORMAT=r'^44' 

#output file
OUTPUT_FILE='data/standings.csv'

```