#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // bool, true, false가 정의된 헤더 파일

// max stack size
#define SIZE 1000

int stack[SIZE];
int top = -1;

int IsEmpty()
{
  if (top < 0)
    return true;
  else
    return false;
}

int IsFull()
{
  if (top >= SIZE - 1)
    return true;
  else
    return false;
}

void push(int value)
{
  if (IsFull() == true)
    printf("스택이 찼어유");
  else
    stack[++top] = value;
}

int pop()
{
  if (IsEmpty() == true)
  {
    printf("스택이 비었어유\n");
    exit(0);
  }
  else
    return stack[top--];
}

int main()
{
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(4);
  push(4);
  push(4);
  push(1111);
  push(111111);
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());

  return 0;
}