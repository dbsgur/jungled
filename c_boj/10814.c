#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int age;
  char name[20];
  int idx;
} Member;

int compare(const void *first, const void *second)
{
  Member *a = (Member *)first;
  Member *b = (Member *)second;

  // age compare
  if (a->age > b->age)
    return 1;
  else if (a->age < b->age)
    return -1;
  else
  {
    // idx compare
    if (a->idx > b->idx)
      return 1;
    else
      return -1;
  }
  return 0;
}

int main()
{
  int i, n;
  Member *members;
  scanf("%d", &n);
  members = (Member *)calloc(n + 1, sizeof(Member));

  for (i = 0; i < n; i++)
  {
    scanf("%d %s", &members[i].age, members[i].name);
    members[i].idx = i;
  }

  qsort(members, n, sizeof(members[0]), compare);

  for (i = 0; i < n; i++)
  {
    printf("%d %s\n", members[i].age, members[i].name);
  }
  free(members);
  return 0;
}