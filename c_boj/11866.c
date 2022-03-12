#include <stdio.h>

int main()
{
  int n, k, i;
  scanf("%d %d", &n, &k);
  int yosep[n];
  int result[n];
  int front = 0;
  int rear = n - 1;
  for (i = 0; i < n; i++)
  {
    yosep[i] = i + 1;
  }
  while (1)
  {
    for (i = 0; i < k - 1; i++)
    {
      rear = (rear + 1) % n;
      yosep[rear] = yosep[front];
      front = (front + 1) % n;
      //?
    }
    // 시발 다 틀렷어 ㅠㅠ 꾀부릴려다가 ,,,
    // 정석부터 익히자 븅시나
    front = (front + 1) % n;
  }
  return 0;
}