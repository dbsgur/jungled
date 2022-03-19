import sys
import heapq

input = sys.stdin.readline

heap = []

# N : 연산의 갯수
N = int(input())

for _ in range(N):
    num = int(input())
    if num != 0:
        heapq.heappush(heap, num)
    else:
        if(len(heap) == 0):
            print("0")
            continue
        print(heapq.heappop(heap))
