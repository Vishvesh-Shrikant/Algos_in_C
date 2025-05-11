#include <time.h> 
#include <stdio.h>
#include <stdlib.h>  

#define n 30000  // Size of the array

// Function to sort array using Selection Sort algorithm
void selectionSort(int arr[]) 
{
    int i, j, min_idx, temp;

    // Traverse the array from index 0 to n-2
    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;  // Assume the current element is the minimum

        // Find the index of the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx]) 
                min_idx = j;
        }

        // Swap the found minimum element with the current element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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

    // Initialize arr2 with sorted values (best case for Selection Sort — although Selection Sort ignores that)
    for (i = 0; i < n; i++)
        arr2[i] = i;
        
    // Initialize arr3 with descending values (worst case for some algorithms but not much impact here)
    for (i = 0; i < n; i++)
        arr3[i] = n - i;
    
    // Measure time to sort random array
    t = clock(); 
    selectionSort(arr1);
    t1 = clock() - t; 
    time_taken1 = ((double)t1);

    // Measure time to sort already sorted array
    t = clock(); 
    selectionSort(arr2);
    t2 = clock() - t; 
    time_taken2 = ((double)t2);

    // Measure time to sort descending array
    t = clock(); 
    selectionSort(arr3);
    t3 = clock() - t; 
    time_taken3 = ((double)t3);
    
    // Print execution times
    printf("\nSelection Sort (random values, %d elements): %lf", n, time_taken1);
    printf("\nSelection Sort (sorted array, %d elements): %lf", n, time_taken2);
    printf("\nSelection Sort (descending values, %d elements): %lf", n, time_taken3);

    return 0;
}
