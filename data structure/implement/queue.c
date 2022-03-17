#include <stdio.h>
#include <stdlib.h>

typedef struct __SNode
{
  int data;
  struct __SNode *next;
} Node;

typedef struct __SQueue
{
  Node *front;
  Node *rear;
  int count; // 노드 갯수
} Queue;

// Initialization
void initQueue(Queue *queue)
{
  queue->front = queue->rear = NULL;
  queue->count = 0; // 큐안의 노드 개수를 0으로 설정
}

int isEmpty(Queue *queue)
{
  return queue->count == 0;
}

// ENQUEUE
void enqueue(Queue *queue, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (isEmpty(queue)) //if isempty?
  {
    queue->front = newNode;
  }
  else
  {
    queue->rear->next = newNode;
  }
  queue->rear = newNode; //맨 뒤를 newNode로 설정
  queue->count++;
}

// DEQUEUE
int deque(Queue *queue)
{
  int data;
  Node *ptr;
  if (isEmpty(queue))
  {
    printf("Error : Queue is empty!\n");
    // putchar('Error : queue is empty');
    // putchar('\n');
    return 0;
  }
  ptr = queue->front;       //맨앞의 노드 ptr
  data = ptr->data;         // return할 데이터
  queue->front = ptr->next; // 맨 앞은 ptr의 다음 노드로 설정
  free(ptr);
  queue->count--;

  return data;
}

int main()
{
  int i;
  Queue queue;

  initQueue(&queue); // initialization queue
  for (i = 0; i <= 10; i++)
  {
    enqueue(&queue, i * 3);
  }
  while (!isEmpty(&queue))
  {
    printf("%d ", deque(&queue));
  }

  return 0;
}