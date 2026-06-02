#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

typedef struct node {
    struct node* pre;
    struct node* next;
    int value;
} node;

node* newnode(int value)
{
    node* temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->pre = NULL;
    temp->value = value;
    return temp;
}

void connect_node(node* arr[], int i, int n)
{
    if(i != 0)
    {
        arr[i]->pre = arr[i - 1];
        arr[i - 1]->next = arr[i];
    }
}

void print_list(node* head)
{
    node* cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

node* get_tail(node* head)
{
    if(!head) return NULL;
    node* cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur;
}

void cocktail_sort(node* head)
{
    if(!head || !head->next) return;
    bool swapped;
    node* left = head;
    node* right = get_tail(head);
    while(left != right && left->next != right)
    {
        swapped = false;
        node* cur = left;
        while(cur != right)
        {
            if(cur->value > cur->next->value)
            {
                int temp = cur->value;
                cur->value = cur->next->value;
                cur->next->value = temp;
                swapped = true;
            }
            cur = cur->next;
        }
        right = right->pre;
        if(!swapped) break;
        swapped = false;
        cur = right;
        while(cur != left)
        {
            if(cur->value < cur->pre->value)
            {
                int temp = cur->value;
                cur->value = cur->pre->value;
                cur->pre->value = temp;
                swapped = true;
            }
            cur = cur->pre;
        }
        left = left->next;
        if(!swapped) break;
    }
}

void free_list(node* head)
{
    node* cur = head;
    while(cur != NULL)
    {
        node* next = cur->next;
        free(cur);
        cur = next;
    }
}

int main()
{
    int n;
    printf("Please input n\n");
    scanf("%d", &n);

    if(n <= 0 || n > N)
    {
        printf("Invalid n! Must be between 1 and %d.\n", N);
        return 1;
    }
    node* node_arr[N];
    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        node_arr[i] = newnode(value);
    }
    for(int i = 0; i < n; i++)
    {
        connect_node(node_arr, i, n);
    }
    node* head = node_arr[0];
    printf("Original list: ");
    print_list(head);
    cocktail_sort(head);
    printf("Sorted list:   ");
    print_list(head);
    free_list(head);
    return 0;
}