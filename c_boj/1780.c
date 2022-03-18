#include <stdio.h>
#include <stdlib.h>

int amount;

int **matrix;

int i, j;

int cntMinusOne = 0;
int cntZero = 0;
int cntOne = 0;

void cut(int x, int y, int n);

int main()
{
  scanf("%d", &amount);
  // int **matrix;
  matrix = (int **)malloc(sizeof(int *) * (amount + 1));
  for (i = 0; i < amount; i++)
  {
    matrix[i] = (int *)malloc(sizeof(int) * (amount + 1));
  }
  for (i = 0; i < amount; i++)
  {
    // matrix[i] = (int *)malloc(sizeof(int) * amount);
    for (j = 0; j < amount; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  cut(0, 0, amount);
  printf("%d\n%d\n%d", cntMinusOne, cntZero, cntOne);

  // print good work
  // printf("%d", matrix[8][8]);
  // printf("%d", matrix[0][0]);
  // for (i = 0; i < amount; i++)
  // {

  //   for (j = 0; j < amount; j++)
  //   {
  //     printf("%d", matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  for (i = 0; i < amount; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}

void cut(x, y, n)
{
  // printf("%d", matrix[8][8]);
  // printf("%d", matrix[0][0]);
  // printf("%d", matrix[x][y]);
  // printf("%d", n);
  int k, l;
  int color = matrix[x][y];
  for (i = x; i < x + n; i++)
  {
    for (j = y; j < y + n; i++)
    {
      if (color != matrix[i][j])
      {
        // n = n / 3;
        for (k = 0; k < 3; k++)
        {
          for (l = 0; l < 3; l++)
          {
            cut(x + (n / 3 * k), y + (n / 3 * l), n);
          }
        }
        return;
      }
    }
  }
  if (color == -1)
  {
    cntMinusOne += 1;
  }
  else if (color == 0)
  {
    cntOne += 1;
  }
  else
  {
    cntOne += 1;
  }
}
