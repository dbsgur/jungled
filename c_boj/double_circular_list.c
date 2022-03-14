#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct _Node
{
  int data;
  struct _Node *prev;
  struct _Node *next;
} Node;

Node *CreateNode()
{
  Node *New_Node = (Node *)malloc(sizeof(Node));

  if (New_Node == NULL)
    return New_Node;

  New_Node->data = 0;
  New_Node->prev = New_Node->next = NULL;

  return New_Node;
}

Node *Head;
void Init_Head()
{
  Head = CreateNode();

  if (Head == NULL)
    return;

  Head->data = 0;
  Head->prev = Head->next = Head;
}

void Insert_Head(Node *New_Node, int data)
{
  New_Node = CreateNode();

  if (New_Node == NULL)
    return;

  // 새로운 노드 연결.
  New_Node->prev = Head;
  New_Node->next = Head->next;
  New_Node->prev->next = New_Node;
  New_Node->next->prev = New_Node;

  // data 삽입.
  New_Node->data = data;
}

void Insert_Tail(Node *New_Node, int data)
{
  New_Node = CreateNode();

  if (New_Node == NULL)
    return;

  // 새로운 노드 연결.
  New_Node->prev = Head->prev;
  New_Node->next = Head;
  New_Node->prev->next = New_Node;
  New_Node->next->prev = New_Node;

  // data 삽입.
  New_Node->data = data;
}

uint8 Check_Node_Empty()
{
  if (Head->prev == Head && Head->next == Head)
    return FAIL;
  else
    return SUCCESS;
}

uint8 Remove_Head()
{
  Node *Target = Head->next;

  // Node의 존재 여부를 확인.
  if (!Check_Node_Empty())
    return FAIL;

  Target->prev->next = Target->next;
  Target->next->prev = Target->prev;
  free(Target);

  return SUCCESS;
}

uint8 Remove_Tail()
{
  Node *Target = Head->prev;

  // Node의 존재 여부 확인.
  if (!Check_Node_Empty())
    return FAIL;

  Target->prev->next = Target->next;
  Target->next->prev = Target->prev;
  free(Target);

  return SUCCESS;
}

void Print_All_Node()
{
  Node *Target = Head->next;

  if (!Check_Node_Empty())
    return;

  while (Target != Head)
  {
    printf("Data : %d\r\n", Target->data);
    Target = Target->next;
  }
}

void Control_List(void)
{
  Node *Node = NULL;

  Init_Head();
  Insert_Tail(Node, 1);
  Insert_Tail(Node, 2);
  Insert_Tail(Node, 3);
  Insert_Tail(Node, 3);
  Insert_Head(Node, 9);
  Remove_Tail();
  Print_All_Node();
}

int main(void)
{
  Control_List();

  return 0;
}