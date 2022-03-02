import sys
import heapq

# heap
n = int(sys.stdin.readline())
l = []
for _ in range(n):
    m = int(sys.stdin.readline())
    heapq.heappush(l, m)

for _ in range(n):
    print(heapq.heappop(l))

# n = int(sys.stdin.readline())

# l = []

# for i in range(n):
#     l.append(int(sys.stdin.readline()))

# for i in sorted(l):
#     sys.stdout.write(str(i)+'\n')

# python heapq, sort 둘다 O(n logN)이다.
# 그러나 heap가 더 빠르다.
