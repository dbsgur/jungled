#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int min(a, b)
{
  return a > b ? b : a;
}

int main()
{
  int n, i;
  int **costs;
  scanf("%d", &n);
  costs = (int **)calloc(n, sizeof(int *));
  for (i = 0; i < n; i++)
  {
    costs[i] = (int *)calloc(3, sizeof(int));
    scanf("%d %d %d", &costs[i][0], &costs[i][1], &costs[i][2]);
  }
  // for (i = 0; i < n; i++)
  // {
  //   // scanf("%s", costs);
  //   scanf("%d %d %d", &costs[i][0], &costs[i][1], &costs[i][2]);
  // }
  for (i = 1; i < n; i++)
  {
    costs[i][0] = min(costs[i - 1][1], costs[i - 1][2]) + costs[i][0];
    costs[i][1] = min(costs[i - 1][0], costs[i - 1][2]) + costs[i][1];
    costs[i][2] = min(costs[i - 1][1], costs[i - 1][0]) + costs[i][2];
  }
  printf("%d", min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2])));
  free(costs);
  return 0;
}