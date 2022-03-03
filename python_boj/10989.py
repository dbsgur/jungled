import sys

n = int(sys.stdin.readline())

check_list = [0] * 10001

for i in range(n):
    input_num = int(sys.stdin.readline())

    check_list[input_num] += 1


for i in range(10001):
    if check_list[i]:
        # print(i)
        for j in range(check_list[i]):
            print(i)


# 파이썬은 내부적으로 연산과 메모리를 관리하기 때문에 파이썬에 내장되어 있는
# 함수들을 적용할수록 메모리를 효율적으로 관리할 수 있다.
