//Dynamic
#include <stdio.h>
int p[20], w[20], v[20][20], n, m, i, j;
int max(int a, int b) { return a > b ? a : b; }
void knapsack(int n, int m, int w[20], int p[20], int v[20][20]) {
for (i = 0; i <= n; i++) {
for (j = 0; j <= m; j++) {
if (i == 0 || j == 0) {
v[i][j] = 0;
} else if (w[i] > j) {
v[i][j] = v[i - 1][j];
} else {
v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
}
}
}
}
void optimal(int v[20][20], int w[20], int p[20]) {
printf("\nDP Matrix:\n");
for (i = 0; i <= n; i++) {
for (j = 0; j <= m; j++) {
printf("%d\t", v[i][j]);
}
printf("\n");
}
printf("\nSelected objects:\n");
i = n;
j = m;
while (i > 0 && j > 0) {
if (v[i][j] != v[i - 1][j]) {
printf("Object %d selected (Weight: %d, Profit: %d)\n", i, w[i], p[i]);
j = j - w[i];
}
i--;
}
}
int main() {
printf("Enter number of objects: ");
scanf("%d", &n);
printf("Enter the weights of the objects:\n");
for (i = 1; i <= n; i++) {
scanf("%d", &w[i]);
}
printf("Enter the profits of the objects:\n");
for (i = 1; i <= n; i++) {
scanf("%d", &p[i]);
}
printf("Enter the capacity of the knapsack: ");
scanf("%d", &m);
knapsack(n, m, w, p, v);
optimal(v, w, p);
printf("\nThe maximum profit is: %d\n", v[n][m]);
return 0;
}