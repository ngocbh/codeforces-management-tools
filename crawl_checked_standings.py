import conmato

# Provide your contestID or your contest URL
contestID = '255647'

ss = conmato.CSession()

ss.login('74164707NgocBH','123456789')

# conmato.check_plagiarism(ss, contestID)
conmato.crawl_checked_standings(ss, contestID)
