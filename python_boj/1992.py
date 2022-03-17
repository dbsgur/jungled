import sys

input = sys.stdin.readline

N = int(input().strip())

# quad = [input() for _ in range(N)]
quad = [list(map(int, input().strip())) for _ in range(N)]

# print(quad[0][1])


def cut(x, y, n):
    color = quad[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if color != quad[i][j]:
                color = -1
                break
    if color == -1:
        print("(", end='')
        cut(x, y, n//2)
        cut(x, y+n//2, n//2)
        cut(x+n//2, y, n//2)
        cut(x+n//2, y+n//2, n//2)
        print(")", end='')
    elif color == 1:
        print(1, end='')
    else:
        print(0, end='')


cut(0, 0, N)
