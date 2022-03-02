import sys

n = int(sys.stdin.readline())

stack = []

for i in range(n):
    command = sys.stdin.readline().split()
    # push
    if command[0] == 'push':
        stack.append(command[1])
    # pop
    elif command[0] == 'pop':
        # stack.pop() ? print(stack.pop()) : print("-1")
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    # size
    elif command[0] == 'size':
        print(len(stack))
    # empty
    elif command[0] == 'empty':
        if len(stack) == 0:
            print("1")
        else:
            print("0")

    # top
    else:
        if len(stack) == 0:
            print("-1")
        else:
            print(stack[-1])
