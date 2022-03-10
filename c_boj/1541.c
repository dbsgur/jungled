#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str[51];
  int arr[25] = {
      0,
  };
  scanf("%s", str);
  int len = strlen(str);
  int i = 0, j = 0, k = 0, temp = 0, sum = 0, result = 0;

  for (i = 0; i <= len; i++)
  {
    if (str[i] == '-' || i == len)
    {
      sum = sum + temp;
      arr[j] = sum;
      j++;
      temp = 0;
      sum = 0;
    }
    else if (str[i] == '+')
    {
      sum += temp;
      temp = 0;
    }
    else
    {
      // temp += atoi(str[i]);
      // 10의 자릿수 더하기
      temp = temp * 10;
      // 1의 자릿수 더하기
      // 아스키 코드상 1-> 49 2->50 ... 임 그래서 '0'을 빼주면 숫자가 됨
      // ex ) 1- 0 = 1 *ASCII> 1->49 0->48    1-0 = 49-48
      temp = temp + str[i] - '0';
    }
  }
  result = arr[0];
  for (i = 1; i < j; i++)
  {
    result -= arr[i];
  }
  printf("%d\n", result);
  return 0;
}