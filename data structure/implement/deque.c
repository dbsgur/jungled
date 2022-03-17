#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAX_SIZE 10

typedef int element;
typedef int boolean;

typedef struct __Deque
{
  element *data;
  int rear, front;
} Deque;

// deque initialization
void initDeque(Deque *q)
{
  q->data = (element *)malloc((sizeof(element)));
  q->front = q->rear = 0;
}

boolean isEmpty(Deque *q)
{
  if (q->front == q->rear)
    return TRUE;
  else
    return FALSE;
  // return (q->front == q->rear);
}

boolean isFull(Deque *q)
{
  if ((q->rear + 1) % MAX_SIZE == q->front)
    return TRUE;
  else
    return FALSE;
}

// return deque's rear value
element getRear(Deque *q)
{
  // ? isEmpty(&q)
  if (isEmpty(q))
  {
    printf("공백큐\n");
    return ERROR;
  }
  return q->data[q->rear];
}

//return deque's front value
element getFront(Deque *q)
{
  if (isEmpty(q))
  {
    printf("공백큐\n");
    return ERROR;
  }
  // front는 항상 공백을 가리키고 있기 때문에
  // 실제 첫 요소는 front+1의 index에 위치하고 있기 때문이다.
  return q->data[(q->front + 1) % MAX_SIZE];
}

// add data in rear
void addRear(Deque *q, element data)
{
  if (isFull(q))
  {
    printf("포화 큐\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_SIZE;
  q->data[q->rear] = data;
}

// add data in front
void addFront(Deque *q, element data)
{
  if (isFull(q))
  {
    printf("포화큐\n");
    return;
  }
  // front -1인 경우 오류를 방지하기 위해서 +MAX_SIZE해주자
  q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
  return;
}

//delete data front
element deleteFront(Deque *q)
{
  if (isEmpty(q))
  {
    printf("공백큐\n");
    return 0;
  }
  element tmp = getFront(q);
  q->front = (q->front + 1) % MAX_SIZE;
  return tmp;
}

// delete data rear
element deleteRear(Deque *q)
{
  if (isEmpty(q))
  {
    printf("공백 큐\n");
    return 0;
  }
  element tmp = getRear(q);
  //rear이 -1인 경우 오류를 방지하기 위해서 +MAX_SIZE해주자
  q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
  return tmp;
}

// print all deque
void printDeque(Deque *q)
{
  int i = (q->front + 1) % MAX_SIZE;

  printf("DEQUE(front = %d | rear = %d) = ", q->front, q->rear);

  if (isEmpty(q))
  {
    printf("공백큐 \n");
    return;
  }
  while (i != q->rear)
  {
    printf("%d | ", q->data[i]);
    i = (i + 1) % MAX_SIZE;
  }
  printf("%d \n", q->data[i]);
}

int main()
{
  Deque q;

  int i;

  initDeque(&q);
  printf("### ADD FRONT ###\n\n");
  for (i = 0; i < 3; i++)
  {
    addFront(&q, i + 2);
    printDeque(&q);
  }
  printf("\n ### DELETE REAR ###\n\n");
  for (i = 0; i < 2; i++)
  {
    deleteFront(&q);
    printDeque(&q);
  }

  printf("\n ### ADD REAR ###\n\n");
  for (i = 0; i < 3; i++)
  {
    addRear(&q, i + 4);
    printDeque(&q);
  }

  printf("\n ### DELETE FRONT ### \n\n");
  for (i = 0; i < 4; i++)
  {
    deleteFront(&q);
    printDeque(&q);
  }

  free(q.data);
  return 0;
}