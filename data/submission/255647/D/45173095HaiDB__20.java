import math

n = int(input())
s = 0
i=0
kt = True
while (kt):
	i = i+1
	j = i
	k = int( math.log(j)/math.log(10) )
	while(k >= 0):
		if(s%10 != int( j/int( math.pow(10, k) ) )):
			s = s*10 + int( j/int( math.pow(10, k) ) )
		j = j%int(math.pow(10, k))
		k = k -1
	if(n == int( math.log(s)/math.log(10) ) +1):
		kt = False
print(i)

