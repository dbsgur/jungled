#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

typedef struct
{
  int key;
  int value;
} Paper;

typedef struct
{
  Paper queue[SIZE];
  int front, rear;
  int size;
} QueueType;

void InitQueue(QueueType *q)
{
  q->front = q->rear = 0;
  q->size = 0;
}

int IsEmpty(QueueType *q)
{
  return q->rear == q->front;
}

int IsFull(QueueType *q)
{
  return (q->rear + 1) % SIZE == q->front;
}

void Enqueue(QueueType *q, Paper e)
{
  if (IsFull(q))
    return;

  q->rear = (q->rear + 1) % SIZE;
  q->queue[q->rear] = e;
  q->size += 1;
}

Paper Dequeue(QueueType *q)
{
  if (IsEmpty(q))
    exit(1);

  q->front = (q->front + 1) % SIZE;
  q->size -= 1;
  return q->queue[q->front];
}

int IsLarge(QueueType *q)
{
  if (IsEmpty(q))
    return -1;

  int idx = (q->front + 1) % SIZE;
  int max = q->queue[idx].key;

  for (int i = 0; i < q->size - 1; i++)
  {
    idx = (idx + 1) % SIZE;

    // Front값 중요도보다 높은게 있으면.. return 1
    if (max < q->queue[idx].key)
      return 1;
  }

  // Front값 중요도가 제일 높으면.. return 0
  return 0;
}

int main()
{
  QueueType q;
  Paper tmp;
  int i, j, n, m, e, test_case, cnt;

  scanf("%d", &test_case);

  for (i = 0; i < test_case; i++)
  {
    scanf(" %d  %d", &n, &m);

    // 삽입 전 큐 초기화
    InitQueue(&q);
    cnt = 0;

    // 큐에 데이터 삽입
    for (j = 0; j < n; j++)
    {
      scanf(" %d", &tmp.key);

      // 내가 찾고자 하는 값은 1로 세팅
      if (j == m)
        tmp.value = 1;
      // 나머지는 0으로 초기화.
      else
        tmp.value = 0;

      Enqueue(&q, tmp);
    }

    do
    {
      // 제일 중요한게 맨앞에 올때까지
      while (IsLarge(&q) != 0)
      {
        tmp = Dequeue(&q);
        Enqueue(&q, tmp);
      }
      tmp = Dequeue(&q);
      cnt += 1;
    } while (tmp.value != 1);

    printf("%d\n", cnt);
  }

  return 0;
}
