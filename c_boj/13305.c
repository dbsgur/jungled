#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i;
  int *dis;
  // int *liters;
  scanf("%d", &n);
  dis = (int *)malloc(sizeof(int) * (n - 1));
  // liters = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n - 1; i++)
  {
    scanf("%d", &dis[i]);
  }
  long long result = 0;
  int min, cur;
  for (i = 0; i < n - 1; i++)
  {
    scanf("%d", &cur);
    if (i == 0 || min > cur)
      min = cur;
    result += (long long)min * dis[i];
  }
  printf("%lld\n", result);
  free(dis);
  // free(liters);

  return 0;
}
// 58점
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//   int n, i;
//   int *dis;
//   int *liters;
//   scanf("%d", &n);
//   dis = (int *)malloc(sizeof(int) * (n - 1));
//   liters = (int *)malloc(sizeof(int) * n);
//   for (i = 0; i < n - 1; i++)
//   {
//     scanf("%d", &dis[i]);
//   }
//   for (i = 0; i < n; i++)
//   {
//     scanf("%d", &liters[i]);
//   }

//   long int m = liters[0];
//   long long result = dis[0] * m;
//   long int distance = 0;
//   for (i = 1; i < n - 1; i++)
//   {
//     if (liters[i] < m)
//     {
//       result += (distance * m);
//       distance = dis[i];
//       m = liters[i];
//     }
//     else
//     {
//       distance += dis[i];
//     }
//     if (i == (n - 2))
//     {
//       result += (long long)(distance * m);
//     }
//   }
//   printf("%lld\n", result);
//   free(dis);
//   free(liters);

//   return 0;
// }
