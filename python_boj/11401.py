import sys

input = sys.stdin.readline

n, k = map(int, input().split())


def fac(a, b):
    result = 1
    for i in range(a, b+1):
        result *= i
    return result


def bin(N, K):
    if K < 0 or K > N:
        return 0
    else:
        return fac(N-K+1, N) / fac(1, K)


realResult = bin(n, k) % 1000000007

print("%1d" % realResult)

# fucking OVER TIME ㅗ
