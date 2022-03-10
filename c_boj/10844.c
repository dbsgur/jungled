#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, j;
  long long int sum = 0;
  // long long int -> int 해도 된다.
  long long int **dp;
  scanf("%d", &n);
  dp = (long long int **)malloc(sizeof(long long int *) * (n + 1));
  for (i = 0; i < n + 1; i++)
  {
    dp[i] = (long long int *)malloc(sizeof(long long int) * 10);
  }
  for (i = 1; i < 10; i++)
  {
    dp[1][i] = 1;
  }

  for (i = 2; i <= n; i++)
  {
    for (j = 0; j < 10; j++)
    {
      if (j == 0)
      {
        dp[i][j] = dp[i - 1][1];
      }
      else if (j == 9)
      {
        dp[i][j] = dp[i - 1][8];
      }
      else
      {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
      }
      dp[i][j] %= 1000000000;
    }
  }
  for (i = 0; i < 10; i++)
  {
    sum += dp[n][i];
  }
  printf("%lld\n", sum % 1000000000);
  for (i = 0; i < n + 1; i++)
  {
    free(dp[i]);
  }
  free(dp);
  return 0;
}