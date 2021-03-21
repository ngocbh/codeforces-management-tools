# Conmato

A Command Line Interface (CLI) for Codeforces Management Tools that helps coach to 
manage Codeforces group easier.

## Features

* Managing member in a group (confirming or removing by Regex)
* Managing contest in a group 
* Crawling informations, standings, submission in a contest to csv format
* Checking plagiarism in contest

To see more, check the following [docs](https://github.com/ngocjr7/codeforces-management-tools/tree/master/docs)

## Installation

It requires `python>=3.6`. To install:

```sh
python3 -m pip install conmato
```

## Usage

You can see document by passing `--help` argument in each command
```sh
conmato --help

Usage: conmato [OPTIONS] COMMAND [ARGS]...

Options:
  --help  Show this message and exit.

Commands:
  config      Config command.
  contest     Contest commands.
  get         Get commands.
  login       Login command.
  member      Member commands.
  plagiarism  Plagiarism commands.
```

```sh
conmato get --help

Usage: conmato get [OPTIONS] COMMAND [ARGS]...

  Get commands.

Options:
  --help  Show this message and exit.

Commands:
  contest     Get all standing and submission in a contest.
  member      Get members in a group.
  pstandings  Get all standing with plagiarism in a contest.
  standings   Get standing in a contest.
  submission  Get all submission in a contest.
  username    Get this logged username.
```

```sh
conmato get standings --help

Usage: conmato get standings [OPTIONS]

Get standing in a contest.

Options:
-g, --group-id TEXT     Group id in Codeforces.com.
-c, --contest-id TEXT   Contest id in Codeforces.com.  [required]
-f, --user-format TEXT  User format.
-cm, --common           Flag for getting all participants (group outter
                        included).

-o, --output-dir TEXT   Output directory.
--help                  Show this message and exit.
```

Almost functions of conmato requires login before performing.
Usually, Conmato will ask on each action. 
You can login once and save session for future usages by:

```sh
conmato login
```

To get standings in a contest (e.x. `http://codeforces.com/group/Ir5CI6f3FD/contest/269185/standings/groupmates/true`), 
you have to pass `group_id` (e.x. `Ir5CI6f3FD`) and `contest_id` (e.x. `269185`)

```sh
conmato get standings -g Ir5CI6f3FD -c 269185
```

For more detail, check this [doc](https://github.com/ngocjr7/codeforces-management-tools/tree/master/docs/cli.md).

## Issues and Contribution

This project is in development, if you find any issues, please create an issue [here](https://github.com/ngocjr7/codeforces-management-tools/issues).

If you are interested in contributing this project, feel free to create pull request [here](https://github.com/ngocjr7/codeforces-management-tools/pulls). We appreciate any contribution in community.

## Acknowledgement 

This project is sponsored and led by Prof. Do Phan Thuan, Hanoi University of Science and Technology.
Thank Thai Do (Dec1mo) and Tung Tran (tungtran309) for helping me to develop this project.

