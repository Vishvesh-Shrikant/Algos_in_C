#include <stdio.h>
#include <stdlib.h>
#define max 10

int arr[max];

// merge the sorted halves
void merge(int left , int mid, int right)
{
    int temp[max];
    // Merge the two halves
    int i = left, j = mid + 1, k = left;
    
    // adding the elements from the halves into the temporary array 
    while (i <= mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }
    // Copy remaining elements from the left half
    while (i <= mid) 
        temp[k++] = arr[i++];

    // Copy remaining elements from the right half
    while (j <= right) 
        temp[k++] = arr[j++];

    // Copy the sorted elements back to the original array
    for (i = left; i <= right; i++) 
        arr[i] = temp[i];
}

//sorting array using merge sort
void merge_sort(int left , int right)
{
    int mid;
    if( left < right)
    {
        mid = left + (right - left)/2;
        
        merge_sort (left , mid);
        merge_sort( mid+1, right);
        
        merge( left , mid , right);
    }
}

// printing the array 
void print_arr()
{
    int i;
    for(i = 0 ; i < max ; i++)
    {
        printf("%d\t", arr[i]);
    }
}
 
int main()
{
    int i;
    for ( i = 0 ; i < max ; i++)
    {
        arr[i] = rand() % (max - 1);
        //above code is used to generate a random number 
    }
    printf("\nUnsorted Array: \n");
    print_arr();
    merge_sort(0, max-1);
    printf("\nSorted Array: \n");
    print_arr();
    
}