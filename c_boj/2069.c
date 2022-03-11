#include <stdio.h>

int gcd(a, b)
{
  if (b == 0)
  {
    return a;
  }
  return gcd(b, a % b);
}
int main()
{
  int n, m, result;
  scanf("%d %d", &n, &m);
  if (n >= m)
  {
    result = gcd(n, m);
  }
  else
  {
    result = gcd(m, n);
  }
  printf("%d\n", result);
  printf("%d\n", (n * m) / result);
  return 0;
}
