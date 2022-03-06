import sys

n, m = map(int, sys.stdin.readline().split())

arr = []


def dfs(cnt):
    # print(n, m, cnt)
    if cnt == m:
        print(*arr)
        return
    for i in range(n):
        arr.append(i+1)
        dfs(cnt+1)
        arr.pop()


dfs(0)

# visited = [0 for _ in range(N)] arr = [] def dfs(cnt): if cnt == M: print(*arr) return for i in range(N): arr.append(i+1) dfs(cnt+1) # 다음 깊이 탐색 arr.pop() # 탐사한 내용 제거 dfs(0)
# N, M = map(int, input().split())

# arr = []


# def dfs(cnt):
#     if cnt == M:
#         print(*arr)
#         return
#     for i in range(N):
#         arr.append(i+1)
#         dfs(cnt+1)
#         arr.pop()


# dfs(0)
