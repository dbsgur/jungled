import sys

input = sys.stdin.readline

n = int(input().strip())


dis = list(map(int, input().split()))

liters = list(map(int, input().split()))


m = liters[0]
result = dis[0] * m
dist = 0

for i in range(1, n-1):
    if liters[i] < m:
        result += m * dist
        dist = dis[i]
        m = liters[i]
    else:
        dist += dis[i]
    if i == (n-2):
        result += (m*dist)

print(result)
