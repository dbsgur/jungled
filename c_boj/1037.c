#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  if (*(int *)a > *(int *)b)
    return 1;
  else if (*(int *)a < *(int *)b)
    return -1;
  else
    return 0;
}

int main()
{
  int n, i, result;
  int *arr;
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), compare);

  int m = n / 2;
  if (n % 2 == 0)
  {
    result = arr[m] * arr[m - 1];
  }
  else
  {
    result = arr[m] * arr[m];
  }
  printf("%d\n", result);
  free(arr);
  return 0;
}