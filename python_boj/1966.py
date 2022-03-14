import sys

input = sys.stdin.readline
# Question ?! 아래 풀이가 시간 복잡도 개 스레기일거같은디여

test_cases = int(input().strip())

for _ in range(test_cases):
    n, m = map(int, input().split())
    imp = list(map(int, input().split()))
    idx = list(range(len(imp)))
    idx[m] = 'target'

    # 순서
    order = 0

    while True:
        # 첫번째 if: imp의 첫번째 값 = 최댓값?
        if imp[0] == max(imp):
            order += 1

            # 두번째 if: idx의 첫 번째 값 = "target"?
            if idx[0] == 'target':
                print(order)
                break
            else:
                imp.pop(0)
                idx.pop(0)

        else:
            imp.append(imp.pop(0))
            idx.append(idx.pop(0))
