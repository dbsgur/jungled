#include <stdio.h>
#include <stdlib.h>

int pc[101][101];
int visited[101];
int virus;

void checkConnect(int n, int k)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (visited[i] == 0 && pc[k][i] == 1)
    {
      visited[i] = 1;
      checkConnect(n, i);
      virus++;
    }
  }
}

int main()
{
  int N, M, i;
  int x, y;
  scanf("%d", &N);
  scanf("%d", &M);
  for (i = 0; i < M; i++)
  {
    scanf("%d %d", &x, &y);
    pc[x - 1][y - 1] = 1;
    pc[y - 1][x - 1] = 1;
  }
  visited[0] = 1;
  checkConnect(N, 0);

  printf("%d\n", virus);

  return 0;
}