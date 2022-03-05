#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int unique(int *arr, int size)
{
  int i, j = 0;
  for (i = 1; i < size; i++)
  {
    if (arr[j] == arr[i])
      continue;
    arr[++j] = arr[i];
  }
  return ++j;
}

int binarysearch(int *arr, int size, int key)
{
  int left = 0, right = size - 1, mid;
  while (left <= right)
  {
    mid = (left + right) / 2;
    if (arr[mid] < key)
      left = mid + 1;
    else if (arr[mid] > key)
      right = mid - 1;
    else
      return mid;
  }
  return -1;
}

int main()
{
  int n;
  scanf("%d", &n);

  int *arr = (int *)calloc(n, sizeof(int));
  int *sort = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    sort[i] = arr[i];
    // ?? 바로 sort에 넣으면 안되나 ????
  }

  qsort(sort, n, sizeof(int), compare);

  int cnt = unique(sort, n);
  for (int i = 0; i < n; i++)
  {
    int tmp = binarysearch(sort, cnt, arr[i]);
    printf("%d ", tmp);
    printf("");
    // printf("i : ", &i);
  }
  free(arr);
  free(sort);

  return 0;
}

// sort

// 중복 제거

// 이진 탐색

// #include <stdio.h>

// int arr1[1000000] = {
//     0,
// };
// int arr2[1000000] = {
//     0,
// };
// int min_heap[1000001] = {
//     0,
// }; //idx : 1 ~ 1000000
// int idx = 1;

// void insert(int val)
// {
//   int temp_idx = idx;
//   int temp;
//   min_heap[idx++] = val;
//   while (temp_idx > 1)
//   {
//     if (min_heap[temp_idx / 2] > min_heap[temp_idx])
//     {
//       temp = min_heap[temp_idx / 2];
//       min_heap[temp_idx / 2] = min_heap[temp_idx];
//       min_heap[temp_idx] = temp;
//       temp_idx /= 2;
//     }
//     else
//     {
//       break;
//     }
//   }
// }

// void heapify(int i)
// {
//   // i : idx
//   int left = 2 * i;
//   int right = 2 * i + 1;
//   int smallest = i;
//   int temp;

//   // find smallest
//   if (left < idx && min_heap[left] < min_heap[smallest])
//     smallest = left;
//   if (right < idx && min_heap[right] < min_heap[smallest])
//     smallest = right;

//   if (smallest != i)
//   {
//     //swap
//     temp = min_heap[i];
//     min_heap[i] = min_heap[smallest];
//     min_heap[smallest] = temp;
//     heapify(smallest);
//   }
// }

// int main()
// {
//   int N;
//   int val;
//   //input
//   scanf("%d", &N);
//   for (int i = 0; i < N; i++)
//   {
//     scanf(" %d", &arr1[i]);
//     insert(arr1[i]);
//   }
//   // sorting and deduplcation
//   int sort_idx = 0;
//   for (int i = 0; i < N; i++)
//   {
//     val = min_heap[1];
//     if (sort_idx > 0)
//     {
//       if (arr2[sort_idx - 1] == val)
//       {
//         min_heap[1] = min_heap[idx - 1]; // remove
//         heapify(1);
//         idx -= 1;
//         continue;
//       }
//     }
//     arr2[sort_idx++] = min_heap[1];
//     min_heap[1] = min_heap[idx - 1]; //remove
//     heapify(1);
//     idx -= 1;
//   }

//   // binary search로 바꾸기
//   for (int i = 0; i < N; i++)
//   {
//     int left = 0;
//     int right = sort_idx;
//     int mid;
//     while (left <= right)
//     {
//       mid = (left + right) / 2;
//       if (arr2[mid] > arr1[i])
//       {
//         right = mid - 1;
//       }
//       else if (arr2[mid] < arr1[i])
//       {
//         left = mid + 1;
//       }
//       else
//         break;
//     }
//     printf("%d ", mid);
//   }
//   return 0;
// }