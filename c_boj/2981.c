#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
  // if (*(int *)a > *(int *)b)
  //   return 1;
  // else if (*(int *)a < *(int *)b)
  //   return -1;
  // else
  //   return 0;
}
int m[99];
int n;
int main()
{
  int i;
  scanf("%d", &n);
  int arr[n];
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), compare);

  int x = arr[1] - arr[0], idx = 0;
  int sq = sqrt(x);
  for (i = 2; i <= sq; i++)
  {
    if (x % i == 0)
    {
      m[idx++] = i;
      if (x / i != i)
        m[idx++] = x / i;
    }
  }
  qsort(m, idx, sizeof(int), compare);
  m[idx++] = x;
  for (i = 0; i < idx; i++)
  {
    int j;
    for (j = 1; j < n; j++)
    {
      if (arr[j] % m[i] != arr[0] % m[i])
        break;
    }
    if (j == n)
      printf("%d ", m[i]);
  }
  return 0;
}