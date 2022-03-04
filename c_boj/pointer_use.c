#include <stdio.h>

void swap(int *num1, int *num2)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int main()
{
  int num1 = 10;
  int num2 = 20;

  printf("value of num1 : %d \n", num1);
  printf("value of num2 : %d \n", num2);

  swap(&num1, &num2);
  printf("\n swap function AFTER \n\n");

  printf("value of num1 : %d \n", num1);
  printf("value of num2 : %d \n", num2);

  return 0;
}
