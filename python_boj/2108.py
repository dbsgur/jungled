import sys
from collections import Counter

cnt = int(sys.stdin.readline())
numbers = []

for i in range(cnt):
    num = int(sys.stdin.readline())
    numbers.append(num)

if cnt == 1:
    print(numbers[0], numbers[0], numbers[0], 0, sep='\n')

else:
    numbers.sort()
    mode = Counter(numbers).most_common(2)

    print(round(sum(numbers)/cnt))
    print(numbers[cnt//2])
    if mode[0][1] == mode[1][1]:
        print(mode[1][0])
    else:
        print(mode[0][0])
    print(max(numbers) - min(numbers))
