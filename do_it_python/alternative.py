# + & - 번갈아 출력하기

print('+ - 번갈아 출력')
n = int(input('몇개 출력 ?'))

for _ in range(n // 2):
    print('+-', end='')
if n % 2:
    print('+', end='')


print()
