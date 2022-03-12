import sys

input = sys.stdin.readline

k = int(input().strip())

nums = []

for i in range(k):
    num = int(input().strip())
    if (num == 0):
        nums.pop()
        continue
    nums.append(num)

print(sum(nums))
