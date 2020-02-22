N=int(input())
Last=1
Stackk="1"  
i=2
while (Last!=N):
      d=str(i)
      i+=1
      lem=len(d);
      for j in range(lem):
            if d[j]!=Stackk:
                  Stackk=d[j]
                  Last+=1
      
print(i-1)
