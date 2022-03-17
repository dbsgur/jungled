#include <stdio.h>
#include <stdlib.h>

// max stack size
#define SIZE 1000
#define TRUE 1
#define FALSE 0

typedef struct __list
{
  struct __node *cur;
  struct __node *head;
  struct __node *tail;

} linkedList;

typedef struct __node
{
  int data;
  struct __node *next;
} node;

//create node (tail + node)
void createNode(linkedList *L, int tdata)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = tdata;
  newNode->next = NULL;
  if (L->head == NULL && L->tail == NULL)
  {
    L->head = L->tail = newNode;
  }
  else
  {
    L->tail->next = newNode;
    L->tail = newNode;
  }
  L->cur = newNode;
}

// delete (tail node delete)
void deleteLastNode(linkedList *L)
{
  node *p = L->head;
  while (p->next->next != NULL)
    p = p->next;
  p->next = p->next->next;
  L->tail = p;
}

void printNodes(linkedList *L)
{
  node *p = L->head;
  // printf("[");
  putchar('[');
  while (p != NULL)
  {
    printf("%d, ", p->data);
    p = p->next;
  }
  putchar(']');
  putchar('\n');
}

int main()
{
  // linkedList pointer define start
  linkedList *L = (linkedList *)malloc(sizeof(linkedList));
  L->cur = NULL;
  L->head = NULL;
  L->tail = NULL;
  // linkedList pointer define end

  createNode(L, 1);
  createNode(L, 2);
  createNode(L, 3);
  deleteLastNode(L);
  createNode(L, 4);
  createNode(L, 5);
  createNode(L, 6);
  deleteLastNode(L);
  deleteLastNode(L);
  createNode(L, 7);
  createNode(L, 8);
  printNodes(L);

  return 0;
}