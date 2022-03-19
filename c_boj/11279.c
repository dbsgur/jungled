#include <stdio.h>
#include <stdlib.h>

#define SIZE 100001

int heap_count = 0;
int heap[SIZE];

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int size()
{
  return heap_count;
}

void push(int data)
{
  heap[++heap_count] = data;

  int child = heap_count;
  int parent = child / 2;
  while (child > 1 && heap[parent] < heap[child])
  {
    swap(&heap[parent], &heap[child]);
    child = parent;
    parent = child / 2;
  }
}

int pop()
{
  int result = heap[1];
  swap(&heap[1], &heap[heap_count--]);

  int parent = 1;
  int child = parent * 2;
  if (child + 1 <= heap_count)
  {
    // 자식이 두개면 큰놈이랑 바꾸는 거
    if (heap[child] < heap[child + 1])
      child += 1;
  }

  while (child <= heap_count && heap[parent] < heap[child])
  {
    swap(&heap[parent], &heap[child]);

    parent = child;
    child = child * 2;
    if (child + 1 <= heap_count)
    {
      //
      if (heap[child] < heap[child + 1])
        child += 1;
    }
  }
  return result;
}

int main()
{
  int N, i;
  int command;
  scanf("%d", &N);
  for (i = 0; i < N; i++)
  {
    scanf("%d", &command);
    if (command != 0)
    {
      push(command);
    }
    else
    {
      if (size() == 0)
      {
        printf("0\n");
      }
      else
      {
        printf("%d\n", pop());
      }
    }
  }

  return 0;
}