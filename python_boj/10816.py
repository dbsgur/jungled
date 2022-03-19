# GENIOUS?...

import sys

input = sys.stdin.readline

N = int(input())

A = sorted(list(map(int, input().split())))

M = int(input())

B = list(map(int, input().split()))

hashmap = {}

for a in A:
    if a in hashmap:
        hashmap[a] += 1
    else:
        hashmap[a] = 1

print(' '.join(str(hashmap[b]) if b in hashmap else '0' for b in B))
