#include <stdio.h>
#include <stdlib.h>

int n, i, j;
int quad[64][64];

void cut(int a, int b, int c)
{
  int color = quad[a][b];
  for (i = a; i < a + c; i++)
  {
    for (j = b; j < b + c; j++)
    {
      if (color != quad[i][j])
      {
        color = -1;
        break;
      }
    }
  }
  if (color == -1)
  {
    putchar('(');
    c = c / 2;
    cut(a, b, c);
    cut(a, b + c, c);
    cut(a + c, b, c);
    cut(a + c, b + c, c);
    putchar(')');
  }
  else if (color == 1)
  {
    printf("1");
  }
  else
  {
    printf("0");
  }
}

int main()
{

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      // 하나씩 입력받기
      scanf("%1d", &quad[i][j]);
    }
  }

  cut(0, 0, n);
  printf("\n");

  return 0;
}