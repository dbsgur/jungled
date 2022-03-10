#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) (((a) > (b)) ? (b) : (a))

int main()
{
  int n, i;
  int *dp;
  scanf("%d", &n);
  dp = (int *)malloc(sizeof(int) * (n + 1));
  for (i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 == 0)
    {
      dp[i] = MIN(dp[i], dp[i / 2] + 1);
    }
    if (i % 3 == 0)
    {
      dp[i] = MIN(dp[i], dp[i / 3] + 1);
    }
  }
  printf("%d\n", dp[n]);
  free(dp);
  return 0;
}