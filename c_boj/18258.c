#include <stdio.h>
#include <string.h>

typedef struct Queue
{
  int data[2000000];
  int front, rear;
} Queue;

void init(Queue *q)
{
  q->front = q->rear = -1;
}

// empty
int is_empty(Queue *q)
{
  return (q->front == q->rear);
}

// size
int size(Queue *q)
{
  if (is_empty(q))
  {
    return 0;
  }
  return (q->rear - q->front);
}

// front
int front(Queue *q)
{
  if (is_empty(q))
    return -1;
  return q->data[q->front + 1]; //?
}

//back
int back(Queue *q)
{
  if (is_empty(q))
    return -1;
  return q->data[q->rear];
}

// push
void push(Queue *q, int x)
{
  q->data[++(q->rear)] = x;
}

// pop
int pop(Queue *q)
{
  if (is_empty(q))
    return -1;
  return q->data[++(q->front)];
}
int main()
{
  Queue q;
  init(&q);

  int n;
  scanf("%d", &n);

  while (n--)
  {
    char str[6];
    scanf("%s", str);
    if (!strcmp(str, "push"))
    {
      int data = 0;
      scanf("%d", &data);
      push(&q, data);
    }
    else if (!strcmp(str, "front"))
    {
      printf("%d\n", front(&q));
    }
    else if (!strcmp(str, "back"))
    {
      printf("%d\n", back(&q));
    }
    else if (!strcmp(str, "pop"))
    {
      printf("%d\n", pop(&q));
    }
    else if (!strcmp(str, "size"))
    {
      printf("%d\n", size(&q));
    }
    else if (!strcmp(str, "empty"))
    {
      printf("%d\n", is_empty(&q));
    }
  }

  return 0;
}