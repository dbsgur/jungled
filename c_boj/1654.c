#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N, K, i;
  scanf("%d %d", &K, &N);

  long long int *lans;
  long long int end = 0;
  lans = (long long int *)malloc(sizeof(long long int) * K);
  for (i = 0; i < K; i++)
  {
    scanf("%d", &lans[i]);
  }

  for (i = 0; i < K; i++)
  {

    if (lans[i] > end)
      end = lans[i];
  }

  long long int start = 1;
  long long int mid, lines;
  while (start <= end)
  {
    mid = (start + end) / 2;
    lines = 0;
    for (i = 0; i < K; i++)
    {
      lines += (lans[i] / mid);
    }
    if (lines >= N)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  printf("%d\n", end);
  free(lans);
  return 0;
}