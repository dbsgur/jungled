from sys import stdin

n = int(stdin.readline())

a = []

for i in range(n):
    x = int(stdin.readline())
    a.append(x)

a.sort()

for i in a:
    print(i)
