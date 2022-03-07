#include <stdio.h>

void fibonacci(int N)
{
  int last, current, result;
  current = 1, last = 0, result = 0;
  int i;
  for (i = 0; i <= N; i++)
  {
    last = current;
    current = result;
    result = last + current;
  }
  printf("%d %d\n", last, current);
}

int main()
{
  int N, M;
  int i;
  scanf("%d", &N);
  for (i = 0; i < N; i++)
  {
    scanf("%d", &M);
    fibonacci(M);
  }
}

// GARA
// #include <stdio.h>

// int main()
// {
//   int T, N, fibo[41][2];
//   scanf("%d", &T);

//   // 0-> fibo(0)만 호출
//   fibo[0][0] = 1;
//   fibo[0][1] = 0;

//   // 1 -> fibo(1)만 호출
//   fibo[1][0] = 0;
//   fibo[1][1] = 1;

//   // 2 -> fibo(1), fibo(0) 한번씩 호출
//   fibo[2][0] = 1;
//   fibo[2][1] = 1;

//   for (int i = 3; i <= 40; i++)
//   {
//     fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
//     fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
//   }

//   while (T--)
//   {
//     scanf("%d", &N);
//     printf("%d %d\n", fibo[N][0], fibo[N][1]);
//   }
//   return 0;
// }