#include <stdio.h>

int main()
{
  int n, i, num;
  int j = 0;
  scanf("%d", &n);
  int nums[n];
  int sum = 0;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &num);
    // printf("num : %d", num);
    if (num != 0)
    {
      nums[j++] = num;
    }
    else
    {
      nums[j--] = 0;
    }
  }

  // printf("==============\n");
  for (i = 0; i < j; i++)
  {
    // printf("nums[%d] : %d\n", i, nums[i]);
    sum += nums[i];
  }
  // printf("sum : %d\n", sum);
  printf("%d\n", sum);

  return 0;
}