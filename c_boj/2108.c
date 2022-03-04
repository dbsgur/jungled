// 실수형 연산을 할 때는 float보다는 double
// 반올림 할 때는 %.0f 로 출력을 때려버리는 방법도 있다
// 입력되는 수의 범위가 크지 않을 때는 배열을 활용하는 방법도 생각해보자

#define _CRT_SECURE_NO_WARNINGS // 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *first, const void *second)
{
  int *a = (int *)first;
  int *b = (int *)second;

  if (*a < *b)
    return -1;
  else if (*a > *b)
    return 1;
  else
    return 0;
}

int arith(int list[], int n)
{
  double sum = 0;

  for (int i = 0; i < n; i++)
  {
    sum += (list[i]);
  }
  // Average
  return round(sum / n);
}

// 중간값
int median(int list[], int n)
{
  if (n == 1)
    return list[0];
  else
    return list[(n + 1) / 2 - 1];
}
//최빈값
int Mode(int list[], int n)
{
  // 배열을 모두 0으로 초기화
  int ar[8001] = {0};
  // int i, idx, max = 0, cnt = 0;
  int i, idx, max = 0, cnt = 0;

  for (i = 0; i < n; i++)
  {
    idx = list[i] + 4000;
    ar[idx] += 1;

    if (ar[idx] > max)
      max = ar[idx];
  }
  for (i = 0, idx = 0; i < 8001; i++)
  {
    if (ar[i] == 0)
      continue;
    if (ar[i] == max)
    {
      if (cnt == 0)
      {
        idx = i;
        cnt += 1;
      }
      else if (cnt == 1)
      {
        idx = i;
        break;
      }
    }
  }
  return idx - 4000;
}

int range(int list[], int n)
{
  int max = list[n - 1];
  int min = list[0];

  return max - min;
}

int main()
{
  int i, n;
  int *list;

  scanf("%d", &n);
  list = (int *)calloc(n, sizeof(int));

  for (i = 0; i < n; i++)
  {
    scanf("%d", &list[i]);
  }

  // 퀵 정렬 -> 정렬할 배열, 요소 갯수, 요소 크기, 비교함수를 넣어준다
  qsort(list, n, sizeof(list[0]), compare);

  printf("%d\n", arith(list, n));
  printf("%d\n", median(list, n));
  printf("%d\n", Mode(list, n));
  printf("%d\n", range(list, n));

  return 0;
}