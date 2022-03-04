#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int x;
  int y;
} coord;

// x[0]오름차순 정렬
// x[1]오름차순 정렬
int compare(const void *first, const void *second)
{
  coord *a = (coord *)first;
  coord *b = (coord *)second;
  // a.x b.x라는 뜻
  if (a->x < b->x)
    return -1;
  else if (a->x > b->x)
    return 1;
  else
  {
    if (a->y < b->y)
      return -1;
    else
      return 1;
  }
  return 0;
}

int main()
{
  int i, n;
  coord *list;
  // 입력받고
  scanf("%d", &n);
  list = (coord *)malloc(n * sizeof(coord));
  // list = malloc(n * sizeof(coord));
  // 위도 되는데 차이가 뭘까요?

  for (i = 0; i < n; i++)
  {
    scanf("%d %d", &list[i].x, &list[i].y);
  }
  // SORT
  qsort(list, n, sizeof(list[0]), compare);

  // 출력
  for (i = 0; i < n; i++)
  {
    printf("%d %d\n", list[i].x, list[i].y);
  }
  return 0;
}