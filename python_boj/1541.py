import sys

input = sys.stdin.readline

exps = input().split('-')

num = []

for exp in exps:
    cnt = 0
    s = exp.split('+')
    for i in s:
        cnt += int(i)
    num.append(cnt)

n = num[0]
for i in range(1, len(num)):
    n -= num[i]

print(n)
