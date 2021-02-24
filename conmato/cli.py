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

@member.command('get', help='Get members in a group.')
@click.option(
    '--group-id', '-g', required=True,
    help='Group id in Codeforces.com'
)
@click.option(
    '--output-file', '-o', 
    help='CSV file path to store all members in a group.'
)
@click.option(
    '--all', '-a', is_flag=True,
    help='Get all members in a group.'
)
@click.option(
    '--pending', '-pe', is_flag=True,
    help='Get pending participants in a group.'
)
def get(all, pending, group_id, output_file=None):
    if not all and not pending:
        print("Error: Missing option '--all' / '-a' or '--pending' / '-pe'", file=sys.stderr)
    else:
        ss = load_session(SESSION_FILE)
        if pending:
            members = get_pending_participants(ss, group_id)
        else:
            members = get_all_members(ss, group_id)
        if output_file != None:
            try:
                to_df(members).to_csv(output_file)
                print('Members was written to {} successfully'.format(output_file))
            except FileNotFoundError:
                print("Failed to write to file\nNo such file or directory: {}".format(output_file), file=sys.stderr)
                sys.exit(-1)
        else:
            print(to_df(members))

if __name__ == "__main__":
    cli()