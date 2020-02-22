def load_input():
    line_1 = input().split()
    N, K = int(line_1[0]), int(line_1[1])
    arr = [int(i) for i in input().split()]
    return N, K, arr

def solution(K, N, arr):
    count = 0
    for i in range(N):
        tong = 0
        for j in range(i, N):
            tong += arr[j]
            if tong % K == 0:
                count += 1
    print(count)

if __name__ == '__main__':
    N, K, arr = load_input()
    solution(K, N, arr)