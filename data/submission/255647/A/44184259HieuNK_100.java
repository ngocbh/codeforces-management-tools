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
 
s=input()
print(saulap(s))
