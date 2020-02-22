n = int(input())
tree = [0]
tree.append(1)
tree.append(4)
for i in range(3, n + 1):
    temp = (4*tree[i - 1] - tree[i - 2])%1000000007
    tree.append(temp)
print(tree[n]%1000000007)