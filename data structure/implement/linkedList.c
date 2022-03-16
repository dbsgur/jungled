#include <stdio.h>
#include <stdlib.h>

// max stack size
#define SIZE 1000
#define TRUE 1
#define FALSE 0

typedef struct __list
{
  struct node *cur;
  struct node *head;
  struct node *tail;

} linkedList;

typedef struct __node
{
  int data;
  struct __node *next;
} node;

//create node
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

// push

// delete
void deleteLastNode(linkedList *L)
{
}