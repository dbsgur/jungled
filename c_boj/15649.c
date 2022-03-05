#include <stdio.h>

int N, M;
int result[1000];
int checklist[1000];

void DFS(int L)
{
  int i;

  if (L == M)
  {
    for (i = 0; i < M; i++)
      printf("%d ", result[i]);
    printf("\n");
  }
  else
  {
    for (i = 1; i <= N; i++)
    {
      if (checklist[i] == 0)
      {
        result[L] = i;
        checklist[i] = 1;
        DFS(L + 1);
        checklist[i] = 0;
      }
    }
  }
}
int main()
{
  scanf("%d %d", &N, &M);
  DFS(0);
}

// void Backtracking(int Arr[], int N, int M, int d)
// {
//   for (int i = 1; i <= N; i++)
//   {
//     int k = 0;

//     if (d == 0)
//       Arr[0] = i;
//     else
//     {
//       for (k = 0; k < d; k++)
//       {
//         if (Arr[k] == i)
//           break;
//       }
//       if (k == d)
//         Arr[d] = i;
//       else
//         continue;
//     }
//     if (M - 1 == d)
//     {
//       for (k = 0; k < M; k++)
//         printf("%d ", Arr[k]);
//       printf("\n");
//     }
//     else
//       Backtracking(Arr, N, M, d + 1);
//   }
// }

// int main()
// {
//   int N, M;
//   // 배열의 요소를 모두 0으로 초기화
//   int Arr[8] = {
//       0,
//   };
//   scanf("%d%d", &N, &M);

//   Backtracking(Arr, N, M, 0);
//   return 0;
// }