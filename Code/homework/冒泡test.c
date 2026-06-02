#include <stdio.h>
#include <stdbool.h>

void bubblesort(int arr[],int n)
{
    int i, j;
    bool swapped;

    for(int i = 0 ; i < n - 1; i ++)
    {
        swapped = false;
        for(int j = 0 ; j < n - 1 - j ; j ++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j],&arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == true)
        {
            break;
        }
    }
}