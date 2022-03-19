#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

int compare(const void *a, const void *b)
{
  if (*(int *)a > *(int *)b)
    return 1;
  else if (*(int *)a < *(int *)b)
    return -1;
  else
    return 0;
  // return *(int *)a - *(int *)b;
}

int binarySearch(int l, int *arr, int start, int end)
{
  if (start > end)
  {
    return 0;
  }
  int middle = (start + end) / 2;
  if (arr[middle] == l)
  {
    return 1;
  }
  else if (arr[middle] < l)
  {
    return binarySearch(l, arr, middle + 1, end);
  }
  else
  {
    return binarySearch(l, arr, start, middle - 1);
  }
}

int main()
{
  int n, m, i;
  scanf("%d", &n);
  int a[MAX] = {
      0,
  };

  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  // 이게 되ㅣ네 ~?
  // for (i = 0; i < n; i++)
  // {
  //   printf("%d", a[i]);
  // }
  scanf("%d", &m);
  int b[MAX] = {
      0,
  };

  for (i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }
  qsort(a, n, sizeof(int), compare);

  for (i = 0; i < m; i++)
  {
    printf("%d\n", binarySearch(b[i], a, 0, n - 1));
  }

  return 0;
}