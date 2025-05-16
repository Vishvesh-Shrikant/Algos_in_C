#include <stdio.h>
#include <stdbool.h>

void printSubset(int subset[], int size) {
    printf("Subset found: ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("\n");
}

bool isSubsetSum(int set[], int n, int sum, int subset[], int subsetSize) {
    // Base Cases
    if (sum == 0) {
        printSubset(subset, subsetSize);
        return true; // If you want all subsets, don't return here
    }
    if (n == 0)
        return false;

    // If last element is greater than sum, skip it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum, subset, subsetSize);

    // (a) Include the last element
    subset[subsetSize] = set[n - 1];
    bool include = isSubsetSum(set, n - 1, sum - set[n - 1], subset, subsetSize + 1);

    // (b) Exclude the last element
    bool exclude = isSubsetSum(set, n - 1, sum, subset, subsetSize);

    return include || exclude;
}

int main() {
    int set[] = { 3, 34, 5, 12, 6, 1 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    int subset[n]; // Temp array to store subset

    if (!isSubsetSum(set, n, sum, subset, 0))
        printf("No subset with given sum\n");

    return 0;
}
