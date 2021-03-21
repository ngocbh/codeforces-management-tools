import conmato

conmato.cli()

# ss = conmato.CSession() # create codeforces session, inherited request.Session()
# ss.login(username='74164707NgocBH',password='123456789') # login to codeforces and save cookie to ss
# ss.get_logged_username() # get current username logging in codeforces

# group_id = 'bveFK04PIR'
# contest_id = '311013'
# # conmato.get_all_submission(ss, contest_id, './result', group_id)
# from pprint import pprint
# pprint(conmato.get_standings(contest_id))