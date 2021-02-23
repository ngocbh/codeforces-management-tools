from __future__ import absolute_import

from .check_plagiarism import *
from .contest import *
from .crawl_standings import *
from .csession import *
from .member import *
from .mossum import *
from .parameters import *
from .utils import *

import click
import sys
import pickle
import json
from pprint import pprint

@click.group()
def cli():
    pass

# Authentication commands
@cli.group(help='Authentication commands')
def auth():
    pass

@auth.command('login', help='Login to Codeforces.com.')
@click.option(
    '--username', '-u', required=True,
    help='Username in Codeforces.com'
)
@click.option(
    '--password', '-p', required=True,
    help='Password in Codeforces.com'
)
def auth_login(username, password):
    ss = CSession()
    ss.login(username, password)
    if ss.get_logged_username() == None:
        print("Login fail! Please try again!", file=sys.stderr)
        sys.exit(-1)
    print('Successfully login with username: ', ss.get_logged_username())
    with open(SESSION_FILE, 'wb') as f:
        pickle.dump(ss, f)

@auth.command('get-username', help='Get this logged username.')
def auth_get_username():
    ss = load_session(SESSION_FILE)
    print(ss.get_logged_username())

# Member commands 
@cli.group(help='Member commands')
def member():
    pass

@member.command('is-manager', help='Check if this user is the group manager.')
@click.option(
    '--group-id', '-g', required=True,
    help='Group id in Codeforces.com'
)
@click.option(
    '--username', '-u', required=True,
    help='Username in Codeforces.com'
)
@click.option(
    '--password', '-p', required=True,
    help='Password in Codeforces.com'
)
def member_is_manager(group_id, username, password):
    print(is_manager(group_id, username, password))

@member.command('get-all', help='Get all members in a group.')
@click.option(
    '--group-id', '-g', required=True,
    help='Group id in Codeforces.com'
)
@click.option(
    '--output-file', '-o', 
    help='Filepath to store all members in a group.'
)
def member_get_all(group_id, output_file=None):
    ss = load_session(SESSION_FILE)
    # print(output_file)
    all_members = get_all_members(ss, group_id)
    if output_file != None:
        # indent=4,
        with open(output_file, 'w', encoding='utf-8') as f:
            json.dump(all_members, f, indent=4)
        print('All members was written to {} successfully'.format(output_file))
    else:
        pprint(all_members)

if __name__ == "__main__":
    cli()