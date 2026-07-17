// Kruskal
#include <stdio.h>
int ne = 1, min_cost = 0;
int main() {
int n, i, j, min;
int a, b, u, v;
int cost[20][20], parent[20];
printf("Enter the number of vertices: ");
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
parent[i] = 0;
}
printf("\nThe edges of Minimum Spanning Tree are:\n");
while (ne < n) {
min = 999;
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (cost[i][j] < min) {
min = cost[i][j];
a = u = i;
b = v = j;
}
}
}
while (parent[u]) {
u = parent[u];
}
while (parent[v]) {
v = parent[v];
}
if (u != v) {
printf("Edge %d : (%d -> %d) = %d\n", ne++, a, b, min);
min_cost += min;
parent[v] = u;
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
// Edge 1 : (2 -> 3) = 1
// Edge 2 : (4 -> 5) = 2
// Edge 3 : (2 -> 4) = 3
// Edge 4 : (1 -> 2) = 5