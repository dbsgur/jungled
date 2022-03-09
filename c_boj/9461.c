#include <stdio.h>
#include <stdlib.h>

long long int *Arr;

int main()
{
  int T, N;
  scanf("%d", &T);

  for (int i = 0; i < T; i++)
  {
    scanf("%d", &N);

    Arr = (long long int *)malloc(sizeof(long long int) * N);
    for (int i = 0; i < N; i++)
    {
      if (i == 0)
        Arr[0] = 1;
      else if (i == 1)
        Arr[1] = 1;
      else if (i == 2)
        Arr[2] = 1;
      else if (i == 3)
        Arr[3] = 2;
      else if (i == 4)
        Arr[4] = 2;
      else
        Arr[i] = Arr[i - 5] + Arr[i - 1];
    }
    printf("%lld\n", Arr[N - 1]);
    free(Arr);
  }

  return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//   int n, i, num;
//   long long int *wh;
//   scanf("%d", &n);
//   wh = (long long int *)calloc(101, sizeof(long long int));

//   wh[1] = 1;
//   wh[2] = 1;
//   wh[3] = 1;
//   for (i = 1; i < 99; i++)
//   {
//     wh[i + 3] = wh[i] + wh[i + 1];
//   }
//   for (i = 0; i < n; i++)
//   {
//     scanf("%d", &num);
//     printf("%lld", wh[num]);
//   }

//   free(wh);
//   return 0;
// }