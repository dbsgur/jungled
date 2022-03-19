import sys

input = sys.stdin.readline

# N : amount of tree // M : want tree height
N, M = map(int, input().split())

trees = list(map(int, input().split()))

# print(trees)

start, end = 1, max(trees)

while(start <= end):
    height = 0
    mid = (start + end) // 2
    for tree in trees:
        if height > M:
            break
        if tree > mid:
            height += (tree - mid)
        else:
            continue
    if height >= M:
        start = mid+1
    else:
        end = mid - 1


print(end)
