import sys

input = sys.stdin.readline

while True:
    n, m = map(int, input().split())

    if n == 0 & m == 0:
        break
    if (n % m == 0):
        print("multiple")
    elif(m % n == 0):
        print("factor")
    else:
        print('neither')
