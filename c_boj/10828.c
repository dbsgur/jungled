#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int stack[100001];
int count = 0;
// !! void -> return이 없는 자료형
//push
void push(int n)
{
  stack[count] = n;
  count++;
}

//pop
void pop()
{
  if (count == 0)
    printf("%d\n", -1);
  else
  {
    count--;
    printf("%d\n", stack[count]);
    stack[count] = 0;
  }
}
//size
void size()
{
  printf("%d\n", count);
}
//empty
void empty()
{
  if (count == 0)
    printf("%d\n", 1);
  else
    printf("%d\n", 0);
}

//top
void top()
{
  if (count == 0)
    printf("%d\n", -1);
  else
    printf("%d\n", stack[count - 1]);
}

int main()
{
  int n;
  char number[10];

  scanf("%d", &n);

  // int stack[100];
  for (int i = 0; i < n; i++)
  {
    scanf("%s", number);
    if (strcmp(number, "push") == 0)
    {
      int num;
      scanf("%d", &num);
      push(num);
    }
    else if (strcmp(number, "pop") == 0)
      pop();
    else if (strcmp(number, "top") == 0)
      top();
    else if (strcmp(number, "size") == 0)
      size();
    else
      empty();
  }
}