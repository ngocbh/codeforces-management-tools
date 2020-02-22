S=[]
n=int(input())

S.append(0)
S.append(1)
S.append(4)
if n<3:
    print(S[n])
else:
    for i in range(3,n+1):
        a=4*S[i-1]-S[i-2]
        a=a % 1000000007
        S.append(a)
    print(S[n])