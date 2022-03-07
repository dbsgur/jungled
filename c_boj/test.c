#include <stdio.h>

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
  return 0;
}