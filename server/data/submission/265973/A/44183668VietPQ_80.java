st=input().split(" ")
n=int(st[0])
k=int(st[1])
s=[]
s=[int(i) for i in input().split(" ")]
dem=0
for i in range(n):
    sum=0
    for j in range(i,n):
        sum=sum+s[j]
        sum=sum%k
        if sum==0:
            dem=dem+1
print(dem)