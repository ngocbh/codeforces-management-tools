<<<<<<< Updated upstream
N = int(input())
M = []
p = pow(10, 9) + 7
	
for i in range(N + 1):
	M.append(-1)

def solve(n):
	if M[n] != -1:
		return (M[n] % p)
	else:
		M[n] = 4 * solve(n-1) - solve(n-2)
		if M[n] > p:
			M[n] = M[n] % p
	
	return M[n]

M[0] = 0
M[1] = 1
res = solve(N)
=======
N = int(input())
M = []
p = pow(10, 9) + 7
	
for i in range(N + 1):
	M.append(-1)

def solve(n):
	if M[n] != -1:
		return (M[n] % p)
	else:
		M[n] = 4 * solve(n-1) - solve(n-2)
		if M[n] > p:
			M[n] = M[n] % p
	
	return M[n]

M[0] = 0
M[1] = 1
res = solve(N)
>>>>>>> Stashed changes
print(res % p)