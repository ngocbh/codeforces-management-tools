n, k = map(int, input().split(' ')) 
l = list(map(int, input().split(' ')))  
count = 0
for i in range(n):
    S = l[i]
    if S % k == 0:
        count += 1
    for j in range(i + 1, n):
        S += l[j]
        if S % k == 0:
            count += 1
print(count)