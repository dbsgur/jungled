#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, m, i;
  int *nums;
  int count = 0;
  scanf("%d %d", &n, &m);
  nums = (int *)malloc(sizeof(int) * n + 1);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &nums[i]);
  }
  // printf("%d %d\n", n, m);
  for (i = n - 1; i >= 0; i--)
  {
    if (m == 0)
      break;
    if (nums[i] > m)
      continue;

    count += (m / nums[i]);
    m %= nums[i];
    // printf("nums : %d", nums[i]);
  }
  printf("%d\n", count);
  free(nums);
  return 0;
}