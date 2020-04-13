import conmato

# Provide your contestID or your contest URL
contestID = '256575'
groupID = 'bveFK04PIR'
ss = conmato.CSession()
ss.login('74164707NgocBH','123456789')
# print(conmato.member.is_manager(groupID,'74164709NgocBH','123456789'))
# print(conmato.contest.get_managed_contests(ss, groupID=groupID))
# print(ss.get_logged_username())

# USER_FORMAT=r'^[0-9]{8,10}[A-Za-z]{4,10}$'
# conmato.member.confirm_all_participants(ss, 'reject', user_format=USER_FORMAT, groupID=groupID)
# members = conmato.member.get_all_members(ss, groupID)
# print(members)
# print(len(members))

# members = conmato.member.get_pending_participants(ss, groupID)
# print(members)
# print(len(members))
# conmato.member.remove_all_participants(ss, user_format=USER_FORMAT, groupID=groupID)

# conmato.check_plagiarism(ss, contestID, groupID=groupID, min_lines=10, min_percent=90)
# conmato.crawl_checked_standings(ss, '269186')


conmato.crawl_checked_standings(ss, contestID)