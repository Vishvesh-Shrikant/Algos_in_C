#include <stdio.h>
#include <stdlib.h>
#define max 10

int arr[max];

// printing the array 
void print_arr()
{
    int i;
    for(i = 0 ; i < max ; i++)
    {
        printf("%d\t", arr[i]);
    }
}
//sorting array using selection sort 
void selection_sort()
{
    int i, j, min_idx, temp;
    for (i = 0; i < max - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < max; j++) 
        {
            if (arr[j] < arr[min_idx]) 
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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
    selection_sort();
    printf("\nSorted Array: \n");
    print_arr();
    
}