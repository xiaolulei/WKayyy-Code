#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxsize 100
#define wrong_value -100

typedef struct node
{
    int value;
    struct node *left,*right;
}node;

node* new_node(int value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->value = value;
    return temp;
}

void creat_testdata(node* a,int arr[],int idx, int size)
{
    if(size > idx * 2 + 1)
    {
        a->left = new_node(arr[idx * 2 + 1]);
        creat_testdata(a->left,arr,idx * 2 + 1,size);
    }
    if(size > idx * 2 + 2)
    {
        a->right = new_node(arr[idx * 2 + 2]);
        creat_testdata(a->right,arr,idx * 2 + 2,size);
    }
}

void tree_to_array(node* current_node, int* tree_arr, int index, int max_size)
{
    if(current_node == NULL || index >= max_size) return;
    tree_arr[index] = current_node->value;
    tree_to_array(current_node->left, tree_arr, 2 * index + 1, max_size);
    tree_to_array(current_node->right, tree_arr, 2 * index + 2, max_size);
}

int calculate_width(int* tree_arr, int arr_size) 
{
    int max_width = 0;
    int level_start_index = 0;
    int nodes = 1;

    while(level_start_index < arr_size) 
    {
        int current_level_width = 0;
        for(int i = 0; i < nodes; ++i) 
        {
            int current_index = level_start_index + i;
            if(current_index >= arr_size) break;
            if(tree_arr[current_index] != wrong_value) 
            {
                current_level_width++;
            }
        }
        if(current_level_width > max_width) 
        {
            max_width = current_level_width;
        }
        if(current_level_width == 0) break;
        level_start_index += nodes;
        nodes *= 2;
    }
    return max_width;
}

int main()
{
    /*
    我们对树操作的时候最好不要改变树的结构，这样就有可能导致我们的代码出现问题
    谋定而后动，先在纸上模拟好当前函数功能是否可行之后再进行下一步的代码编辑
    */
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *root = new_node(arr[0]);
    creat_testdata(root, arr, 0, size);
    int *tree_array = (int*)malloc(sizeof(int) * maxsize);
    for(int i = 0; i < maxsize; i++) //初始化数组
    {
        tree_array[i] = wrong_value;
    }
    tree_to_array(root, tree_array, 0, maxsize);
    int max_width = calculate_width(tree_array, maxsize);
    printf("The max width is %d\n", max_width);
    return 0;
}