import sys

input = sys.stdin.readline

n = int(input().strip())

tree = []

for i in range(n):
    tree.append(list(map(int, input().strip().split())))

k = 2
for i in range(1, n):
    for j in range(k):
        if j == 0:
            tree[i][j] = tree[i][j] + tree[i-1][j]
        elif i == j:
            tree[i][j] = tree[i][j] + tree[i-1][j-1]
        else:
            tree[i][j] = max(tree[i-1][j-1], tree[i-1][j]) + tree[i][j]
    k += 1

print(max(tree[n-1]))
