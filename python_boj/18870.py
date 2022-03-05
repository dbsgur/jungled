import sys

n = int(sys.stdin.readline())

coList = list(map(int, sys.stdin.readline().split()))
# 중복 제거
coList_sort = sorted(list(set(coList)))

# 시간 단축을 위해 딕셔너리 인덱싱 사용
dic = {coList_sort[i]: i for i in range(len(coList_sort))}

for co in coList:
    print(dic[co], end=' ')

print()
# time excess

# import sys

# # 절대값 구하기

# # 비교하기

# n = int(sys.stdin.readline())

# coList = list(map(int, sys.stdin.readline().split()))

# coList_sort = sorted(list(set(coList)))

# for coordinate in coList:
#     print(coList_sort.index(coordinate), end=' ')

# print()
