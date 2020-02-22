<<<<<<< Updated upstream
s=input()
B=s.split(' ')
N=int(B[0])
K=int(B[1])

s=input()
B=s.split(' ')
A=[int(i) for i in B]


def sum(i,j):
    global A
    s=0
    for m in range(i,j+1):
        s+=A[m]
    return s

count=0
for i in range(N):
    for j in range(i,N):
        if sum(i,j)%K ==0:
            count+=1
print(count)
    
        
        
=======
s=input()
B=s.split(' ')
N=int(B[0])
K=int(B[1])

s=input()
B=s.split(' ')
A=[int(i) for i in B]


def sum(i,j):
    global A
    s=0
    for m in range(i,j+1):
        s+=A[m]
    return s

count=0
for i in range(N):
    for j in range(i,N):
        if sum(i,j)%K ==0:
            count+=1
print(count)
    
        
        
>>>>>>> Stashed changes
