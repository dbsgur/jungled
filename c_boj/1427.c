#include <stdio.h>
#include <string.h>
// 입력 받는다

// 배열에 저장한다. ptr ? fuck uuuuuuuuuu

// 내림차순으로 출력한다.

int main()
{
  char N[11] = {NULL};

  int tmp;
  // gets > 배열을 사용해서 문자열 입력받기
  // gets 함수의 매개변수인 buffer에 사용자가 입력한 문자열이 저장되기 때문에
  //char 형식의 배열로 선언된 변수나 malloc로 할당된 메모리의 주소를 사용해야한다.
  gets(N);

  for (int i = 0; i < strlen(N) - 1; i++)
  {
    for (int j = i; j < strlen(N); j++)
    {
      if (N[i] < N[j])
      {
        tmp = N[i];
        N[i] = N[j];
        N[j] = tmp;
      }
    }
  }
  puts(N);

  return 0;
}
