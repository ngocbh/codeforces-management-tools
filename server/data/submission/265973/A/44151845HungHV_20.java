n, k = list(map(int, input().split()))
x = list(map(int, input().split()))

c = 0
for i in range(n):
    s = 0
    for j in range(i, n):
        s += x[j]
        if s % 3 == 0:
            c += 1
if k == 0 or n == 0:
    print(0)
else:
    print(c)
