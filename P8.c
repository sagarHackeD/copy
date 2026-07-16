#include <stdio.h>

void subset(int cs, int k, int r) {
  int i;

  if (k >= n) {
    return;
  }

  x[k] = 1;

  if (cs + w[k] == d) {
    printf("\nSubset %d:\n", ++count);
    for (i = 0; i <= k; i++) {
      if (x[i] == 1) {
        printf("%d\t", w[i]);
      }
    }
    printf("\n");
  } else if ((k + 1 < n) && (cs + w[k] + w[k + 1] <= d)) {
    subset(cs + w[k], k + 1, r - w[k]);
  }

  if ((k + 1 < n) && (cs + r - w[k] >= d) && (cs + w[k + 1] <= d)) {
    x[k] = 0;
    subset(cs, k + 1, r - w[k]);
  }
}
int x[10], w[10], d, count = 0, n;

int main() {
  int i, sum = 0;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements in ascending order:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }

  printf("Enter the required sum: ");
  scanf("%d", &d);

  for (i = 0; i < n; i++) {
    sum += w[i];
  }

  if (sum < d) {
    printf("No Solution\n");
    return 0;
  }

  subset(0, 0, sum);

  if (count == 0) {
    printf("No Solution\n");
  }

  return 0;
}

