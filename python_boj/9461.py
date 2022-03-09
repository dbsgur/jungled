import sys
# import time

# start = time.time()
input = sys.stdin.readline

N = int(input().strip())

arr = []

print("Arr : ", arr)

for i in range(N):
    arr.append(int(input().strip()))

# print(max(arr))

max = max(arr) + 1

wh = [0 for i in range(max)]

wh[1] = 1
wh[2] = 1
wh[3] = 1

for i in range(0, max-3):
    wh[i+3] = wh[i] + wh[i+1]

for num in arr:
    print(wh[num])

print("Arr : ", arr)

# # 이게 훨~~ 씬 빠르다.
# wh = [0 for i in range(101)]
# # wh = [0] * 101

# wh[1] = 1
# wh[2] = 1
# wh[3] = 1

# N = int(input().strip())

# for i in range(0, 98):
#     wh[i+3] = wh[i] + wh[i+1]

# for i in range(N):
#     n = int(input().strip())
#     print(wh[n])

# print("time : ", time.time() - start)
