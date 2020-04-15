import conmato
import os


# Would you like to use the submission time to rank participants?
PENALTY=True


# A list of user usernames = ['abc', 'def']
USERNAMES=None # None to get all participants

contest_id = '256575'

conmato.get_standings_to_csv(contest_id, usernames=USERNAMES, penalty=PENALTY)