import sys


def logic(n):
    if n == N:
        global count
        count += 1
    else:
        for i in range(N):
            if visited[i]:
                continue
            board[n] = i  # (n, i)에 퀸 놓기

            if check(n):  # 퀸 놓기 조건에 맞다면
                visited[i] = True
                logic(n+1)  # 다음 행으로 넘어가기
                visited[i] = False


def check(n):
    for i in range(n):
        if (board[n] == board[i]) or (n-i == abs(board[n] - board[i])):
            return False

    return True


if __name__ == '__main__':
    N = int(sys.stdin.readline())
    count = 0
    board = [0 for _ in range(N)]  # 인덱스 번호 == 행, 인덱스 값 ==열
    visited = [False for _ in range(N)]

    logic(0)
    print(count)


# 시간 초과 이유 모르겟음 ;
# import sys

# n = int(sys.stdin.readline())

# ans = 0
# row = [0] * n


# def is_promising(x):
#     for i in range(x):
#         if row[x] == row[i] or abs(row[x] - row[i]) == abs(x-i):
#             return False
#     return True


# def n_queens(x):
#     global ans
#     if x == n:
#         ans += 1
#     else:
#         for i in range(n):
#             # [x, i]에 퀸을 놓음
#             row[x] = i
#             if is_promising(x):
#                 n_queens(x+1)


# if __name__ == '__main__':
#     n_queens(0)
#     print(ans)
