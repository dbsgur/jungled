#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100001
#define TRUE 1
#define FALSE 0

// this is absolution min heap !!!
typedef struct
{
  int key;
} element;

typedef struct
{
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;

// initialization function
void init(HeapType *h)
{
  h->heap_size = 0;
}

// insert function
void insert_min_heap(HeapType *h, element item)
{
  int i;
  i = ++(h->heap_size);

  // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
  while ((i != 1) && (abs(item.key) <= abs(h->heap[i / 2].key)))
  {
    // item.key가 양수면 break
    if (abs(item.key) == abs(h->heap[i / 2].key) && item.key > h->heap[i / 2].key)
      break;
    h->heap[i] = h->heap[i / 2];
    i /= 2;
  }
  h->heap[i] = item;
}

// deletion function
element delete_min_heap(HeapType *h)
{
  int parent, child;
  element item, temp;

  if (!h->heap_size)
  {
    item.key = 0;
    return item;
  }
  item = h->heap[1];
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;
  while (child <= h->heap_size)
  {
    // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
    if ((child < h->heap_size) &&
        abs(h->heap[child].key) > abs(h->heap[child + 1].key))
      child++;
    else if ((child < h->heap_size) && abs(h->heap[child].key) == abs(h->heap[child + 1].key) &&
             (h->heap[child].key) > h->heap[child + 1].key)
      child++;
    if (abs(temp.key) < abs(h->heap[child].key))
      break;
    else if (abs(temp.key) == abs(h->heap[child].key) &&
             temp.key < h->heap[child].key)
      break;
    // 한단계 아래로 이동
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item;
}

int main()
{
  HeapType heap;
  element e;
  int n, i;
  int input;

  init(&heap);
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &input);
    if (input > 0 || input < 0)
    {
      e.key = input;
      insert_min_heap(&heap, e);
    }
    else
    {
      printf("%d\n", delete_min_heap(&heap).key);
    }
  }
}

// ?? 아 ,,, 밑에꺼는 최대힙,,,,ㅠ
// #include <stdio.h>
// #include <stdlib.h>

// #define SIZE 100001

// int heap_count = 0;
// int heap[SIZE];

// void swap(int *a, int *b)
// {
//   int tmp = *a;
//   *a = *b;
//   *b = tmp;
// }

// int size()
// {
//   return heap_count;
// }

// void push(int data)
// {
//   heap[++heap_count] = data;

//   int child = heap_count;
//   int parent = child / 2;
//   while (child > 1 && abs(heap[parent]) < abs(heap[child]))
//   {
//     swap(&heap[parent], &heap[child]);
//     child = parent;
//     parent = child / 2;
//   }
// }

// int pop()
// {
//   int result = heap[1];
//   swap(&heap[1], &heap[heap_count--]);

//   int parent = 1;
//   int child = parent * 2;
//   if (child + 1 <= heap_count)
//   {
//     // 자식이 두개면 큰놈이랑 바꾸는 거
//     if (abs(heap[child]) < abs(heap[child + 1]))
//       child += 1;
//   }

//   while (child <= heap_count && abs(heap[parent]) < abs(heap[child]))
//   {
//     swap(&heap[parent], &heap[child]);

//     parent = child;
//     child = child * 2;
//     if (child + 1 <= heap_count)
//     {
//       //
//       if (abs(heap[child]) < abs(heap[child + 1]))
//         child += 1;
//     }
//   }
//   return result;
// }

// int main()
// {
//   int N, i;
//   int command;
//   scanf("%d", &N);
//   for (i = 0; i < N; i++)
//   {
//     scanf("%d", &command);
//     if (command != 0)
//     {
//       push(command);
//     }
//     else
//     {
//       if (size() == 0)
//       {
//         printf("0\n");
//       }
//       else
//       {
//         printf("%d\n", pop());
//       }
//     }
//   }

//   return 0;
// }