# 배열 원소의 최댓값을 구해서 출력(원소 값은 난수)

import random
from max import max_of


print('best of randoms')
num = int(input('randoms numbers ? '))
lo = int(input('randoms minimum ? '))
hi = int(input('randoms maximum ? '))
x = [None] * num

for i in range(num):
    x[i] = random.randint(lo, hi)

print(f'{(x)}')
print(f'MAXIMUN : {max_of(x)}')
