#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxcapacity 100000

typedef struct HuffmanNode
{
    char ch;
    int frequent;
    struct HuffmanNode *left,*right;
}huffmannode;

typedef struct MinHeap
{
    int size;
    int capacity;
    huffmannode** arr;
}minheap;

huffmannode* createhuffmannode(char ch,int frequent)
{
    huffmannode* temp = (huffmannode*)malloc(sizeof(huffmannode));
    temp->ch = ch;
    temp->frequent = frequent;
    temp->left = temp->right = NULL;
    return temp;
}

minheap* createminheap(int size)
{
    minheap* temp = (minheap*)malloc(sizeof(minheap));
    temp->size = size;
    temp->capacity = maxcapacity;
    temp->arr = (huffmannode**)malloc(sizeof(huffmannode*) * maxcapacity);
    return temp;
}

void swaphuffmannode(huffmannode** a,huffmannode** b)
{
    huffmannode* t = *a;
    *a = *b;
    *b = t;
}

void minheapify(minheap* heap,int idx)
{
    int small = idx;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    if(left < heap->size && heap->arr[small]->frequent > heap->arr[left]->frequent)
    {
        small = left;
    }
    if(right < heap->size && heap->arr[small]->frequent > heap->arr[right]->frequent)
    {
        small = right;
    }
    if(small != idx)
    {
        swaphuffmannode(&heap->arr[small],&heap->arr[idx]);
        minheapify(heap, small);
    }
}

minheap* buildminheap(char str[],int frequent[],int size)
{
    minheap* heap = createminheap(size);
    heap->size = size;
    for(int i = 0 ; i < size; i ++)
    {
        heap->arr[i] = createhuffmannode(str[i],frequent[i]);
    }
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        minheapify(heap, i);
    }
    return heap;
}

void inserthuffmannode(huffmannode* a,minheap* heap)
{
    if(heap->size + 1 > heap->capacity)
    {
        printf("error\n");
        return;
    }
    ++heap->size;
    int i = heap->size - 1;
    while(i && a->frequent < heap->arr[(i - 1) / 2]->frequent)
    {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = a;
}

huffmannode* gettop(minheap* heap)
{
    huffmannode* temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    --heap->size;
    minheapify(heap,0);
    return temp;
}

huffmannode* createhuffmantree(minheap* heap)
{
    while(heap->size != 1)
    {
        huffmannode* left = gettop(heap);
        huffmannode* right = gettop(heap);

        huffmannode* top = createhuffmannode('#',left->frequent + right -> frequent);
        top->left = left;
        top->right = right;
        inserthuffmannode(top,heap);
    }
    return heap->arr[0];
}

void printfhuffmancode(huffmannode* node,int idx,int code[])
{
    if(node->left)
    {
        code[idx] = 0;
        printfhuffmancode(node->left,idx + 1,code);
    }
    if(node->right)
    {
        code[idx] = 1;
        printfhuffmancode(node->right,idx + 1,code);
    }
    if((!node->left)&&(!node->right))
    {
        printf("%c:",node->ch);
        for(int i = 0 ; i < idx ; i ++)
        {
            printf("%d",code[i]);
        }
        printf("\n");
    }
}

int main()
{
    char str[] = {'a','b','c','d','e','f'};
    int frequent[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(str) / sizeof(str[0]);
    minheap* minheap = buildminheap(str,frequent,size);
    huffmannode* top = createhuffmantree(minheap);
    int code[10000];
    printfhuffmancode(top,0,code);
    return 0;
}