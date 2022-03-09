#include <stdio.h>

int w[102][102][102] = {
    0,
};

int function(int a, int b, int c)
{
  if (w[a][b][c] == 0) //초기 값이면
  {
    if (a <= 50 || b <= 50 || c <= 50)
    {
      return (w[a][b][c] = 1);
    }
    else if (a > 70 || b > 70 || c > 70)
    {
      return (w[a][b][c] = function(70, 70, 70));
    }
    else if (a < b && b < c)
    {
      return (w[a][b][c] = function(a, b, c - 1) + function(a, b - 1, c - 1) - function(a, b - 1, c));
    }
    else
    {
      return (w[a][b][c] = function(a - 1, b, c) + function(a - 1, b - 1, c) + function(a - 1, b, c - 1) - function(a - 1, b - 1, c - 1));
    }
  }
  else //이미 계산된 값 이면
  {
    return w[a][b][c];
  }
}

int main()
{

  int d = 0;
  int e = 0;
  int f = 0;
  while (1)
  {
    scanf("%d %d %d", &d, &e, &f);
    if (d == -1 && e == -1 && f == -1)
    {
      break;
    }

    printf("w(%d, %d, %d) = %d\n", d, e, f, function(d + 50, e + 50, f + 50));
  }
}