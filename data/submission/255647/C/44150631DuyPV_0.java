import math

n = int(input())

dc_tho = []
dc_khach = []
for i in range(0,n):
	dc_tho.append(int(input()))
for i in range(0,n):
	dc_khach.append(int(input()))

# print(n,dc_tho,dc_khach)

c = []
for i in range(0,n):
	x = []
	for j in range(0,n):
		x.append(math.pow(dc_tho[i]-dc_khach[j],2))
	c.append(x)

# print(c)

taged = []
for i in range(0,n):
	taged.append(False)

def ucv():
	S = []
	for i in range(0,n):
		if taged[i] == False:
			S.append(i)
	return S		

f = 9000000000000000000
chiphi = 0
def brach(k):
	global taged
	global f
	global chiphi

	S = ucv()
	# print(S)
	for y in S:
		# print(y,k)
		taged[y] = True
		chiphi += c[k][y]
		if k == n-1:
			f = min(f, chiphi)
		elif chiphi <= f:
			brach(k+1)
		taged[y] = False
		chiphi -= c[k][y]	
		
brach(0)				
print(int(f))
# print(c[0][0]+c[1][1])


	
								