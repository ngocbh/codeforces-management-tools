def subCount(arr, n, k): 
	mod =[] 
	for i in range(k + 1): 
		mod.append(0) 
	cumSum = 0
	for i in range(n): 
		cumSum = cumSum + arr[i] 
		mod[((cumSum % k)+k)% k]= mod[((cumSum % k)+k)% k] + 1
	result = 0 
	for i in range(k): 
		if (mod[i] > 1): 
			result = result + (mod[i]*(mod[i]-1))//2
	result = result + mod[0] 
	
	return result 

if __name__ == "__main__":
    data = input().split()
    n = int(data[0])
    k = int(data[1])
    arr = input().split()
    arr = [int(i) for i in arr]
    print(subCount(arr, n, k)) 
     