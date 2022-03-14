import sys
from collections import deque

input = sys.stdin.readline

N = int(input().strip())

dq = deque()


def empty():
    if len(dq) == 0:
        return 1
    else:
        return 0


for i in range(N):
    cmd = list(input().split())

    if cmd[0] == 'push_front':
        dq.appendleft(cmd[1])
    elif cmd[0] == 'push_back':
        dq.append(cmd[1])

    elif cmd[0] == 'pop_front':
        if empty() == 1:
            print("-1")
        else:
            print(dq.popleft())

    elif cmd[0] == 'pop_back':
        if empty() == 1:
            print("-1")
        else:
            print(dq.pop())

    elif cmd[0] == 'size':
        print(len(dq))
        # ?

    elif cmd[0] == 'empty':
        if empty() == 1:
            print("1")
        else:
            print("0")

    elif cmd[0] == 'front':
        if empty() == 1:
            print("-1")
        else:
            print(dq[0])

    elif cmd[0] == 'back':
        if empty() == 1:
            print("-1")
        else:
            print(dq[len(dq)-1])
