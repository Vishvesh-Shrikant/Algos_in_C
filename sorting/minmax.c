#include <stdio.h>
int comparisons = 0;
void findMinMax(int arr[], int low, int high, int *min, int *max) {
	int mid, min1, max1, min2, max2;
	if (low == high) {
		*min = *max = arr[low];
	}
	else if (high == low + 1) {
		comparisons++;
		if (arr[low] < arr[high]) {
			*min = arr[low];
			*max = arr[high];
		} else {
			*min = arr[high];
			*max = arr[low];
		}
	}
	else {
		mid = (low + high) / 2;
		findMinMax(arr, low, mid, &min1, &max1);
		findMinMax(arr, mid + 1, high, &min2, &max2);
		comparisons += 2;
		*min = (min1 < min2) ? min1 : min2;
		*max = (max1 > max2) ? max1 : max2;
	}
}
int main() {
	int n, min, max;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	findMinMax(arr, 0, n - 1, &min, &max);
	printf("Minimum: %d\n", min);
	printf("Maximum: %d\n", max);
	printf("Total comparisons in Min-Max algorithm: %d\n", comparisons);
	return 0;
}