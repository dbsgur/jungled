import sys

input = sys.stdin.readline


def gcd(a, b):
    if(b == 0):
        return a
    return gcd(b, a % b)


# nums = list(map(int, input().split()))

# x = max(nums)
# y = min(nums)
n, m = map(int, input().split())

if (n >= m):
    x = n
    y = m
else:
    x = m
    y = n

print(gcd(x, y))
print((x*y)//gcd(x, y))
