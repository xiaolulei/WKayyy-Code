#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertsort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void binaryinsertsort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int left = 0;
        int right = i;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(arr[mid] > key)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        for(int j = i; j > left; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[left] = key;
    }
}

void shellSort(int arr[], int n)
{
    int gap;
    for(gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void bubblesort(int arr[], int n)
{
    int i, j;
    int swapped;
    for(i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for(j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if(swapped == 0)break;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergesort_rec(int arr[], int temp[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort_rec(arr, temp, left, mid);
        mergesort_rec(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void mergesort(int arr[], int n)
{
    int *temp = malloc(n * sizeof(int));
    mergesort_rec(arr, temp, 0, n - 1);
    free(temp);
}

void selectionsort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void treesort(int arr[], int n)
{
    if(n <= 1)return;
    int tree_size = 1;
    while(tree_size < n)tree_size *= 2;
    int *tree = malloc(2 * tree_size * sizeof(int));
    int INF = INT_MAX;
    for(int i = 0; i < tree_size; i++)
    {
        tree[tree_size + i] = (i < n) ? arr[i] : INF;
    }
    for(int i = tree_size - 1; i >= 1; i--)
    {
        tree[i] = (tree[2 * i] < tree[2 * i + 1]) ? tree[2 * i] : tree[2 * i + 1];
    }
    for(int pos = 0; pos < n; pos++)
    {
        arr[pos] = tree[1];
        int idx = 1;
        while(idx < tree_size)
        {
            if(tree[idx] == tree[2 * idx])idx = 2 * idx;
            else idx = 2 * idx + 1;
        }
        tree[idx] = INF;
        for(int i = idx / 2; i >= 1; i /= 2)
        {
            tree[i] = (tree[2 * i] < tree[2 * i + 1]) ? tree[2 * i] : tree[2 * i + 1];
        }
    }
    free(tree);
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest])largest = l;
    if(r < n && arr[r] > arr[largest])largest = r;
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildheap(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapsort(int arr[], int n)
{
    buildheap(arr, n);
    for(int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void generate_data(int *arr, int n, int type)
{
    srand(12345);
    if(type == 0)
    {
        for(int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
    }
    else if(type == 1)
    {
        for(int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            arr[i] = rand() % (10 * n) + 1;
        }
    }
}

int main()
{
    int n, type;
    scanf("%d %d", &n, &type);

    int *orig = malloc(n * sizeof(int));
    generate_data(orig, n, type);

    int *a1 = malloc(n * sizeof(int));
    int *a2 = malloc(n * sizeof(int));
    int *a3 = malloc(n * sizeof(int));
    int *a4 = malloc(n * sizeof(int));
    int *a5 = malloc(n * sizeof(int));
    int *a6 = malloc(n * sizeof(int));
    int *a7 = malloc(n * sizeof(int));
    int *a8 = malloc(n * sizeof(int));
    int *a9 = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)a1[i] = orig[i];
    clock_t start = clock();
    insertsort(a1, n);
    clock_t end = clock();
    double t1 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("insertsort: %fs\n", t1);

    for(int i = 0; i < n; i++)a2[i] = orig[i];
    start = clock();
    binaryinsertsort(a2, n);
    end = clock();
    double t2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("binaryinsertsort: %fs\n", t2);

    for(int i = 0; i < n; i++)a3[i] = orig[i];
    start = clock();
    shellSort(a3, n);
    end = clock();
    double t3 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("shellsort: %fs\n", t3);

    for(int i = 0; i < n; i++)a4[i] = orig[i];
    start = clock();
    bubblesort(a4, n);
    end = clock();
    double t4 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("bubblesort: %fs\n", t4);

    for(int i = 0; i < n; i++) a5[i] = orig[i];
    start = clock();
    quicksort(a5, 0, n - 1);
    end = clock();
    double t5 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("quicksort: %fs\n", t5);

    for(int i = 0; i < n; i++) a6[i] = orig[i];
    start = clock();
    mergesort(a6, n);
    end = clock();
    double t6 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("mergesort: %fs\n", t6);

    for(int i = 0; i < n; i++) a7[i] = orig[i];
    start = clock();
    selectionsort(a7, n);
    end = clock();
    double t7 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("selectionsort: %fs\n", t7);

    for(int i = 0; i < n; i++) a8[i] = orig[i];
    start = clock();
    treesort(a8, n);
    end = clock();
    double t8 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("treesort: %fs\n", t8);

    for(int i = 0; i < n; i++) a9[i] = orig[i];
    start = clock();
    heapsort(a9, n);
    end = clock();
    double t9 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("heapsort: %fs\n", t9);

    free(orig);
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
    free(a7);
    free(a8);
    free(a9);
    return 0;
}