#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
  int data;
  struct _Node *prev;
  struct _Node *next;
} Node;