import sys

input = sys.stdin.readline

n = int(input().strip())

score = [0]

for _ in range(n):
    score.append(int(input().strip()))

if n == 1:
    print(score[1])
else:
    dp = [0] * (n+1)
    dp[1] = score[1]
    dp[2] = score[1] + score[2]
    for i in range(3, n+1):
        dp[i] = max(dp[i-2] + score[i], score[i]+score[i-1]+dp[i-3])

    print(dp[n])
