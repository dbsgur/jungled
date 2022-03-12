#include <stdio.h>
#define size 500000

int main()
{
  int n, i, front = 0, rear;
  int que[size];
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    que[i] = i + 1;
  }
  rear = n - 1;

  while (1)
  {
    front = (front + 1) % n;
    if (front == rear)
      break;
    rear = (rear + 1) % n;
    que[rear] = que[front];
    front = (front + 1) % n;
    if (front == rear)
      break;
  }
  printf("%d\n", que[rear]);
  return 0;
}