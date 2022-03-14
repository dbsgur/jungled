#include <stdio.h>
#include <stdlib.h>

// struct
typedef struct _Node
{
  int data;
  struct _Node *prev;
  struct _Node *next;
} Node;

// Craete Node
Node *CreateNode()
{
  Node *New_Node = (Node *)malloc(sizeof(Node));

  if (New_Node == NULL)
    return New_Node;

  New_Node->data = 0;
  New_Node->prev = New_Node->next = NULL;
}

// Initilaization Head
Node *Head;
void Init_Head()
{
  Head = CreateNode();

  if (Head == NULL)
    return;

  Head->data = 0;
  // 초기엔 아무것도 없기 때문에,
  // Head의 next, prev의 초깃값은 자기 자신인 Head를 가리킨다.
  // Head의 next, prev의 값을 이용해 노드의 존재 여부를 확인할 수 있다.
  Head->prev = Head->next = Head;
}

// Insert Head Node
void Insert_Head(Node *New_Node, int data)
{
  New_Node = CreateNode();

  if (New_Node == NULL)
    return;

  // connection new node
  New_Node->prev = Head;
  New_Node->next = Head->next;
  New_Node->prev->next = New_Node;
  New_Node->next->prev = New_Node;

  //insert Data
  New_Node->data = data;
}