<<<<<<< Updated upstream
def subCount(arr, n, k):

    mod = []
    for i in range(k + 1):
        mod.append(0)
    cumSum = 0
    for i in range(n):
        cumSum = cumSum + arr[i]
        mod[((cumSum % k)+k) % k] = mod[((cumSum % k)+k) % k] + 1

    result = 0  # Initialize result

    for i in range(k):
        if (mod[i] > 1):
            result = result + (mod[i]*(mod[i]-1))//2
    result = result + mod[0]

    return result


n, k = list(map(int, input().split()))
x = list(map(int, input().split()))

print(subCount(x, n, k))
=======
def subCount(arr, n, k):

    mod = []
    for i in range(k + 1):
        mod.append(0)
    cumSum = 0
    for i in range(n):
        cumSum = cumSum + arr[i]
        mod[((cumSum % k)+k) % k] = mod[((cumSum % k)+k) % k] + 1

    result = 0  # Initialize result

    for i in range(k):
        if (mod[i] > 1):
            result = result + (mod[i]*(mod[i]-1))//2
    result = result + mod[0]

    return result


n, k = list(map(int, input().split()))
x = list(map(int, input().split()))

print(subCount(x, n, k))
>>>>>>> Stashed changes
