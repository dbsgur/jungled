#include <stdio.h>

int main()
{
  int n, i, x, head = 0, s;
  int Data[100001] = {0};

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    if (x)
    {
      Data[++head] = x;

      for (int i = head; i > 1;)
      {
        int parent = i / 2;
        if (Data[parent] > Data[i])
        {
          s = Data[i];
          Data[i] = Data[parent];
          Data[parent] = s;

          i = parent;
        }
        else
          break;
      }
    }

    else
    {
      if (!head)
      {
        printf("0\n");
        continue;
      }
      printf("%d\n", Data[1]);
      Data[1] = Data[head--];
      for (int i = 1;;)
      {
        int child;
        if (head < i * 2)
          break;
        else if (head == i * 2)
          child = i * 2;
        else
          child = Data[i * 2] < Data[i * 2 + 1] ? i * 2 : i * 2 + 1;

        if (Data[i] > Data[child])
        {
          s = Data[i];
          Data[i] = Data[child];
          Data[child] = s;

          i = child;
        }
        else
          break;
      }
    }
  }
  return 0;
}

// 시간 초과
// #include <stdio.h>
// #include <stdlib.h>

// #define SIZE 100001

// int heap[SIZE];
// int heap_count = 0;

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

//   while (child > 1 && heap[child] < heap[parent])
//   {
//     swap(&heap[child], &heap[parent]);
//     child = parent;
//     parent = child / 2;
//   }
// }

// int pop()
// {
//   if (size() == 0)
//   {
//     return 0;
//   }
//   int result = heap[1];
//   swap(&heap[1], &heap[heap_count--]);

//   int parent = 1;
//   int child = parent * 2;
//   // 자식이 두개면 작은놈이랑 바꾸기
//   if (child + 1 <= heap_count)
//   {
//     if (heap[child] > heap[child + 1])
//       child += 1;
//   }

//   while (child <= heap_count && heap[parent] > heap[child])
//   {
//     swap(&heap[parent], &heap[child]);
//     parent = child;
//     child = parent / 2;

//     if (child + 1 <= heap_count)
//     {
//       if (heap[child] > heap[child + 1])
//         child += 1;
//     }
//   }
//   return result;
// }

// int main()
// {
//   int N, i, command;

//   scanf("%d", &N);
//   for (i = 0; i < N; i++)
//   {
//     scanf("%d", &command);
//     if (command != 0)
//     {
//       push(command);
//       continue;
//     }
//     else
//     {
//       printf("%d\n", pop());
//     }
//   }
//   return 0;
// }