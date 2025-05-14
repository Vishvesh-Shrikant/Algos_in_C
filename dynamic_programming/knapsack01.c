#include <stdio.h>

// Function to return maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    // Create a 2D DP array to store max value at each n and W
    int dp[n + 1][W + 1];

    
    // Build the table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {           // i = items considered
        for (int w = 0; w <= W; w++) {       // w = current capacity
            if (i == 0 || w == 0)
                dp[i][w] = 0;                // Base case: no items or zero capacity
            else if (wt[i - 1] <= w)
                // Item can be included, take max of including or excluding it
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]], // Include item
                    dp[i - 1][w]                           // Exclude item
                );
            else
                // Item too heavy, exclude it
                dp[i][w] = dp[i - 1][w];
        }
    }

    // The bottom-right cell contains the maximum value that can be attained
    return dp[n][W];
}

int main() {
    // Example item values and weights
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;  // Maximum weight capacity of the knapsack
    int n = sizeof(val) / sizeof(val[0]);  // Number of items

    // Call knapsack function and print result
    printf("Maximum value in knapsack = %d\n", knapsack(W, wt, val, n));
    return 0;
}
