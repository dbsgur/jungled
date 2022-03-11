#include <stdio.h>
#include <limits.h>

int main()
{

  int result[5] = {
      0,
  };
  int i;
  for (i = 1; i <= 4; i++)
  {
    result[1] = i;
  }

  for (i = 0; i < 4; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");
  int num2 = 1000000000;
  printf("%d", num2);

  int num1 = INT_MAX;
  printf("%d", num1);
  //2,147,483,647
  int test[5] = {
      1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", test[i]);
  }
  return 0;
}