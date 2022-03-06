import sys

graph = []
blank = []

for i in range(9):
    graph.append(list(map(int, sys.stdin.readline().strip().split())))

# 빈칸 정보를 blanck에 넣는다.
for i in range(9):
    for j in range(9):
        if graph[i][j] == 0:
            blank.append((i, j))

# 행 확인 > a의 값이 x행에 있는지 확인


def checkRow(x, a):
    for i in range(9):
        if a == graph[x][i]:
            return False
    return True


# 열 확인 > a의 값이 y행에 있는지 확인
def checkCol(y, a):
    for i in range(9):
        if a == graph[i][y]:
            return False
    return True

# 3 x 3확인 > a의 값이 3x3안에 있는지 확인


def checkRect(x, y, a):
    nx = x//3*3
    ny = y//3*3
    for i in range(3):
        for j in range(3):
            if a == graph[nx+i][ny+j]:
                return False
    return True


def dfs(idx):
    if idx == len(blank):
        for i in range(9):
            print(*graph[i])
        # return
        exit(0)

    for i in range(1, 10):
        x = blank[idx][0]
        y = blank[idx][1]

        if checkRow(x, i) and checkCol(y, i) and checkRect(x, y, i):
            graph[x][y] = i
            dfs(idx+1)
            graph[x][y] = 0


dfs(0)
