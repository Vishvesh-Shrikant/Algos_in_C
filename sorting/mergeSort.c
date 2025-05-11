#include <time.h> 
#include <stdio.h>
#include <stdlib.h>  

#define n 30000
int arr1[n], arr2[n], arr3[n];

// Merge function: merges two sorted subarrays into a single sorted subarray
void merge(int arr[], int left, int mid, int right)
{
    int temp[right - left + 1];  // Temporary array to hold merged elements
    int i = left;     // Pointer for left subarray
    int j = mid + 1;  // Pointer for right subarray
    int k = 0;        // Pointer for temp array

    // Merge elements from both subarrays into temp[]
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];  // Take element from left subarray
        else
            temp[k++] = arr[j++];  // Take element from right subarray
    }

    // Copy any remaining elements from left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy any remaining elements from right subarray
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy merged elements back to the original array
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort function: recursively divides array and calls merge()
void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;  // Find midpoint

        // Recursively sort left half
        merge_sort(arr, left, mid);

        // Recursively sort right half
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int i;
    clock_t t;
    double time_taken1, time_taken2, time_taken3;

    srand(time(0));  // Seed random number generator

    // Generate random array
    for (i = 0; i < n; i++)
        arr1[i] = rand() % (n - 1);

    // Generate sorted array
    for (i = 0; i < n; i++)
        arr2[i] = i;

    // Generate reverse sorted array
    for (i = 0; i < n; i++)
        arr3[i] = n - i;

    // Measure time for sorting random array
    t = clock();
    merge_sort(arr1, 0, n - 1);
    time_taken1 = ((double)(clock() - t));
    printf("\nMerge Sort (random values, %d elements): %lf ", n, time_taken1);

    // Measure time for sorting already sorted array
    t = clock();
    merge_sort(arr2, 0, n - 1);
    time_taken2 = ((double)(clock() - t));
    printf("\nMerge Sort (sorted values, %d elements): %lf ", n, time_taken2);

    // Measure time for sorting reverse sorted array
    t = clock();
    merge_sort(arr3, 0, n - 1);
    time_taken3 = ((double)(clock() - t));
    printf("\nMerge Sort (descending values, %d elements): %lf ", n, time_taken3);

    return 0;
}
