N=int(input())
Last=0
Stackk=[]
def push(s="2"):
      global Last
      Last+=1
      Stackk.append(s)
push("1")
for i in range(1,N+1):
      d= str(i);
      lem=len(d);
      for j in range(lem):
            if d[j]!=Stackk[Last-1]:
                  push(d[j])

print(Last)
