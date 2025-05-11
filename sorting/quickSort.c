#include <time.h> 
#include <stdio.h>
#include <stdlib.h>  

#define n 30000
int arr1[n], arr2[n], arr3[n];

// Partition function: rearranges elements around a pivot (first element)
// Elements <= pivot will be on left; > pivot on right
int partition(int arr[], int low, int high)
{
    int p = arr[low];     // Pivot is the first element
    int i = low;          // Pointer moving from left to right
    int j = high;         // Pointer moving from right to left
    int temp;

    // Continue until pointers cross
    while (i < j)
    {
        // Find first element greater than pivot from left side
        while (arr[i] <= p && i <= high - 1)
            i++;

        // Find first element smaller than pivot from right side
        while (arr[j] > p && j >= low + 1)
            j--;

        // Swap elements if i < j
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct sorted position
    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;  // Return final pivot index
}

// Quick Sort function: recursively sorts elements
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition array and get pivot index
        int partition_index = partition(arr, low, high);

        // Recursively sort left sub-array
        quick_sort(arr, low, partition_index - 1);

        // Recursively sort right sub-array
        quick_sort(arr, partition_index + 1, high);
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

    // Measure sorting time for random array
    t = clock();
    quick_sort(arr1, 0, n - 1);
    time_taken1 = ((double)(clock() - t));
    printf("\nQuick Sort (random values, %d elements): %lf ", n, time_taken1);

    // Measure sorting time for sorted array
    t = clock();
    quick_sort(arr2, 0, n - 1);
    time_taken2 = ((double)(clock() - t)) ;
    printf("\nQuick Sort (sorted values, %d elements): %lf ", n, time_taken2);

    // Measure sorting time for reverse sorted array
    t = clock();
    quick_sort(arr3, 0, n - 1);
    time_taken3 = ((double)(clock() - t)) ;
    printf("\nQuick Sort (descending values, %d elements): %lf ", n, time_taken3);

    return 0;
}
