import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

positions = list(map(int, input().split()))

dq = deque([i for i in range(1, n+1)])

count = 0

for position in positions:
    while True:
        if dq[0] == position:
            dq.popleft()
            break
        else:
            # 뽑아야하는 수의 위치 인덱스가 dq의 길이를 반으로 나눈 것보다 적을때 왼족으로 움직여야 최소임
            if dq.index(position) < len(dq) / 2:
                while dq[0] != position:
                    dq.append(dq.popleft())
                    count += 1
            else:
                while dq[0] != position:
                    dq.appendleft(dq.pop())
                    count += 1


print(count)
