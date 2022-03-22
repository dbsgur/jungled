import sys
import heapq

input = sys.stdin.readline

N = int(input())

commands = list(int(input()) for _ in range(N))

heap = []

for command in commands:
    if command != 0:
        heapq.heappush(heap, (abs(command), command))
    else:
        try:
            print(heapq.heappop(heap)[1])
        except:
            print(0)
