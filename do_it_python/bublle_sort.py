# bubble sort 1
# O(n^2)

from typing import MutableSequence


def bubble_sort1(a: MutableSequence) -> None:
    n = len(a)
    for i in range(n-1):
        for j in range(n-1, i, -1):
            if a[j-i] > a[j]:
                a[j-1], a[j] = a[j], a[j-1]


if __name__ == '__main__':
    print('버블 정렬을 수행합니다.')
    num = int(input('원소 수를 입력하세요. : '))
    x = [None] * num

    for i in range(num):
        x[i] = int(input(f'x[{i}] : '))

    bubble_sort1(x)

    print('오름차순으로 정렬되었음.')
    for i in range(num):
        print(f'x[{i}] : {x[i]}')
