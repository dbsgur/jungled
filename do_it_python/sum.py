# a~b 까지의 정수의 합

print('a ~ b sum')
a = int(input('value a : '))
b = int(input('value b : '))

if a > b:
    a, b = b, a
sum = 0
for i in range(a, b+1):
    sum += i

print(f'{a} ~ {b} 의 합 : {sum}')
