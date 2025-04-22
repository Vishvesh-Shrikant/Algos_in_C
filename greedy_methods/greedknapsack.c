#include <stdio.h>
#define max 7
int p[max], w[max];

float pw[max];

void sort() {
  int i, j, temp1;
  float temp2;
  for (i = 0; i < max; i++) {
    for (j = i + 1; j < max; j++)
      if (pw[i] < pw[j]) {
        // swapping the profit values
        temp1 = p[i];
        p[i] = p[j];
        p[j] = temp1;

        // swapping the weight values
        temp1 = w[i];
        w[i] = w[j];
        w[j] = temp1;

        // swapping the profit/weight values
        temp2 = pw[i];
        pw[i] = pw[j];
        pw[j] = temp2;
      }
  }
}

float knapsack(int m) {
  int i = 0;
  float fraction, profit = 0;

  //calculating the profit/weight ratio
  for (i = 0; i < max; i++) {
    pw[i] = (float)p[i] / w[i];
  }
  //sorts the profit/weight ratio in descending order and also the weights and profits
  sort();

  // calculating the maximum profit
  i=0;
  while (w[i] <= m) {
    profit = profit + (float)p[i]; 
    m = m - w[i];
    i++;
  }
  // if the capacity is not full
  if (i < max) {
    fraction = (float)m / w[i];
    profit = profit + (fraction * p[i]);
  }

  return profit;
}

int main()
{
  int m;
  printf("\nEnter the capacity of the knapsack: \n");
  scanf("%d", &m);
  //taking weights as input 
  printf("\nEnter the weights of the items: \n");
  for (int i = 0; i < max; i++) {
    scanf("%d", &w[i]);
  }

  //taking profits as input
  printf("\nEnter the profits of the items: \n");
  for (int i = 0; i < max; i++) {
    scanf("%d", &p[i]);
  }

  //printing the maximum profit 
  printf("\nThe maximum profit is: %f\n", knapsack(m));
  return 0;
}

