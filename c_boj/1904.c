#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i;
  scanf("%d", &n);
  int a = 1, b = 2, c = 0;
  for (i = 3; i <= n; i++)
  {
    c = (a + b);
    a = b;
    b = c;
    // d = c % 15746;
    // c = (a + b) % 15746;
  }
  c = c % 15746;
  printf("%d\n", c);
  // int n, i;
  // int dp1[1000001];
  // int *dp2;
  // dp1[1] = 1;
  // dp1[2] = 2;
  // scanf("%d", &n);
  // dp2 = (int *)calloc(n + 1, sizeof(int));
  // dp2[1] = 1;
  // dp2[2] = 2;
  // for (i = 3; i <= n; i++)
  // {
  //   dp2[i] = (dp2[i - 1] + dp2[i - 2]) % 15746;
  // }
  // printf("%d\n", dp2[n]);
  // free(dp2);
  // int dp[1000001] = {
  //     0,
  // };
  // dp[1] = 1;
  // dp[2] = 2;
  // scanf("%d", &n);
  //members = (Member *)calloc(n + 1, sizeof(Member));
  // dp[] = (int *)calloc(n + 1, sizeof(int));
  // for (i = 3; i <= n; i++)
  // {
  //   dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  // }
  // printf("%d\n", dp[n]);
  return 0;
}