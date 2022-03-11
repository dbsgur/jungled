import sys

input = sys.stdin.readline

n = int(input().strip())

arr = list(map(int, input().split()))

arr.sort()

# result = 1
m = n // 2

if(n % 2 == 0):
    result = arr[m] * arr[m-1]
else:
    result = arr[m] * arr[m]

print(result)
print("n : ", n)
print("m : ", m)
print("arr : ", arr)
