import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())

queue = deque([i for i in range(n, 0, -1)])

result = []
# print(queue)

while len(queue) > 0:
    for i in range(k-1):
        # queue.pop()
        queue.appendleft(queue.pop())
    result.append(queue.pop())

print("<", end='')
print(*result, sep=', ', end='')
print(">")
