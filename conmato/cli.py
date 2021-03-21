from __future__ import absolute_import

from conmato.check_plagiarism import *
from conmato.contest import *
from conmato.crawl_standings import *
from conmato.csession import *
from conmato.member import *
from conmato.mossum import *
from conmato.parameters import *
from conmato.utils import *

import os
import click
import sys
import pickle
import json
import yaml
from tqdm import tqdm

@click.group()
def cli():
    pass

@cli.command('config', help='Config command.')
@click.option(
    '--reset', '-rs', is_flag=True,
    help='Reset config file to default values.'
)
@click.option(
    '--show', '-s', is_flag=True,
    help="Show all parameters in config files."
)
@click.option(
    '--group-id', '-g', default=None, 
    help='Group id in Codeforces.com.'
)
@click.option(
    '--min-lines', '-ml', type=int,
    help='Min similar lines between two files.'
)
@click.option(
    '--min-percent', '-mp', type=int,
    help='Min percent between two files.'
)
@click.option(
    '--user-id', '-uid', type=int,
    help='User id in moss.standford.edu, to register check https://theory.stanford.edu/~aiken/moss/.'
)
@click.option(
    '--transformer', '-tr', 
    help='A regular expression that is used to transform the name of them matched files.'
)
@click.option(
    '--new-score', '-ns', 
    help='Assign new score to cheating submission.'
)
@click.option(
    '--default-username', '-du', 
    help='Default username.'
)
@click.option(
    '--default-password', '-dp', 
    help='Default password.'
)
@click.option(
    '--user-key', '-uk', 
    help='Get key here http://codeforces.com/settings/api.'
)
@click.option(
    '--user-secret', '-us', 
    help='Get sceret here http://codeforces.com/settings/api.'
)
@click.option(
    '--timesleep', '-ts', type=int,
    help='Time sleep.'
)
def config(reset, show, group_id, min_lines, min_percent, 
    user_id, transformer, new_score, default_username, 
    default_password, user_key, user_secret, timesleep):
    if reset:
        with open(USER_CONFIG_FILE, 'w') as file:
            yaml.dump(None, file)
        print('Successfully reset config file.')

    with open(USER_CONFIG_FILE) as file:
        config = yaml.full_load(file) or {}
    if group_id != None:
        config['group_id'] = group_id
    if min_lines != None:
        config['min_lines'] = min_lines
    if min_percent != None:
        config['min_percent'] = min_percent
    if user_id != None:
        config['user_id'] = user_id
    if transformer != None:
        config['transformer'] = transformer
    if new_score != None:
        config['new_score'] = new_score
    if default_username != None:
        config['default_username'] = default_username
    if default_password != None:
        config['default_password'] = default_password
    if user_key != None:
        config['user_key'] = user_key
    if user_secret != None:
        config['user_secret'] = user_secret
    if timesleep != None:
        config['timesleep'] = timesleep
    with open(USER_CONFIG_FILE, 'w') as file:
        yaml.dump(config, file)
    # print('Successfully updated config file.')

    if show:
        printed_paras = set()
        print("All parameters in user config file:")
        if not config:
            print()
        else:
            for k, v in config.items():
                print('{}: {}'.format(k, v))
                printed_paras.add(k)
        print('='*80)
        print("All parameters in default config file:")
        with open(DEFAULT_CONFIG_FILE) as file:
            config = yaml.full_load(file) or {}
        if not config:
            print()
        else:
            for k, v in config.items():
                if k not in printed_paras:
                    print('{}: {}'.format(k, v))

@cli.command('login', help='Login command.')
@click.option(
    '--username', '-u', required=True, prompt=True,
    help='Username in Codeforces.com.'
)
@click.option(
    '--password', '-p', required=True, prompt=True, hide_input=True,
    help='Password in Codeforces.com.'
)
def login(username, password):
    ss = CSession()
    if ss.login(username, password) != "Login successfully":
        print("Login fail! Please try again!", file=sys.stderr)
        sys.exit(-1)
    print('Successfully login with username: ', ss.get_logged_username())
    with open(SESSION_FILE, 'wb') as f:
        pickle.dump(ss, f)

# Member commands 
@cli.group(help='Member commands.')
def member():
    pass

@member.command('is-manager', help='Check if this user is the group manager.')
@click.option(
    '--group-id', '-g',
    help='Group id in Codeforces.com.'
)
@click.option(
    '--username', '-u', required=True,
    help='Username in Codeforces.com.'
)
@click.option(
    '--password', '-p', required=True,
    help='Password in Codeforces.com.'
)
def is_manager(group_id, username, password):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    print(is_manager(group_id, username, password))

@member.command('confirm', help='Confirm members in a group.')
@click.option(
    '--group-id', '-g',
    help='Group id in Codeforces.com.'
)
@click.option(
    '--input-file', '-i',
    help='CSV file path that stores members.'
)
@click.option(
    '--user-format', '-f', 
    help='User format.'
)
@click.option(
    '--action', '-ac', required=True,
    type=click.Choice(['accept','reject'], case_sensitive=False),
    help='Accept or reject users.'
)
def confirm(group_id, action, input_file, user_format):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    ss = CSession.load_session(SESSION_FILE)

    members = get_pending_participants(ss, group_id)
    if not members:
        print('There is no pending members to be confirmed.')
        sys.exit(0)
    members_df = to_df(members)

    if input_file != None:
        try:
            input_df = pd.read_csv(input_file)
            input_df = input_df['username']
        except KeyError:
            input_df = pd.read_csv(input_file, header=None)  
            input_df = input_df.iloc[:, 0]
        members_df = members_df[members_df['username'].isin(input_df.tolist())]

    if user_format != None:
        members_df = members_df[members_df['username'].str.match(user_format)==True]

    print('Do you want to confirm (accept/reject) {} user(s)? [y/n]: '.format(len(members_df)), end='')
    ans = input()
    if ans.strip().lower() == 'y':
        members = members_df.to_dict('records')
        for member in tqdm(members, desc='Confirming members', unit=' members'):
            confirm_joining(ss, member, action, group_id)
        print('Successfully {}ed {} user(s)'.format(action, len(members_df)))

@member.command('remove', help='Remove members in a group.')
@click.option(
    '--input-file', '-i',
    help='CSV file that stores members.'
)
@click.option(
    '--user-format', '-f', 
    help='User format.'
)
@click.option(
    '--group-id', '-g', 
    help='Group id in Codeforces.com.'
)
def remove(group_id, input_file, user_format):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    ss = CSession.load_session(SESSION_FILE)
    
    members = get_all_members(ss, group_id)
    if not members:
        print('There is no members in the group to be removed.')
        sys.exit(0)
    members_df = to_df(members)

    if input_file != None:
        try:
            input_df = pd.read_csv(input_file)
            input_df = input_df['username']
        except KeyError:
            input_df = pd.read_csv(input_file, header=None)  
            input_df = input_df.iloc[:, 0]
        members_df = members_df[members_df['username'].isin(input_df.tolist())]

    if user_format != None:
        members_df = members_df[members_df['username'].str.match(user_format)==True]
    print('Do you want to remove {} user(s)? [y/n]: '.format(len(members_df)), end='')
    ans = input()
    if ans.strip().lower() == 'y':
        members = members_df.to_dict('records')
        for member in tqdm(members, desc='Removing member(s)', unit=' members'):
            remove_participants(ss, member, group_id)
        print('Successfully removed {} user(s)'.format(len(members_df)))

# Contest commands 
@cli.group(help='Contest commands.')
def contest():
    pass

@contest.command('ls', help='List all contests of a group.')
@click.option(
    '--group-id', '-g', 
    help='Group id in Codeforces.com.'
)
def ls(group_id):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    ss = CSession.load_session(SESSION_FILE)

    contests = get_contests(ss, group_id)
    contest_df = pd.DataFrame(data={'contest id':list(contests.keys()),
        'contest name': list(contests.values())})
    print(contest_df)

@contest.command('register', help='Register users to join contest.')
@click.option(
    '--group-id', '-g', required=True,
    help='Group id in Codeforces.com.'
)
def register(group_id):
    print('Developing')

@contest.command('manage', help='Turn on manager-mode for contest(s) in a group.')
@click.option(
    '--group-id', '-g',
    help='Group id in Codeforces.com.'
)
@click.option(
    '--contest-id', '-c',
    help='Contest id in Codeforces.com.'
)
@click.option(
    '--mode', '-m', required=True,
    type=click.Choice(['true','false'], case_sensitive=False),
    help='true for Yes, false for No.'
)
def manage(group_id, contest_id, mode):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    ss = CSession.load_session(SESSION_FILE)

    if contest_id != None:
        toggle_manager_mode(ss, contest_id, group_id, mode)
        contest_ids = [contest_id]
    else:
        ret = get_managed_contests(ss, group_id, mode)
        contest_ids = ret.keys()
    for contest_id in contest_ids:
        print('Successfully changed manage mode at contest {} in group {}.'
            .format(contest_id, group_id, mode))

# Plagiarism commands 
@cli.group(help='Plagiarism commands.')
def plagiarism():
    pass

@plagiarism.command('check', help='Check plagiarism.')
@click.option(
    '--group-id', '-g',
    help='Group id in Codeforces.com.'
)
@click.option(
    '--contest-id', '-c', required=True,
    help='Contest id in Codeforces.com.'
)
@click.option(
    '--min-lines', '-ml', 
    help='Min similar lines between two files.'
)
@click.option(
    '--min-percent', '-mp', 
    help='Min percent between two files.'
)
@click.option(
    '--submission-dir', '-sd', required=True,
    help='Submission directory (output dir from "get submission" command).'
)
@click.option(
    '--output-dir', '-o', 
    help='Output directory.'
)
def check(group_id, contest_id, min_lines, min_percent, submission_dir, output_dir):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    if not min_lines and MIN_LINES:
        min_lines = MIN_LINES
    if not min_percent and MIN_PERCENT:
        min_percent = MIN_PERCENT
    if not output_dir:
        output_dir = './'
    ss = CSession.load_session(SESSION_FILE)

    print("Checking plagiarism".format(contest_id, group_id))
    check_plagiarism(ss, contest_id, submission_dir, group_id, min_lines, min_percent, True, output_dir)
    outdir = os.path.join(output_dir, 'plagiarism_report_{}'.format(contest_id))
    print("Successfully saved plagiarism checking report of contest {} of group {} in directory: {}.".\
        format(contest_id, group_id, outdir))

@cli.group(help='Get commands.')
def get():
    pass

@get.command('username', help='Get this logged username.')
def username():
    ss = CSession.load_session(SESSION_FILE)
    print(ss.get_logged_username())

@get.command('member', help='Get members in a group.')
@click.option(
    '--group-id', '-g',
    help='Group id in Codeforces.com.'
)
@click.option(
    '--type', '-t', multiple=True,
    type=click.Choice(['all','pending', 'spectator', 'manager', 'participant'], case_sensitive=False),
    help='Get members in a group.'
)
@click.option(
    '--user-format', '-f', 
    help='User format.'
)
@click.option(
    '--output-dir', '-o', 
    help='Output directory.'
)
def member(group_id, type, user_format, output_dir):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    ss = CSession.load_session(SESSION_FILE)

    if not type:
        type = ('all',)

    if 'all' in type:
        members = get_all_members(ss, group_id)
        result_df = to_df(members)
        result_df.loc[result_df['pending']==True, ['role']] = 'pending'
        result_df.drop(columns={'pending', 'csrf_token', 'groupRoleId', '_tta'}, inplace=True)
    else:
        pending_members_df = pd.DataFrame(columns={'username', 'role'})
        remaining_members_df = pd.DataFrame(columns={'username', 'role'})

        if 'pending' in type:
            pending_members = get_pending_participants(ss, group_id)
            pending_members_df = to_df(pending_members)
            pending_members_df['role'] = 'pending'
            pending_members_df.drop(columns={'csrf_token', 'groupRoleId', '_tta'}, inplace=True)

        remaining_roles = set(type) - {'pending'}
        if remaining_roles:                 
            remaining_members = get_all_members(ss, group_id)
            remaining_members_df = to_df(remaining_members)
            remaining_members_df = remaining_members_df[remaining_members_df['pending']==False]
            remaining_members_df = remaining_members_df[remaining_members_df['role'].isin(list(remaining_roles))]
            remaining_members_df.drop(columns={'pending', 'csrf_token', 'groupRoleId', '_tta'}, inplace=True)

        result_df = pd.concat([pending_members_df, remaining_members_df])
    if user_format != None:
        result_df = result_df[result_df['username'].str.match(user_format)==True]
    if output_dir != None:
        output_file = os.path.join(output_dir,'members_{}_{}.csv'.format(group_id, '_'.join(type)))
        create_dir(output_file)
        result_df.to_csv(output_file, index=False)
        print('Successfully saved members in group id {} to {}'.format(group_id, output_file))
    else:
        if result_df.empty:
            print('There is no members!')
        else:
            print(result_df.to_string())

@get.command('contest', help='Get all standing and submission in a contest.')
@click.option(
    '--group-id', '-g', 
    help='Group id in Codeforces.com.'
)
@click.option(
    '--contest-id', '-c', required=True,
    help='Contest id in Codeforces.com.'
)
@click.option(
    '--output-dir', '-o', 
    help='Output directory.'
)
def contest(group_id=None, contest_id=None, output_dir=None):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    if not output_dir:
        output_dir = './'
    ss = CSession.load_session(SESSION_FILE)

    members = get_all_members(ss, group_id)
    members_df = to_df(members)
    members_df = members_df[members_df['pending']==False]
    standings = get_standings(contest_id, usernames=members_df['username'].to_list())
    standing_df = standing_to_df(standings)

    # Saving standings file
    contest_name = get_contest_name(ss, contest_id, group_id)
    standings_file = os.path.join(output_dir, 'contest_{}_{}-{}/standings.csv'.format(
        group_id, contest_id, contest_name))
    create_dir(standings_file)
    standing_df.to_csv(standings_file, index=False)
    # print('Standings was written to {} successfully'.format(standings_file))

    # Saving submission  file
    print("Getting all submission from contest {} in group {}".format(contest_id, group_id))
    new_output_dir = os.path.join(output_dir, 'contest_{}_{}-{}'.format(
        group_id, contest_id, contest_name))
    get_all_submission(ss, contest_id, new_output_dir, group_id)
    print("Successfully saved contest {} in group {} to directory: {}".
        format(contest_id, group_id, new_output_dir))

@get.command('standings', help='Get standing in a contest.')
@click.option(
    '--group-id', '-g',
    help='Group id in Codeforces.com.'
)
@click.option(
    '--contest-id', '-c', required=True,
    help='Contest id in Codeforces.com.'
)
@click.option(
    '--user-format', '-f', 
    help='User format.'
)
@click.option(
    '--common', '-cm', is_flag=True,
    help='Flag for getting all participants (group outter included).')
@click.option(
    '--output-dir', '-o', 
    help='Output directory.'
)
def standings(group_id, contest_id, user_format, common, output_dir):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id and not common:
        print("group-id not found in the command or config file.\n" + \
            "Please provide group id or use '--common'/'-cm' flag to get common standings.", file=sys.stderr)
        sys.exit(-1)
    # if not output_dir:
    #     output_dir = './'
    ss = CSession.load_session(SESSION_FILE)

    if common:
        standings = get_standings(contest_id, usernames=None, user_format=user_format)
        standing_df = standing_to_df(standings)
        if user_format != None:
            standing_df = standing_df[standing_df['Who'].str.match(user_format)==True]
    else:
        members = get_all_members(ss, group_id)
        members_df = to_df(members)
        members_df = members_df[members_df['pending']==False]
        # print('members_df = ', members_df)
        standings = get_standings(contest_id, usernames=members_df['username'].to_list(), user_format=user_format)
        # print('standings = ', standings)
        standing_df = standing_to_df(standings)
    
    if output_dir != None:
        name = 'common' if common else group_id
        output_file = os.path.join(output_dir, 'standings_{}_{}.csv'.format(name, contest_id))
        create_dir(output_file)
        standing_df.to_csv(output_file, index=False)
        print('Successfully saved standings {} successfully'.format(output_file))
    else:
        print(standing_df.to_string())

@get.command('submission', help='Get all submission in a contest.')
@click.option(
    '--group-id', '-g',
    help='Group id in Codeforces.com.'
)
@click.option(
    '--contest-id', '-c', required=True,
    help='Contest id in Codeforces.com.'
)
@click.option(
    '--user-format', '-f', 
    help='User format.'
)
@click.option(
    '--output-dir', '-o', 
    help='Output directory.'
)
def submission(group_id, contest_id, user_format, output_dir):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    if not output_dir:
        output_dir = './'
    ss = CSession.load_session(SESSION_FILE)

    print("Getting all submission from contest {} in group {}".format(contest_id, group_id))
    get_all_submission(ss, contest_id, output_dir, group_id, page=1, user_format=user_format)
    outdir = os.path.join(output_dir, 'submission_{}'.format(contest_id))
    print("Successfully saved all submission from contest {} in group {} to directory: {}".
        format(contest_id, group_id, outdir))

@get.command('pstandings', help='Get all standing with plagiarism in a contest.')
@click.option(
    '--group-id', '-g', 
    help='Group id in Codeforces.com.'
)
@click.option(
    '--contest-id', '-c', required=True,
    help='Contest id in Codeforces.com.'
)
@click.option(
    '--min-lines', '-ml', 
    help='Min similar lines between two files.'
)
@click.option(
    '--min-percent', '-mp', 
    help='Min percent between two files.'
)
@click.option(
    '--submission-dir', '-sd', required=True,
    help='Submission directory (output dir from "get submission" command).'
)
@click.option(
    '--output-dir', '-o', 
    help='Output directory.'
)
def pstandings(group_id, contest_id, min_lines, min_percent, submission_dir, output_dir):
    if not group_id and GROUP_ID:
        group_id = GROUP_ID
    if not group_id:
        print("group-id not found in the command or config file.", file=sys.stderr)
        sys.exit(-1)
    if not min_lines and MIN_LINES:
        min_lines = MIN_LINES
    if not min_percent and MIN_PERCENT:
        min_percent = MIN_PERCENT
    if not output_dir:
        output_dir = './'
    ss = CSession.load_session(SESSION_FILE)

    print("Crawling checked standings from contest {} in group {}".format(contest_id, group_id))
    crawl_checked_standings(ss, contest_id, submission_dir, group_id, min_lines, min_percent, True, output_dir)
    outdir = os.path.join(output_dir, 'plagiarism_stadings_report_{}'.format(contest_id))
    print("Successfully crawled checked standings from contest {} in group {} to directory: {}".
        format(contest_id, group_id, outdir))

if __name__ == "__main__":
    cli()