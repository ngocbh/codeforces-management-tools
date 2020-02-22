dulieu = input()
dulieu2 = input()
kt = dulieu.split()
n = int(kt[0])
k = int(kt[1])
kt = dulieu2.split()
i = 0
while(i < len(kt)):
    kt[i] = int(kt[i])
    i = i+1
i = 0
dem = 0
while(i < len(kt)):
    j = i
    t = 0
    while(j < len(kt)):
        t = t + kt[j]
        if(t % k == 0):
            dem = dem+1
        j = j+1
    i = i+1
print(dem)