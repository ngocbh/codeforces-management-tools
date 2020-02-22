d = int(input())
n = int(input())  
xx_min = 100
yy_min = 100
xx_max = 0
yy_max = 0
ll = [0] * n
for i in range(n):
    x, y, c = list(map(int, input().split(' ')))  
    x = x - 1
    y = y - 1
    if x > xx_max: xx_max = x
    if y > yy_max: yy_max = y
    if x < xx_min: xx_min = x
    if y < yy_min: yy_min = y 
    ll[i] = [x, y, c]
ans = -9999999999
x_ans = 0
y_ans = 0 
for i in range(xx_min, xx_max + 1):
    for j in range(yy_min, yy_max + 1):
        x, y = i, j
        result = 0
        for xy in ll:
            x0, y0, c = xy
            if max(abs(x - x0), abs(y - y0)) <= d: 
                result += c 
        if result > ans:
            ans = result
            x_ans = x
            y_ans = y  
print(x_ans + 1, y_ans + 1, ans)