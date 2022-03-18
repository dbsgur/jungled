import sys

input = sys.stdin.readline

N = int(input().strip())

quad = [list(map(int, input().split())) for _ in range(N)]

cntZero = 0
cntMinusOne = 0
cntOne = 0

# print(type(quad[0][6]))


def cut(x, y, n):
    global cntMinusOne, cntOne, cntZero
    number = quad[x][y]
    for i in range(x, x+n):
        # if n == 1: break
        for j in range(y, y+n):
            if number != quad[i][j]:
                n //= 3
                for k in range(3):
                    for l in range(3):
                        cut(x + (n*k), y + (n*l), n)
                return
                # cut(x, y, n)
                # cut(x, y+n, n)
                # cut(x, y+(2*n), n)

                # cut(x+n, y, n)
                # cut(x+n, y+n, n)
                # cut(x+n, y+(2*n), n)

                # cut(x+(2*n), y, n)
                # cut(x+(2*n), y+n, n)
                # cut(x+(2*n), y+(2*n), n)

                # break가 아니라 return
                # return

    if number == -1:
        # print("### number - 1 ###")
        cntMinusOne += 1
    elif number == 0:
        # print("### number 0 ###")
        # print(x, y, n)
        cntZero += 1
    else:
        # print("### number + 1 ###")
        cntOne += 1


cut(0, 0, N)

print(cntMinusOne)
print(cntZero)
print(cntOne)


# 3
# 0 1 1
# 1 0 0
# -1 -1 -1
