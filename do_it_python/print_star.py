# * 를 n개 출력하되  w개 마다 줄바꿈

n = int(input('certain ?'))
w = int(input('certain line break?'))


for _ in range(n // w):
    print('*' * w)

rest = n % w
if rest:
    print('*' * rest)
