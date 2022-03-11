import sys

input = sys.stdin.readline


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


n = int(input().strip())

for i in range(n):
    x, y = map(int, input().split())
    # result = x*y // gcd(x, y)
    print(x*y // gcd(x, y))
