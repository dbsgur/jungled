import sys
from collections import deque

input = sys.stdin.readline

# 정점의 개수 N, 간선의 개수 M, 탐색을 시작할 정점의 번호 V
N, M, V = map(int, input().split())

# 위가 더 좋은 코드인듯


def dfs(n):
    print(n, end=' ')
    visited[n] = True
    for i in graph[n]:
        if not visited[i]:
            dfs(i)


def bfs(n):
    visited[n] = True
    queue = deque([n])
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)

# 인접 리스트 저장
for _ in range(M):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

# sort
for i in range(1, N+1):
    graph[i].sort()

dfs(V)

visited = [False] * (N+1)
print()
bfs(V)


# def bfs(v):
#     q = deque()
#     q.append(v)
#     visit_list[v] == 1
#     while q:
#         if visit_list[i] == 0 and graph[v][i] == 1:
#             q.append(i)
#             visit_list[i] = 1


# def dfs(v):
#     visit_list2[v] = 1
#     print(v, end=' ')
#     for i in range(1, N+1):
#         if visit_list2[i] == 0 and graph[v][i] == 1:
#             dfs(i)


# graph = [[0] * (N+1) for _ in range(N+1)]
# visit_list = [0] * (N+1)
# visit_list2 = [0] * (N+1)

# for _ in range(M):
#     x, y = map(int, input().split())
#     graph[x][y] = graph[y][x] = 1

# dfs(V)
# print()
# bfs(V)
