import conmato

# Provide your contestID or your contest URL
contestID = '265973'

ss = conmato.CSession()

print(ss.login('',''))
print(conmato.get_contests(ss))


# conmato.check_plagiarism(ss, contestID)
# conmato.crawl_checked_standings(ss, contestID)
