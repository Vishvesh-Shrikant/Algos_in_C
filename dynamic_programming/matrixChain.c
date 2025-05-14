#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];

    // Cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1]; // Minimum cost to multiply matrices from A1 to An-1
}

int main() {
    int arr[] = {2,1,3,4}; // Matrix A1: 2 x 1, A2: 1 x 3, A3: 3 x 4
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n));
    return 0;
}
