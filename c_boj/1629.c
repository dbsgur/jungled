#include <stdio.h>

int a, b, c;

int multi(int x, int y)
{
  if (y == 1)
  {
    return x % c;
  }
  else
  {
    long long tmp = multi(x, y / 2);
    if (y % 2 == 0)
    {
      return (tmp * tmp) % c;
    }
    else
    {
      return ((tmp * tmp) % c * a) % c;
    }
  }
}

int main()
{

  scanf("%d %d %d", &a, &b, &c);
  // printf("####");
  // printf("%d %d %d\n\n\n\n", a, b, c);
  int result = multi(a % c, b);
  printf("%d", result);
  return 0;
}