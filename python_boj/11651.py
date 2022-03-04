import sys

n = int(sys.stdin.readline())

so = []

for i in range(n):
    so.append(list(map(int, sys.stdin.readline().split())))

so.sort(key=lambda x: (x[1], x[0]))

for i in so:
  # 예가 제일 빠름!!
    print(f'{i[0]} {i[1]}')
    # print(i[0], i[1])

    # print(f'{so[i][0]} {so[i][1]}')
