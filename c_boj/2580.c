#include <stdio.h>

#define N 9
#define UNASSIGNED 0

// row 행 검사 >> 해당 값(num) 찾으면 1 리턴
int is_exist_row(int grid[N][N], int row, int num)
{
  int col;

  col = 0;
  while (col < 9)
  {
    if (grid[row][col] == num)
    {
      return (1);
    }
    col++;
  }
  return (0);
}

// col 열 검사 >> 해당 값(num) 찾으면 1 리턴
int is_exist_col(int grid[N][N], int col, int num)
{
  int row;
  row = 0;
  while (row < 9)
  {
    if (grid[row][col] == num)
    {
      return (1);
    }
    row++;
  }
  return (0);
}

// box 검사 >> 해당 값(num) 찾으면 1 리턴
int is_exist_box(int grid[N][N], int startRow, int startCol, int num)
{
  int row;
  int col;

  row = 0;
  while (row < 3)
  {
    col = 0;
    while (col < 3)
    {
      if (grid[row + startRow][col + startCol] == num)
      {
        return (1);
      }
      col++;
    }
    row++;
  }
  return (0);
}

int is_safe_num(int grid[N][N], int row, int col, int num)
{
  return !is_exist_row(grid, row, num) && !is_exist_col(grid, col, num) && !is_exist_box(grid, row - (row % 3), col - (col % 3), num);
}

int find_unassigned(int grid[N][N], int *row, int *col)
{

  *row = 0;
  while (*row < N)
  {
    *col = 0;
    while (*col < N)
    {
      if (grid[*row][*col] == 0)
      {
        return (1);
      }
      (*col)++;
    }
    (*row)++;
  }
  return (0);
}

int solve(int grid[N][N])
{
  int row = 0;
  int col = 0;

  if (!find_unassigned(grid, &row, &col))
  {
    return (1);
  }
  int num;
  num = 1;
  while (num <= N)
  {
    if (is_safe_num(grid, row, col, num))
    {
      grid[row][col] = num;

      if (solve(grid))
      {
        return (1);
      }
      grid[row][col] = UNASSIGNED;
    }
    num++;
  }
  return (0);
}

void print_grid(int grid[N][N])
{
  int row;
  int col
      row = 0;
  while (row < N)
  {
    col = 0;
    while (col < N)
    {
      printf("%d ", grid[row][col]);
      col++;
    }
    row++;
    printf("\n");
  }
}

int main()
{
  int grid[N][N];

  int i;
  int j;

  i = 0;
  while (i < N)
  {
    j = 0;
    while (j < N)
    {
      scanf("%d", &*(*(grid + i) + j));
      j++;
    }
    i++;
  }
  if (solve(gird))
  {
    print_grid(grid);
  }
  else
  {
    printf("no solution");
  }
  return 0;
}