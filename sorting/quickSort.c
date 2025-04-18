#include <stdio.h>
#include <stdlib.h>
#define max 10

int arr[max];

int partition (int low , int high)
{
    int p = arr[low];
    int i = low;
    int j = high; 
    int temp;
    while ( i < j)
    {
        //finding first element higher than pivot , i.e arr[low]
        while ( arr[i] <= p && i <= high - 1)
            i++;
        
        //finding first element smaller than pivot , i.e arr[low]
        while ( arr[j] > p && j >= low + 1)
            j--;
            
        if( i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //puts the pivot into the correct place in the array
    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    
    //returns the pivot --> where partition takes places 
    return j;
}

void quick_sort( int low , int high)
{
    int partition_index;
    if( low < high)
    {
        partition_index = partition(low, high);
        
        quick_sort( low, partition_index -1);
        quick_sort( partition_index + 1, high);
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
    quick_sort(0, max-1 );
    printf("\nSorted Array: \n");
    print_arr();   
}