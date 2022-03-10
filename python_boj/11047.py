import sys

input = sys.stdin.readline

n, m = map(int, input().split())

nums = []
# nums = [0 for _ in range(n)]
# who better fast?

for i in range(n):
    nums.append(int(input().strip()))

count = 0

nums.sort(reverse=True)

for num in nums:
    if(m == 0):
        break
    if(num > m):
        continue
    count += (m//num)
    m %= num

print(count)
