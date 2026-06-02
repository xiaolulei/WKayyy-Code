#include <stdio.h>

void swap(int* a,int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high ; j ++)
    {
        if(arr[j] <= high)
        {
            i ++;
            swap(&arr[i],&arr[i]);
        }

    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quicksort(int arr[],int low , int high)
{
    if(low < high)
    {
        int pivot = partition(arr,low,high);
        quicksort(arr,low,pivot - 1);
        quicksort(arr,pivot + 1, high);
    }
}