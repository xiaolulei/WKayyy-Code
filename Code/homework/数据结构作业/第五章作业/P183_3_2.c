#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left,*right;
}node;

int comparetree(node* a_top, node* b_top)
{
    if (a_top == NULL && b_top == NULL)
    {
        return 1;
    }
    if (a_top == NULL || b_top == NULL || a_top->value != b_top->value)
    {
        return 0;
    }

    return comparetree(a_top->left, b_top->left) && comparetree(a_top->right, b_top->right);
}
node* new_node(int value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->value = value;
}

void creat_testdata(node* a,int arr[],int idx, int size)
{
    //arr[] = {1,2,3,4,5,6,7,8};
    if(size > idx * 2 + 1)
    {
        a->left = new_node(arr[idx * 2 + 1]);
        creat_testdata(a->left,arr,idx * 2 + 1,size);
    }
    else
    {
        a->left = NULL;
    }
    if(size > idx * 2 + 2)
    {
        a->right = new_node(arr[idx * 2 + 2]);
        creat_testdata(a->right,arr,idx * 2 + 2,size);
    }
    else
    {
        a->right = NULL;
    }
}

int main()
{
    /*
    既然我们要判定的是两棵树是否相等，假设是二叉树
    那我们可以把二叉树用先序遍历所有的节点，然后将值进行比对
    如果两值相等则继续遍历，否则两棵树不同
    假设这是一个以数字为数据的树
    */
    int arr_a[] = {1,2,3,4,5};
    int arr_b[] = {1,2,3,4,5,6,7};
    int a_size = sizeof(arr_a) / sizeof(arr_a[0]),b_size = sizeof(arr_b) / sizeof(arr_b[0]);
    node *a = new_node(arr_a[0]);
    node *b = new_node(arr_b[0]);
    creat_testdata(a,arr_a,0,a_size);
    creat_testdata(b,arr_b,0,b_size);
    if(a_size != b_size)
    {
        printf("different");
        return 0;
    }
    int correct = comparetree(a,b);
    if(correct) printf("Same!");
    else printf("Different!");
    return 0;
}