#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int len;
  char str[51];
} Word;

void merge(Word list[], int left, int mid, int right)
{
  Word *tmp_list;
  int i, j, k;

  tmp_list = (Word *)calloc(right + 1, sizeof(Word)); // 임시 배열 할당

  i = k = left;
  j = mid + 1;

  while (i <= mid && j <= right)
  {
    if (list[i].len < list[j].len)
      tmp_list[k++] = list[i++];
    else if (list[j].len < list[i].len)
      tmp_list[k++] = list[j++];
    else /* 길이가 같은 경우 사전순 정렬 */
    {
      if (strcmp(list[i].str, list[j].str) < 0)
        tmp_list[k++] = list[i++];
      else
        tmp_list[k++] = list[j++];
    }
  }
  while (i <= mid)
  {
    tmp_list[k++] = list[i++];
  }
  while (j <= right)
  {
    tmp_list[k++] = list[j++];
  }

  for (k = left; k <= right; k++)
  {
    list[k] = tmp_list[k];
  }

  free(tmp_list);
}

void merge_sort(Word list[], int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    merge_sort(list, left, mid);
    merge_sort(list, mid + 1, right);
    merge(list, left, mid, right);
  }
}

int main()
{
  int i, j, n;
  Word *text;

  scanf("%d", &n);

  text = (Word *)calloc(n + 1, sizeof(Word));

  for (i = 0; i < n; i++)
  {
    scanf(" %s", text[i].str);
    text[i].len = strlen(text[i].str);

    /*중복 제거*/
    for (j = 0; j < i; j++)
    {
      if (strcmp(text[i].str, text[j].str) == 0)
      {
        i -= 1;
        n -= 1;
        break;
      }
    }
  }

  merge_sort(text, 0, n - 1);

  for (i = 0; i < n; i++)
  {
    printf("%s\n", text[i].str);
  }

  return 0;
}

// merge < quick 시간 약 1.8배 메모리 약 2배