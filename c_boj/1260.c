#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1001
int DFS_V[MAX_VERTICES] = {
    0,
};
int BFS_V[MAX_VERTICES] = {
    0,
};
int graph[MAX_VERTICES][MAX_VERTICES] = {
    0,
};
int queue[MAX_VERTICES] = {
    0,
};

void dfs(int v, int vertices);
void bfs(int v, int vertices);

int main()
{
  // 정점의 개수 N, 간선의 개수 M, 탐색을 시작할 정점의 번호 V
  int N, M, V, i, j;
  scanf("%d %d %d", &N, &M, &V);

  while (M--)
  {
    scanf("%d %d", &i, &j);
    graph[i][j] = 1;
    graph[j][i] = 1;
  }

  dfs(V, N);
  printf("\n");
  bfs(V, N);

  return 0;
}

void dfs(int v, int vertices)
{
  int w;
  DFS_V[v] = 1;
  printf("%d ", v);
  for (w = 1; w <= vertices; w++)
  {
    if (graph[v][w] == 1 && DFS_V[w] == 0)
    {
      dfs(w, vertices);
    }
  }
}

void bfs(int v, int vertices)
{
  int w;
  int front, rear, pop;
  front = rear = 0;
  printf("%d ", v);
  BFS_V[v] = 1;
  queue[0] = v;
  rear++;
  while (front < rear)
  {
    pop = queue[front++];
    for (w = 1; w <= vertices; w++)
    {
      if (graph[pop][w] == 1 && BFS_V[w] == 0)
      {
        printf("%d ", w);
        queue[rear++] = w;
        BFS_V[w] = 1;
      }
    }
  }
}