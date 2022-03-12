# deque의 popleft()와 appendleft(x) 메서드는 모두 0(1)의 시간 복잡도를 가진다.
# list의 pop(0)과 insert(0,x) 대비 성능 상에 큰 이점을 가지므로
# 큐를 구현할 때는 list보다는 deque를 사용하도록 하자.

import sys
from collections import deque

input = sys.stdin.readline

n = int(input().strip())

# for i in range(n):
#   commands = int(input().strip())
commands = [input().strip() for _ in range(n)]

queue = deque([])

length = len(queue)

for command in commands:
    # pop
    if command == 'pop':
        if length == 0:
            print("-1")
        else:
            print(queue.pop())
            length -= 1
    # size
    elif command == 'size':
        print(length)
        # print(len(queue))
    # empty
    elif command == 'empty':
        if length:
            print("0")
        else:
            print("1")
    # front
    elif command == 'front':
        if length == 0:
            print("-1")
        else:
            print(queue[length-1])
    # back
    elif command == 'back':
        if length == 0:
            print("-1")
        else:
            print(queue[0])
    # push X
    else:
        num = list(command.split())[1]
        queue.appendleft(num)
        length += 1
