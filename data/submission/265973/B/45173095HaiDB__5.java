def Phabom(d, x, y, matran, maxX, minX, maxY, minY):
    i = max(x-d, minX, 0)
    bom = 0
    while(i <= min(x+d, maxX, 100)):
        j = max(y-d, minY, 0)
        while(j <= min(y+d, maxY, 100)):
            bom = bom + matran[i][j]
            j = j+1
        i = i+1
    return bom

d = int(input())
n = int(input())
matran = []
for i in range(0, 101):
    matran.append([])
    for j in range (0,101):
        matran[i].append(0)

minX = 100
maxX = 0
minY = 100
maxY = 0
for dem in range(0, n):
    dulieu = input()
    dulieu = dulieu.split()
    x = int(dulieu[0])
    y = int(dulieu[1])
    c = int(dulieu[2])
    matran[x][y] = c
    if(x < minX):
        minX = x
    if(x > maxX):
        maxX = x
    if(y < minY):
        minY = y
    if(y > maxY):
        maxY = y
i = minX
j = minY
c = 0
x = 0
y = 0
while(i <= maxX):
    j = minY
    while(j <= maxY):
        temp = Phabom(d, i, j, matran, maxX, minX, maxY, minY)
        if(c < temp):
            c = temp
            x = i
            y = j
        j = j+1
    i = i+1
print(x, y, c)
