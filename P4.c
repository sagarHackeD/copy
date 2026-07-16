#include <stdio.h>

void dij(int source, int cost[20][20], int visited[20], int d[20], int n);

int main() {
  int i, j, n;
  int visited[20], source, cost[20][20], d[20];

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter the cost adjacency matrix:\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }

  printf("Enter the source node: ");
  scanf("%d", &source);

  dij(source, cost, visited, d, n);

  printf("\nShortest distances from source node %d:\n", source);
  for (i = 1; i <= n; i++) {
    if (i != source) {
      printf("To %d = %d\n", i, d[i]);
    }
  }

  return 0;
}

void dij(int source, int cost[20][20], int visited[20], int d[20], int n) {
  int i, j, min, u = 0, w;

  for (i = 1; i <= n; i++) {
    visited[i] = 0;
    d[i] = cost[source][i];
  }

  visited[source] = 1;
  d[source] = 0;

  for (j = 2; j <= n; j++) {
    min = 999;

    for (i = 1; i <= n; i++) {
      if (!visited[i] && d[i] < min) {
        min = d[i];
        u = i;
      }
    }

    visited[u] = 1;

    for (w = 1; w <= n; w++) {
      if (!visited[w] && cost[u][w] != 999) {
        if (d[w] > d[u] + cost[u][w]) {
          d[w] = d[u] + cost[u][w];
        }
      }
    }
  }
}