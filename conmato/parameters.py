import os

WORKING_DIR = os.path.join(os.path.dirname(
    os.path.abspath(__file__)), '../data')

LOGGING_FILE = os.path.join(WORKING_DIR, 'logs/build.log')
SESSION_FILE = os.path.join(WORKING_DIR, 'session/session.pkl')

# USERID in moss.standford.edu, to register check https://theory.stanford.edu/~aiken/moss/
USERID = 203062946
# USERID in moss.standford.edu, to register check https://theory.stanford.edu/~aiken/moss/

# Only show matches (in check check plajiarism) with the number of the same line > MIN_LINES
MIN_LINES = 10

# Only show matches (in check check plajiarism) with score of similarity > MIN_PERCENT
MIN_PERCENT = 90

# A regular expression that is used to transform the name of them matched files.
TRANSFORMER = r'.*'

NEW_SCORE = -1  # assign new score to cheating submission

VIRTUALIZATION = True  # generate a picture?

USER_FORMAT = r'^[0-9]{8,10}[A-Za-z]{4,10}$'

TIMESLEEP = 1

DEFAULT_USERNAME = '21431252KbjfGM'
DEFAULT_PASSWORD = '4761032=<'
USER_KEY = '757e4de2c3d19ff5a823003bbfa108aaab96d834' # get key and sceret here http://codeforces.com/settings/api
USER_SECRET = '12872454ac44ec1bc0ada71a12bf186397ee7438'

CODEFORCES_URI = 'https://codeforces.com'

GROUP_ID = 'Ir5CI6f3FD'

LOGIN_URL = 'https://codeforces.com/enter?back=%2F'

GROUP_URL = 'http://codeforces.com/group/{}/contests'

DATA_URL = 'http://codeforces.com/group/{}/data'

STANDINGS_URL = 'http://codeforces.com/group/{}/contest/{}/standings'

STATUS_URL = 'http://codeforces.com/group/{}/contest/{}/status'

MEMBERS_URL = 'http://codeforces.com/group/{}/members'

LANGUAGES = (
    "c",
    "cc",
    "java",
    "ml",
    "pascal",
    "ada",
    "lisp",
    "scheme",
    "haskell",
    "fortran",
    "ascii",
    "vhdl",
    "verilog",
    "perl",
    "matlab",
    "python",
    "mips",
    "prolog",
    "spice",
    "vb",
    "csharp",
    "modula2",
    "a8086",
    "javascript",
    "plsql")
