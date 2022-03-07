#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int add_num, minus_num, mul_num, dev_num, N;
int min, max;

//void Calculate(int cal_count, int *numbers, int result, int add_count, int minus_count, int mul_count, int dev_count);

void add(int a, int b, int *numbers, int cal_count, int add_count, int minus_count, int mul_count, int dev_count)
{
  if (add_count > add_num)
    return;

  Calculate(cal_count + 1, numbers, a + b, add_count, minus_count, mul_count, dev_count);
}
void minus(int a, int b, int *numbers, int cal_count, int add_count, int minus_count, int mul_count, int dev_count)
{
  if (minus_count > minus_num)
    return;

  Calculate(cal_count + 1, numbers, a - b, add_count, minus_count, mul_count, dev_count);
}
void mul(int a, int b, int *numbers, int cal_count, int add_count, int minus_count, int mul_count, int dev_count)
{
  if (mul_count > mul_num)
    return;

  Calculate(cal_count + 1, numbers, a * b, add_count, minus_count, mul_count, dev_count);
}
void dev(int a, int b, int *numbers, int cal_count, int add_count, int minus_count, int mul_count, int dev_count)
{
  if (dev_count > dev_num)
    return;

  Calculate(cal_count + 1, numbers, a / b, add_count, minus_count, mul_count, dev_count);
}

void Calculate(int cal_count, int *numbers, int result, int add_count, int minus_count, int mul_count, int dev_count)
{
  if (cal_count == N)
  {
    //printf("%d\n", result);            //각 연산을 마친 후 결과를 프린트해보세요
    if (result > max)
      max = result;
    if (result < min)
      min = result;
    return;
  }

  add(result, numbers[cal_count], numbers, cal_count, add_count + 1, minus_count, mul_count, dev_count);
  minus(result, numbers[cal_count], numbers, cal_count, add_count, minus_count + 1, mul_count, dev_count);
  mul(result, numbers[cal_count], numbers, cal_count, add_count, minus_count, mul_count + 1, dev_count);
  dev(result, numbers[cal_count], numbers, cal_count, add_count, minus_count, mul_count, dev_count + 1);
}

int main()
{
  int i;
  scanf("%d", &N);
  int *numbers = (int *)malloc(N * sizeof(int));
  for (i = 0; i < N; i++)
  {
    scanf("%d", &numbers[i]);
  }
  scanf("%d %d %d %d", &add_num, &minus_num, &mul_num, &dev_num);

  min = INT_MAX;
  max = INT_MIN;
  Calculate(1, numbers, numbers[0], 0, 0, 0, 0); //처음 들어가는 연산횟수는 1, 각 연산의 횟수는 0으로 넣는다

  printf("%d\n%d", max, min);

  free(numbers);
  return 0;
}