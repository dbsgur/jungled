#include <stdlib.h>
#include <stdio.h>

int gcd(a, b)
{
  return b == 0 ? a : gcd(b, a % b);
}

int main()
{
  int n, i;
  int x, y;
  scanf("%d", &n);
  int *result;
  result = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d %d", &x, &y);
    result[i] = (x * y) / gcd(x, y);
    // printf("%d\n", (x * y) / gcd(x, y));
  }
  for (i = 0; i < n; i++)
  {
    printf("%d\n", result[i]);
  }
  free(result);
  return 0;
}