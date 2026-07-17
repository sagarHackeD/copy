#include <stdio.h>
int ne = 1, min_cost = 0;
int main() {
int n, i, j, min;
int cost[20][20], a, b, u, v, source;
int visited[20];
printf("Enter the number of nodes: ");
scanf("%d", &n);
printf("Enter the cost matrix:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
scanf("%d", &cost[i][j]);
if (cost[i][j] == 0) {
cost[i][j] = 999;
}
}
}
for (i = 1; i <= n; i++) {
visited[i] = 0;
}
printf("Enter the root node: ");
scanf("%d", &source);
visited[source] = 1;
printf("\nMinimum Cost Spanning Tree:\n");
while (ne < n) {
min = 999;
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (cost[i][j] < min) {
if (visited[i] != 0) {
min = cost[i][j];
a = u = i;
b = v = j;
}
}
}
}
if (visited[u] == 0 || visited[v] == 0) {
printf("Edge %d : (%d -> %d) = %d\n", ne++, a, b, min);
min_cost += min;
visited[b] = 1;
}
cost[a][b] = cost[b][a] = 999;
}
printf("\nMinimum Cost = %d\n", min_cost);
return 0;
}
// 0 5 0 6 0
// 5 0 1 3 0
// 0 1 0 4 6
// 6 3 4 0 2
// 0 0 6 2 0