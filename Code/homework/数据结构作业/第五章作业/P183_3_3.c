#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left,*right;
}node;

void change_son(node* a)
{
    node* temp;
    temp = a->left;
    a->left = a->right;
    a->right = temp;
    if(a->left != NULL ) change_son(a->left);
    if(a->right != NULL) change_son(a->right);
}

node* new_node(int value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->value = value;
}

void creat_testdata(node* a,int arr[],int idx, int size)
{
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

void printnodetree(node* a)
{
    printf("%d ",a->value);
    if(a->left != NULL) printnodetree(a->left);
    if(a->right != NULL) printnodetree(a->right);
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *a = new_node(arr[0]);
    creat_testdata(a,arr,0,size);
    change_son(a);
    printnodetree(a);
    return 0;
}