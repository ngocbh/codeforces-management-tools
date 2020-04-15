import conmato

# Provide your contestID or your contest URL
contestID = '256575'
groupID = 'bveFK04PIR'
ss = conmato.CSession()
ss.login('74164707NgocBH','123456789')

conmato.crawl_checked_standings(ss, contestID)