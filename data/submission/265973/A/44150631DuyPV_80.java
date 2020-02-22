<<<<<<< Updated upstream
#input
N, K = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]	

# algorithm
Q = 0
for i in range(1, N+1):
	for j in range(0, N-i+1):
		tong = 0
		for k in range(j, j+i):
			tong = tong + a[k]
		if tong % K == 0:
				Q = Q + 1

=======
#input
N, K = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]	

# algorithm
Q = 0
for i in range(1, N+1):
	for j in range(0, N-i+1):
		tong = 0
		for k in range(j, j+i):
			tong = tong + a[k]
		if tong % K == 0:
				Q = Q + 1

>>>>>>> Stashed changes
print(Q)				