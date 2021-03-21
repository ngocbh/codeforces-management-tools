from __future__ import absolute_import

import requests

from conmato.utils import *



class CSession(requests.Session):
    """
        is_manager: check if use is manger of codeforces group
        get_csrf_token: get csrf_token

    """
    csrf_token = None

    def get_csrf_token(self):
        return self.csrf_token

    def get(self, URL):
        response = super().get(URL)
        if response.url == 'http://codeforces.com/' or response.url == 'https://codeforces.com/':
            logger.error("""get: Codeforces rejected request,\nIt could be due to too many requests or you don't have 
            permission to request.\nYou should be slower or check your permission again""")
        return response

    def get_logged_username(self):
        """
                Return username if it's logged, otherwise, return None
        """
        response = self.get(CODEFORCES_URI)
        doc = pq(response.text)
        username = doc('div').filter(
            '.lang-chooser').children().eq(1).children().eq(0).text()
        if username == 'Enter':
            return None
        else:
            return username

    def login(self, username, password):
        """
            usage: 	You should only log in once for a session
                                session = CSession.Session()
                                session.login(username, password)
            return (one of these cases):
                    "Please provide username and password before using."
                    "Login failed, wrong username or password"
                    "Login failed while logger in by default user"
                    "Login successfully"
        """

        if username is None or password is None:
            return "Please provide username and password before using."

        payload = {
            "handleOrEmail": username,
            "password": password,
            "csrf_token": "",
            "bfaa": '1ef059a32710a29f84fbde5b5500d49c',
            "action": 'enter',
            "ftaa": 'uf8qxh8b5vphq6wna4',
            "remember": 'on',
            "_tta": 569
        }

        self.cookies.clear()

        response = self.get(LOGIN_URL)
        doc = pq(response.text)
        payload['csrf_token'] = doc('input').attr('value')
        payload['handleOrEmail'] = username
        payload['password'] = password
        self.csrf_token = payload['csrf_token']

        response = self.post(
            LOGIN_URL,
            data=payload,
            headers=dict(referer=LOGIN_URL)
        )

        doc = pq(response.text)
        username_again = doc('div').filter(
            '.lang-chooser').children().eq(1).children().eq(0).text()
        if username_again == 'Enter' or username_again.lower() != username.lower():
            return 'Login failed while logging in by default user'
        return "Login successfully"

    @staticmethod
    def load_session(session_file):
        try:
            with open(SESSION_FILE, 'rb') as f:
                ss = pickle.load(f)
            if ss.get_logged_username() != None:
                return ss
        except FileNotFoundError:
            print("This command requires login! Please login first!", file=sys.stderr)
        except AttributeError:
            print("Session time out. Please login again.", file=sys.stderr)
        ss = CSession()
        i = 0
        while i < 5:
            username = input('Username: ')
            password = getpass('Password: ')
            status = ss.login(username, password)
            if status != "Login successfully":
                print('Login failed! Please try again!')
            else:
                break
            i += 1
        return ss 
