#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* createNode(int val)
{
    node* node = malloc(sizeof(node));
    node->data = val;
    node->next = NULL;
    return node;
}

void insert(node** head, int val)
{
    node* newNode = createNode(val);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort(node* head)
{
    node* current = head;
    while(current != NULL)
    {
        node* minNode = current;
        node* runner = current->next;
        while(runner != NULL)
        {
            if(runner->data < minNode->data)
            {
                minNode = runner;
            }
            runner = runner->next;
        }
        if(minNode != current)
        {
            int temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }
        current = current->next;
    }
}

int main()
{
    node* head = NULL;
    insert(&head, 64);
    insert(&head, 25);
    insert(&head, 12);
    insert(&head, 22);
    insert(&head, 11);
    printf("before: ");
    printList(head);
    sort(head);
    printf("after: ");
    printList(head);
    return 0;
}