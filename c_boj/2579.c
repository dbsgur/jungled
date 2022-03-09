#include <stdio.h>
#include <stdlib.h>
// ??? 도대체 이게 왜틀림???????
int max(int a, int b)
{
  return (a > b ? a : b);
}

int main()
{
  int n, i;
  int *score;
  int *dp;

  scanf("%d", &n);
  score = (int *)malloc(sizeof(int) * n);
  dp = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &score[i]);
  }
  if (n == 1)
  {
    printf("%d\n", score[0]);
  }
  else
  {
    dp[0] = score[0];
    dp[1] = score[0] + score[1];
    dp[2] = max(score[0] + score[2], score[1] + score[2]);
    for (i = 3; i < n; i++)
    {
      dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i] + score[i - 1]);
    }
    printf("%d\n", dp[n - 1]);
  }

  free(score);
  free(dp);
  return 0;
}