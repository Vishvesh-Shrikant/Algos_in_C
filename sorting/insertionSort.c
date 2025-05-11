#include <stdio.h>
#include <stdlib.h>
#define max 10

int arr[max];

//sorting array using insertion sort 
void insertion_sort()
{
    int i , j;
    for ( i = 1; i < max ; i++ )
    { 
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertion_sort();
    printf("\nSorted Array: \n");
    print_arr();
    
}