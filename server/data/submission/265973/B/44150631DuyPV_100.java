d = int(input())
n = int(input())
line = []
for i in range(n):
	line.append([int(i) for i in input().split()])

A = []
for i in range(100):
	hang = []
	for j in range(100):
		hang.append(0)
	A.append(hang)

for i in range(n):
	A[line[i][0]-1][line[i][1]-1] = line[i][2]

def count(A, vi_tri, d):
	start_i = 0
	if vi_tri[0]-d > 0:
		start_i = vi_tri[0]-d
	end_i = 99
	if vi_tri[0]+d < 99:
		end_i = vi_tri[0]+d
	start_j = 0
	if vi_tri[1]-d > 0:
		start_j = vi_tri[1]-d
	end_j = 99	
	if vi_tri[1]+d < 99:
		end_j = vi_tri[1]+d
	tong = 0	
	for i in range(start_i, end_i+1):
		for j in range(start_j, end_j+1):
			# print(i,j, A[i][j])
			tong = tong + A[i][j]
	return tong

max = [0,0,0]
for i in range(100):
	for j in range(100):
		res = count(A, [i,j], d)
		if (res > max[2]):
			max[2] = res
			max[0] = i+1
			max[1] = j+1

for i in max:
	print(i, end=' ')		

