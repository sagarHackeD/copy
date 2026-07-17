// greedyKnapsack
#include <stdio.h>
int main() {
double n, m, rc = 0, temp;
double profit = 0;
int i, j;
double w[10];
double p[10];
double pp[10];
double x[10];
printf("Enter number of objects: ");
scanf("%lf", &n);
printf("Enter capacity of knapsack: ");
scanf("%lf", &m);
for (i = 0; i < n; i++) {
printf("\nEnter the weight and profit of object %d:\n", i + 1);
scanf("%lf", &w[i]);
scanf("%lf", &p[i]);
pp[i] = p[i] / w[i];
}
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (pp[j] < pp[j + 1]) {
temp = pp[j];
pp[j] = pp[j + 1];
pp[j + 1] = temp;
temp = w[j];
w[j] = w[j + 1];
w[j + 1] = temp;
temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
printf("\nSorted items by profit/weight ratio:\n");
printf("P/W\tWeight\tProfit\n");
for (i = 0; i < n; i++) {
printf("%.2lf\t%.2lf\t%.2lf\n", pp[i], w[i], p[i]);
}
for (i = 0; i < n; i++) {
x[i] = 0;
}
rc = m;
for (i = 0; i < n && rc > 0; i++) {
if (w[i] > rc) {
x[i] = rc / w[i];
} else {
x[i] = 1;
}
profit += x[i] * p[i];
printf("Selected %.2lf of item %d (Profit: %.2lf)\n", x[i], i + 1,
x[i] * p[i]);
rc -= x[i] * w[i];
}
printf("\nTotal profit earned: %.2lf\n", profit);
return 0;
}