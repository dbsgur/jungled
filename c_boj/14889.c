#include <stdio.h>
#include <stdlib.h>

int N;           // 전체 멤버의 수
int **s;         // Synergy를 저장하는 배열
int gap = 10000; // synergey차의 최소 값을 저장하는 변수
int *team1;      // 팀 1의 구성 멤버를 저장하는 배열
int *team2;      // 팀 2의 구성 멤버를 저장하는 배열
int *flag;       // 팀원으로 할당했음을 표시하는 배열

int calculatePower()
{
  int i, j;
  int power1 = 0; // 팀 1의 시너지 합을 계싼
  for (i = 1; i < N / 2; i++)
  {
    for (j = i + 1; j <= N / 2; j++)
    {
      power1 += (s[team1[i]][team1[j]] + s[team1[j]][team1[i]]);
    }
  }
  int power2 = 0; // 팀 2의 시너지 합을 계산
  for (i = 1; i < N / 2; i++)
  {
    for (j = i + 1; j <= N / 2; j++)
    {
      power2 += (s[team2[i]][team2[j]] + s[team2[j]][team2[i]]);
    }
  }
  return power1 > power2 ? power1 - power2 : power2 - power1;
}

void partition(int n)
{           // 팀원을 구성한다. 1명씩 추가하고 모두 구성한 경우
  int i, j; // 시너지의 합의 차의 최소 값을 얻는다.
  // team1 구성완료
  if (n == (N / 2 + 1))
  {
    j = 1;
    // team2 구성완료
    for (i = 1; i <= N; i++)
    {
      if (flag[i] == 0)
      {
        team2[j++] = i;
      }
    }
    int diff = calculatePower(); // 시너지 합의 차이를 계산
    // 최소값 갱신 (있어야하나 ?)
    if (gap > diff)
    {
      gap = diff;
    }
  }
  else
  {
    // 팀원을 한명씩 할당
    for (i = 1; i < N; i++)
    {
      // 기존에 할당하지 않았고, 할당한 팀원보다 id가 큰 경우만 할당한다.
      if (flag[i] == 0 && team1[n - 1] < i)
      {
        team1[n] = i;
        flag[i] = 1;
        partition(n + 1);
        flag[i] = 0;
      }
    }
  }
}

int main()
{
  int i, j;
  scanf("%d", &N);
  // s = (int*)calloc(N+1, sizeof(int));
  s = calloc(N + 1, sizeof(int *)); // 시너지를 저장하는 배열의 메모리를 할당
  for (i = 1; i <= N; i++)
  {
    s[i] = calloc(N + 1, sizeof(int));
  }
  team1 = calloc(N / 2 + 1, sizeof(int));
  team2 = calloc(N / 2 + 1, sizeof(int));
  flag = calloc(N + 1, sizeof(int));

  // 시너지 정보를 입력
  for (i = 1; i <= N; i++)
  {
    for (j = 1; j <= N; j++)
    {
      scanf("%d", &s[i][j]);
    }
  }

  partition(1);        // 팀원 할당 시작
  printf("%d\n", gap); // 시너지 합의 차에 대한 최소 값을 출력

  free(team1);
  free(team2);
  free(flag);
  for (i = 0; i <= N; i++)
  {
    free(s[i]);
  }
  free(s);

  return 0;
}