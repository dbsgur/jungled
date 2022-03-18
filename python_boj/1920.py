import sys

input = sys.stdin.readline

N = int(input().strip())

A = list(map(int, input().split()))


M = int(input().strip())

B = list(map(int, input().split()))


A.sort()
B.sort()
