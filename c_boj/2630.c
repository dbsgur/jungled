#include <stdio.h>
#include <stdlib.h>

int n;
int i, j, x, y;
int paper[128][128];
// int cut(x, y, n);
int white = 0, blue = 0;

void cut(int a, int b, int c)
{
  int color = paper[a][b];
  for (i = a; i < a + c; i++)
  {
    for (j = b; j < b + c; j++)
    {
      if (color != paper[i][j])
      {
        cut(a, b, c / 2);
        cut(a + c / 2, b, c / 2);
        cut(a, b + c / 2, c / 2);
        cut(a + c / 2, b + c / 2, c / 2);
        return;
      }
    }
  }
  if (color == 0)
    white += 1;
  else
    blue += 1;
}

int main()
{
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &paper[i][j]);
    }
  }

  cut(0, 0, n);
  printf("%d\n", white);
  printf("%d\n", blue);
  return 0;
}
