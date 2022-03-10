import sys

input = sys.stdin.readline

# 오름 차순 정렬
# num[n] += num[n-1]

n = int(input().strip())


nums = list(map(int, input().split()))

nums.sort()

for i in range(1, n):
    nums[i] += nums[i-1]

print(sum(nums))
