<<<<<<< Updated upstream
n=int(input())
if n==1:
    print(1)
elif n==2:
    print(4)
else:    
    A=[0]*n
    A[0]=1
    A[1]=4
    i=2
    while i<n:
        A[i]=4*A[i-1]-A[i-2]
        i+=1
        
        
    print(A[n-1]%(10**9+7))
=======
n=int(input())
if n==1:
    print(1)
elif n==2:
    print(4)
else:    
    A=[0]*n
    A[0]=1
    A[1]=4
    i=2
    while i<n:
        A[i]=4*A[i-1]-A[i-2]
        i+=1
        
        
    print(A[n-1]%(10**9+7))
>>>>>>> Stashed changes
        