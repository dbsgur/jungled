import sys

zero = [1, 0, 1]
one = [0, 1, 1]


def fibonacci(num):
    length = len(zero)
    if num >= length:
        for i in range(length, num+1):
            zero.append(zero[i-1] + zero[i-2])
            one.append(one[i-1] + one[i-2])
    # print('{} {}'.format(zero[num], one[num]))
    print(f'{zero[num]} {one[num]}')


N = int(sys.stdin.readline())

for _ in range(N):
    fibonacci(int(sys.stdin.readline()))
