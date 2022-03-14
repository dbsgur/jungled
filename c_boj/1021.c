// 양방향 순환 큐-> deque 구현해서 풀어보기
#include <stdio.h>
#define size 100

int N, M;
int extracted[100];
int index_extracted;
int total_op;

int deque[size];

int front = 0, back = 1;
int temp_front, temp_back;

void rotate_clock()
{
  deque[back] = deque[(front + 1 + size) % size];
  back = (back + 1) % size;
  front = (front + 1) % size;
  return;
}

void rotate_counterclock()
{
  deque[front] = deque[(back - 1 + size) % size];
  back = (back - 1 + size) % size;
  front = (front - 1 + size) % size;
  return;
}

void pop_front()
{
  front = (front + 1) % size;
  return;
}

int main(void)
{
  scanf("%d %d", &N, &M);

  for (int i = 0; i < M; i++)
  {
    scanf("%d", &extracted[i]);
  }

  for (int i = 1; i <= N; i++)
  {
    deque[i] = i;
  }
  back = N + 1;

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < (back - front + size - 1) % size; j++)
    {
      if (deque[(front + 1 + j) % size] == extracted[i])
      {
        index_extracted = (front + 1 + j) % size;
        break;
      }
    }
    temp_front = front;
    temp_back = back;
    if (((index_extracted - temp_front - 1 + size) % size) > (temp_back - index_extracted + size) % size)
    {
      for (int j = 0; j < ((temp_back - index_extracted + size) % size); j++)
      {
        rotate_counterclock();
        total_op++;
      }
      pop_front();
    }
    else
    {
      for (int j = 0; j < ((index_extracted - temp_front - 1 + size) % size); j++)
      {
        rotate_clock();
        total_op++;
      }
      pop_front();
    }
  }

  printf("%d\n", total_op);
}