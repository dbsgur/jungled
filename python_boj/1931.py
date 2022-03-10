import sys

input = sys.stdin.readline

n = int(input())

s = []

for _ in range(n):
    start, end = map(int, input().split())
    s.append([start, end])

# s = sorted(s, key=lambda a: (a[0], a[1]))
# [[0, 6], [1, 4], [2, 13], [3, 5], [3, 8], [5, 7], [5, 9], [6, 10], [8, 11], [8, 12], [12, 14]]

# s = sorted(s, key=lambda a: a[0])
# s = sorted(s, key=lambda a: a[1])
# [[1, 4], [3, 5], [0, 6], [5, 7], [3, 8], [5, 9], [6, 10], [8, 11], [8, 12], [2, 13], [12, 14]]
# 위 아래 동일 결과
s = sorted(s, key=lambda a: (a[1], a[0]))

last = 0
count = 0

for start, end in s:
    if start >= last:
        count += 1
        last = end


print(count)
