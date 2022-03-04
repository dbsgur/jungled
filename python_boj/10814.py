import sys

# 나이, 먼저 가입 순

n = int(sys.stdin.readline())

members = []
for idx in range(n):
    # 변수에 idx추가하고
    age, name = map(str, sys.stdin.readline().split())
    age = int(age)
    # 넣어
    members.append((age, name, idx))

members.sort(key=lambda x: (x[0], x[2]))

for member in members:
    print(member[0], member[1])
    # sys.stdout.write(member[0]+'\n')
    # sys.stdout.write(member[1])

# sort

# !! sys.stdout.write 는 int형은 출력 못한다. 원래 안되는건가 ????
