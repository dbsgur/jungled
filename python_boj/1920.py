import sys

input = sys.stdin.readline

N = int(input().strip())

A = sorted(list(map(int, input().split())))


M = int(input().strip())

B = list(map(int, input().split()))


# l in B
def binarySearch(l, A, start, end):
    if start > end:
        return 0
    middle = (start + end) // 2
    if l == A[middle]:
        return 1
    elif l > A[middle]:
        return binarySearch(l, A, middle+1, end)
    else:
        return binarySearch(l, A, start, middle-1)


for l in B:
    print(binarySearch(l, A, 0, N-1))
