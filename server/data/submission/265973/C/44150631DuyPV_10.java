n = int(input())

def f(n):
	if n == 1:
		return 1
	if n == 2:
		return 4
	return f(n-1)*3

print(f(n))			