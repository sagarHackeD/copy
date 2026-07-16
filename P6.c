#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

// Function to solve 0/1 Knapsack
int knapsack(int W, int wt[], int val[], int n) {
  int i, w;
  int K[n + 1][W + 1];

  // Build table K[][] in bottom-up manner
  for (i = 0; i <= n; i++) {
    for (w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        K[i][w] = 0;
      } else if (wt[i - 1] <= w) {
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      } else {
        K[i][w] = K[i - 1][w];
      }
    }
  }

  // Display DP Table
  printf("\nDP Table:\n");
  for (i = 0; i <= n; i++) {
    for (w = 0; w <= W; w++) {
      printf("%3d ", K[i][w]);
    }
    printf("\n");
  }

  return K[n][W];
}

int main() {
  int val[10], wt[10];
  int m, n, i;

  printf("Enter the number of objects: ");
  scanf("%d", &n);

  printf("Enter the knapsack capacity: ");
  scanf("%d", &m);

  printf("Enter profit and weight of each object:\n");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &val[i], &wt[i]);
  }

  printf("\nMaximum Value = %d\n", knapsack(m, wt, val, n));

  return 0;
}