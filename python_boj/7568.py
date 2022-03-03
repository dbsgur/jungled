import sys

N = int(sys.stdin.readline())
# N = int(input('입력 : '))
people = []

for i in range(N):
    x, y = map(int, sys.stdin.readline().split(" "))
    # x, y = map(int, input(" :").split(' '))
    people.append([x, y])

for i in people:
    rank = 1
    for j in people:
        if i != j:
            if i[0] < j[0] and i[1] < j[1]:
                rank += 1
    print(rank, end=" ")
    # end 빼면 정답이다. 그러나 붙히면 %가 같이 나와서 오답처리가 된다 이유가 뭐지 ??????
    # people[i][2] = rank
print()


# for man in people:
#     print(man[2], end=" ")
# print(f'{man[2]:2}')

# print(people)
