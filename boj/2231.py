import sys

n = int(sys.stdin.readline().strip())


for i in range(1, n+1):
    num = sum((map(int, str(i))))  # i의 각 자릿수 더하기
    num_sum = i + num  # 분해합 = 생성자 + 각 자릿수의 합
    # i가 작은 수부터 차례로 들어가므로 처음으로 분해합과 입력값이 같을 때가 가장 작은 생성자를 가진다.
    if num_sum == n:
        print(i)
        sys.exit(0)
    if i == n:
        print(0)
