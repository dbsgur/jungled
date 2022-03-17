#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAX_SIZE 10

typedef int element;
typedef int boolean;

// circular queue
typedef struct __Queue
{
  int rear;
  int front;
  element *data;
} Queue;

// queue initialization
void initQueue(Queue *q)
{
  q->front = 0;
  q->rear = 0;
  q->data = (element *)malloc(sizeof(element) * MAX_SIZE);
}

// 공백상태인지 여부
boolean isEmpty(Queue *q)
{
  if (q->front == q->rear)
    return TRUE;
  else
    return FALSE;
}

// 포화 상태인지 여부
boolean isFull(Queue *q)
{
  if ((q->rear + 1) % MAX_SIZE == q->front)
    return TRUE;
  else
    return FALSE;
}

// insert queue
void enqueue(Queue *q, element data)
{
  if (isFull(q))
  {
    printf("\n 포화 큐\n");
    // return;
  }
  else
  {
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = data;
  }
  // return;
}

//delete queue
element dequeue(Queue *q)
{
  if (isEmpty(q))
  {
    printf("\n공백큐\n");
  }
  q->front = (q->front + 1) % MAX_SIZE;
  return q->data[q->front];
}

void printQueue(Queue q)
{
  int i = q.front;
  if (isEmpty(&q))
  {
    printf("\n공백큐\n");
    return;
  }
  do
  {
    i = (i + 1) % MAX_SIZE;
    printf("%d | ", q.data[i]);
    if (i == q.rear)
    {
      break;
    }
  } while (i != q.front);
  printf("\n\n");
  return;
}

int main()
{
  Queue q;
  initQueue(&q);
  int i;
  for (i = 0; i < 15; i++)
  {
    enqueue(&q, i);
    printQueue(q);
  }
  for (i = 0; i < 7; i++)
  {
    dequeue(&q);
    printQueue(q);
  }
  free(q.data);
  return 0;
}