// ************************
// **** genious's CODE ****
// ************************

#include <stdio.h>
char p[100001], x[100001];
int all_zero(int front, int rear)
{
  for (int i = front; i <= rear; i++)
    if (x[i])
      return 0;
  return 1;
}
int main()
{
  int T, n;
  scanf("%d", &T);
  while (T--)
  {
    int error = 0, reverse = 0;
    scanf("%s %d ", p, &n);
    int front = 0, rear = n - 1;

    getchar();
    for (int i = 0; i < n; i++)
      scanf("%d,", &x[i]);
    getchar();

    for (int i = 0; p[i] != '\0'; i++)
    {
      if (p[i] == 'R')
        reverse = reverse ? 0 : 1;
      else
      {
        if (!n)
        {
          error++;
          break;
        }
        !reverse ? (front++) : (rear--);
        n--;
      }
    }
    if (error)
      puts("error");
    else if (all_zero(front, rear))
      puts("[]");
    else
    {
      putchar('[');
      if (!reverse)
        for (int i = front; i <= rear; i++)
          printf("%d%c", x[i], i == rear ? ']' : ',');
      else
        for (int i = rear; i >= front; i--)
          printf("%d%c", x[i], i == front ? ']' : ',');
      putchar(10);
    }
  }
}