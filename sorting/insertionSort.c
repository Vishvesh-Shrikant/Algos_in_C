#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 30000  // Size of the array

// Function to sort array using Insertion Sort algorithm
void insertionSort(int arr[])
{
    int i, j;
    
    // Traverse the array from index 1 to n-1
    for (i = 1; i < n; i++)
    {
        int key = arr[i];    // Element to be inserted at correct position
        j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];  // Shift element one position to the right
            j = j - 1;
        }

        // Place key in its correct position
        arr[j + 1] = key;
    }
}

int main()
{
    int i, arr1[n], arr2[n], arr3[n];
    clock_t t, t1, t2, t3;
    double time_taken1, time_taken2, time_taken3;

    // Initialize arr1 with random values
    for (i = 0; i < n; i++)
        arr1[i] = rand() % (n - 1);

    // Initialize arr2 with sorted values (best case for insertion sort)
    for (i = 0; i < n; i++)
        arr2[i] = i;

    // Initialize arr3 with descending values (worst case for insertion sort)
    for (i = 0; i < n; i++)
        arr3[i] = n - i;

    // Measure time to sort random array
    t = clock();
    insertionSort(arr1);
    t1 = clock() - t;
    time_taken1 = ((double)t1);

    // Measure time to sort already sorted array
    t = clock();
    insertionSort(arr2);
    t2 = clock() - t;
    time_taken2 = ((double)t2);

    // Measure time to sort descending array
    t = clock();
    insertionSort(arr3);
    t3 = clock() - t;
    time_taken3 = ((double)t3);

    // Print execution times
    printf("\nInsertion Sort (random values, %d elements): %lf", n, time_taken1);
    printf("\nInsertion Sort (sorted array, %d elements): %lf", n, time_taken2);
    printf("\nInsertion Sort (descending values, %d elements): %lf", n, time_taken3);

    return 0;
}
