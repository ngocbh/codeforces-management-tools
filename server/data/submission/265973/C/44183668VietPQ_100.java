n=int(input())
S=[]
S.append(int(0))
S.append(int(1))
S.append(int(4))
a=1000000007
for i in range(3,n+1):
        b=4*S[i-1]-S[i-2]
        b=b%a
        S.append(int(b))
print(S[n]) 