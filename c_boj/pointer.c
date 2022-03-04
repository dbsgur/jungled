#include <stdio.h>

void main()
{
  int *p = NULL;
  int i = 10;
  p = &i;

  printf("변수 i의 주소값 : %p \n", &i);
  printf("포인터 P의 값 : %p \n", p);
  printf("포인터 p가 가리키는 값 : %d \n", *p);
}
