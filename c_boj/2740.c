#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n, m, i, j, k;
  scanf("%d %d", &n, &m);
  int a[n][m];
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  int w, v;
  scanf("%d %d", &w, &v);
  int b[w][v];
  for (i = 0; i < w; i++)
  {
    for (j = 0; j < v; j++)
    {
      // 음수를 문자열로 받구나!!! 시발!!왜????????
      // 아닌듯 ?... 근데 왜 -1 * 1 = 431489227????
      scanf("%d", &b[i][j]);
    }
  }
  // int c[n][v];
  int sum;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < v; j++)
    {
      sum = 0;
      for (k = 0; k < m; k++)
      {
        sum += (a[i][k] * b[k][j]);
        // printf("i : %d, j: %d, k = %d", i, j, k);
        // printf("a[i][k] : %d ", a[i][k]);
        // printf("b[k][j] : %d ", b[k][j]);
        // printf("\n###########\n");
        // c[i][j] += a[i][k] * b[k][j];
        // printf("\nc[%d][%d] : %d ", i, j, c[i][j]);
      }
      printf("%d ", sum);
      // printf("\nc[%d][%d] : %d ", i, j, c[i][j]);
    }
    printf("\n");
  }

  // for (i = 0; i < n; i++)
  // {
  //   for (j = 0; j < v; j++)
  //   {
  //     printf("%d ", c[i][j]);
  //   }
  //   printf("\n");
  // }
  return 0;
}
