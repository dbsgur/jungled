import sys
import heapq

input = sys.stdin.readline

# N : 연산의 갯수
N = int(input())

# x=0 -> print max(num)  + pop max(num)

# x>0 -> push num

heap = []

for _ in range(N):
    num = int(input())
    if num != 0:
        heapq.heappush(heap, (-num, num))
    else:
        if len(heap) == 0:
            print("0")
            continue
        print(heapq.heappop(heap)[1])
