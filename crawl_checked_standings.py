import conmato

# Provide your contestID or your contest URL
contestID = '265973'

ss = conmato.CSession()
print(ss.is_manager('74164707NgocBh','123456789'))
ss.login('74164707NgocBh','123456789')
print(conmato.get_managed_contests(ss))

conmato.check_plagiarism(ss, '269186')
# conmato.crawl_checked_standings(ss, '269186')
