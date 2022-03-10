#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int main()
{
  int n, i;
  int *nums;
  int sum = 0;
  scanf("%d", &n);
  nums = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &nums[i]);
  }
  // for (i = 0; i < n; i++)
  // {
  //   printf("%d", nums[i]);
  // }
  qsort(nums, n, sizeof(int), compare);
  // printf("!!!\n");
  // for (i = 0; i < n; i++)
  // {
  //   printf("%d", nums[i]);
  // }
  for (i = 1; i < n; i++)
  {
    nums[i] += nums[i - 1];
  }
  for (i = 0; i < n; i++)
  {
    sum += nums[i];
  }
  printf("%d\n", sum);
  free(nums);
  return 0;
}
int compare(const void *a, const void *b)
{
  if (*(int *)a > *(int *)b)
    return 1;
  else if (*(int *)a < *(int *)b)
    return -1;
  else
    return 0;
}