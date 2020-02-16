n = int(input())
a = [int(i) for i in input().split()]

def find_up(a, t):
	up = 0
	for i in range(t, n-1):	
		if a[i] < a[i+1]:
			up += 1

		else:
			return [up,i,1]
	return [up,n-1,1]		

def find_flat(a, t):
	flat = 0
	for i in range(t, n-1):	
		if a[i] == a[i+1]: 
			flat += 1

		else :
			return [flat,i,0]
	return [flat,n-1,0]
			
def find_down(a, t):
	down = 0
	for i in range(t, n-1):	
		if a[i] > a[i+1]:
			down += 1

		else:
			return [down,i,-1]	
	return [down,n-1,-1]						

S = []
i = 0
while i < n-1:
	u = find_up(a,i)
	f = find_flat(a,i)
	d = find_down(a,i)
	if u[0] > 0:
		i = u[1]
		S.append(u)
	elif f[0] > 0:
		i = f[1]
		S.append(f)	
	else:
		i = d[1]
		S.append(d)	

high = 0
down = 0
for i in range(0,len(S)-1):
	if S[i][2] > 0 and S[i+1][2] < 0:
		high = max(high, min(S[i][0], S[i+1][0]))

	elif S[i][2] < 0 and S[i+1][2] > 0:
		down = 	max(down, min(S[i][0], S[i+1][0]))

print(high, down)		
			