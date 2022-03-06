import sys

N, M = map(int, sys.stdin.readline().split())

visited = [0 for _ in range(N)]

arr = []


def dfs(cnt):
    if cnt == M:
        print(*arr)
        return

    for i in range(N):
        if visited[i] == 0:
            arr.append(i+1)

            dfs(cnt+1)  # next level find
            visited[i] = 1

            arr.pop()  # 탐사한 내용 제거
            # 시작 탐색 값만 제외시키도록 나머진 초기화
            for j in range(i+1, N):
                visited[j] = 0


dfs(0)
