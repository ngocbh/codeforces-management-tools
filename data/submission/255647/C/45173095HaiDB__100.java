n = int(input())

khach = [0, 1, 2]
tho = [0, 1, 2]
khach.clear()
tho.clear()
i=0
while(i < n):
	k = int(input())
	tho.append(k)
	i = i+1

i=0
while(i < n):
	k = int(input())
	khach.append(k)
	i = i+1

khach.sort()
tho.sort()

t = 0
i=0
while(i<n):
	t = t + (khach[i] - tho[i])*(khach[i] - tho[i])
	i = i+1
print(t)