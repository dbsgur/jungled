#include <stdio.h>
#include <stdlib.h>

int main()
{

  // N : amount of trees , M : want amount of tree
  int N, M, i;
  int *trees;
  scanf("%d %d", &N, &M);
  trees = (int *)malloc(sizeof(int) * N);

  int start = 1;
  int end = 0;
  for (i = 0; i < N; i++)
  {
    scanf("%d", &trees[i]);
    if (trees[i] > end)
      end = trees[i];
  }
  long long int height;
  int mid;
  while (start <= end)
  {
    height = 0;
    mid = (start + end) / 2;
    for (i = 0; i < N; i++)
    {
      if (height > M)
        break;
      if (trees[i] > mid)
        height += (trees[i] - mid);
      else
        continue;
    }
    if (height >= M)
      start = mid + 1;
    else
      end = mid - 1;
  }
  printf("%d\n", end);
  free(trees);

  return 0;
}