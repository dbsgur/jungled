# Heap Sort
# O(n log n)

from typing import MutableSequence


def heap_sort(a: MutableSequence) -> None:

    def down_heap(a: MutableSequence, left: int, right: int) -> None:
        temp = a[left]  # 루트

        parent = left

        while parent < (right + 1) // 2:
            cl = parent * 2 + 1  # left child
            cr = cl + 1  # right child

            child = cr if cr <= right and a[cr] > a[cl] else cl  # 큰 값 선택

            if temp >= a[child]:
                break

            a[parent] = a[child]
            parent = child
        a[parent] = temp

    n = len(a)

    for i in range((n-1) // 2, -1, -1):  # a[i] ~ a[n-1]을 힙으로 만들기
        a[0], a[i] = a[i], a[0]  # 최대값인 a[0]과 마지막 원소 교환
        down_heap(a, 0, i-1)  # a[0] ~ a[i-1]을 힙으로 만들기


if __name__ == '__main__':
    print('힙 정렬을 수행합니다.')
    num = int(input('원소 수를 입력하세요. : '))
    x = [None] * num

    for i in range(num):
        x[i] = int(input(f'x[{i}] : '))

    heap_sort(x)

    print('오름차순으로 정렬되었음.')

    for i in range(num):
        print(f'x[{i}] : {x[i]}')
