import sys

input = sys.stdin.readline

# A[i][j] Matrix
i, j = map(int, input().split())

A = []
for _ in range(i):
    A.append(list(map(int, input().split())))

# B[i][j] Matrix
n, m = map(int, input().split())
B = []
for _ in range(n):
    B.append(list(map(int, input().split())))


C = [[0 for _ in range(m)] for _ in range(i)]

for x in range(i):
    for y in range(m):
        for z in range(j):
            C[x][y] += (A[x][z] * B[z][y])

for x in C:
    for y in x:
        print(y, end=' ')
    print()
