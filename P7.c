#include <stdio.h>

#define MAX 50

int p[MAX], w[MAX], n, m, i;
double x[MAX], maxprofit;

void greedyKnapsack(int n, int w[], int p[], int m) {
  double ratio[MAX], temp;
  int temp2, currentWeight = 0;
  int i, j;

  // Calculate profit/weight ratio
  for (i = 0; i < n; i++) {
    ratio[i] = (double)p[i] / w[i];
  }

  // Sort in descending order of ratio
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (ratio[i] < ratio[j]) {
        temp = ratio[i];
        ratio[i] = ratio[j];
        ratio[j] = temp;

        temp2 = w[i];
        w[i] = w[j];
        w[j] = temp2;

        temp2 = p[i];
        p[i] = p[j];
        p[j] = temp2;
      }
    }
  }

  for (i = 0; i < n; i++) {
    x[i] = 0.0;
  }

  maxprofit = 0.0;

  // Fill knapsack
  for (i = 0; i < n; i++) {
    if (currentWeight + w[i] <= m) {
      x[i] = 1.0;
      currentWeight += w[i];
      maxprofit += p[i];
    } else {
      x[i] = (double)(m - currentWeight) / w[i];
      maxprofit += x[i] * p[i];
      break;
    }
  }

  printf("\nOptimal Solution for Greedy Method = %.2f\n", maxprofit);

  printf("Solution Vector:\n");
  for (i = 0; i < n; i++) {
    printf("%.2f ", x[i]);
  }
}

int main() {
  printf("Enter the number of objects: ");
  scanf("%d", &n);

  printf("Enter the objects' weights:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }

  printf("Enter the objects' profits:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }

  printf("Enter the maximum capacity: ");
  scanf("%d", &m);

  greedyKnapsack(n, w, p, m);

  return 0;
}