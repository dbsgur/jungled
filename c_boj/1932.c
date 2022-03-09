#include <stdio.h>
#include <stdlib.h>

int max(a, b)
{
  return (a > b ? a : b);
}

int main()
{
  int n, i, j;
  int **tree;

  scanf("%d", &n);
  tree = (int **)calloc(n, sizeof(int *));
  for (i = 0; i < n; i++)
  {
    tree[i] = (int *)calloc(n, sizeof(int));
    for (j = 0; j <= i; j++)
    {
      scanf("%d", &tree[i][j]);
    }
  }
  // n == 1일 경우 예외처리?
  for (i = 1; i < n; i++)
  {
    for (j = 0; j <= i; j++)
    {
      if (j == 0)
      {
        tree[i][j] = tree[i - 1][j] + tree[i][j];
      }
      else if (i == j)
      {
        tree[i][j] = tree[i - 1][j - 1] + tree[i][j];
      }
      else
      {
        tree[i][j] = max(tree[i - 1][j - 1], tree[i - 1][j]) + tree[i][j];
      }
    }
  }
  int result = tree[n - 1][0];
  for (i = 0; i < n; i++)
  {
    if (tree[n - 1][i] > result)
      result = tree[n - 1][i];
  }
  printf("%d", result);
  // printf();
  return 0;
}