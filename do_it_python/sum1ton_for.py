# 1~ n까지의 합

print('1부터 n까지의 정수의 합을 구합니다.')
n = int(input('please enter n'))

sum = 0
for i in range(1, n+1):
    sum += i

print(f'1부터 {n}까지의 정수의 합은 {sum}이다.')

# 가우스 공식
# sum = n * (n+1) // 2
