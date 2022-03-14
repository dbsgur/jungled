import sys
from collections import deque

input = sys.stdin.readline

n = int(input().strip())

for i in range(n):
    commands = list(input())
    amount = int(input().strip())
    arr = input().strip()[1:-1].split(",")
    # print('arr : ', arr)
    queue = deque(arr)

    flag, rev, front, back = 0, 0, 0, len(queue)-1

    if amount == 0:
        queue = []
        front = 0
        back = 0

    for command in commands:
        if command == 'R':
            rev += 1
        elif command == 'D':
            if len(queue) < 1:
                flag = 1
                print("error")
                break
            else:
                if rev % 2 == 0:
                    queue.popleft()
                else:
                    queue.pop()
    if flag == 0:
        if rev % 2 == 0:
            print("["+",".join(queue)+"]")
        else:
            queue.reverse()
            print("["+",".join(queue)+"]")
