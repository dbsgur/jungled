import sys
from math import gcd
from math import sqrt

input = sys.stdin.readline

n = int(input().strip())

arr = []

for i in range(n):
    arr.append(int(input().strip()))

arr.sort()
interval = []
ans = []

for i in range(1, n):
    interval.append(arr[i] - arr[i-1])

prev = interval[0]
for i in range(1, len(interval)):
    prev = gcd(prev, interval[i])

for i in range(2, int(sqrt(prev)) + 1):  # 제곱근까지만 검색
    if prev % i == 0:
        ans.append(i)
        ans.append(prev//i)

ans.append(prev)
ans = list(set(ans))  # / w
ans.sort()
print(*ans)
