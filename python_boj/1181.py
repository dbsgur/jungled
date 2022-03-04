import sys

n = int(sys.stdin.readline())

so = []

for i in range(n):
    so.append(sys.stdin.readline().strip())

set_so = set(so)  # 중복 제거
so = list(set_so)  # 다시 리스트로 변환

so.sort()
so.sort(key=len)

# so.sort(key=lambda x: (len(x), x))
# !!!! 예상외로 람다가 더 느리다!!!!!!! 메모리도 많이 먹는다!!!

for i in so:
    print(i)


# sort -> lambda len(),
