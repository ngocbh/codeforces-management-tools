n=int(input())
s=input()
B=s.split(' ')
A=[int(i) for i in B]
D=[]
T=[]
i=0
while i<n-1:
    k=i
    if A[i]<A[i+1]:
        for j in range(i,n-1):
            if A[j]<A[j+1]:
                k=j+1
            else : break
    if k!=i:
        
        D.append((i,k))
        i=k
    else: i+=1
i=0
while i<n-1:

    k=i
    if A[i]>A[i+1]:
        for j in range(i,n-1):
            if A[j]>A[j+1]:
                k=j+1
            else : break
    if k!=i:
        
        T.append((i,k))
        i=k
    else: i+=1

maxT=0
maxD=0
for d in D:
    for t in T:
        if d[0]==t[1]:#thung lung
            m=min(abs(d[1]-d[0]),abs(t[0]-t[1]))
            if m>maxT: maxT=m
            
        if d[1]==t[0]:#doi
            m=min(abs(d[1]-d[0]),abs(t[1]-t[0]))
            if m>maxD:maxD=m
            

print(maxD,maxT)
            

