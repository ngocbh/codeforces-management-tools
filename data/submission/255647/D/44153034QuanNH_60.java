def saulap(s):
    n=len(s)
    i=0
    while i<len(s):
        for j in range(i,len(s)):
            if s[i]==s[j]:
                k=j
            else :break
        s=s[:i+1]+s[k+1:]
        i+=1
    return s
 
 
n=int(input())
i=1
s='1'
while len(s)<n:
    s=s[:len(s)-1]+saulap(s[len(s)-1]+str(i))
    
    i+=1
 
 
 
 
 
print(i-1)