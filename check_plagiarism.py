import conmato

# Provide your contestID or your contest URL
contestID = '257806'

ss = conmato.CSession()

ss.login(username='',password='')

conmato.check_plagiarism(ss, contestID)
# conmato.crawl_checked_standings(ss, contestID)
