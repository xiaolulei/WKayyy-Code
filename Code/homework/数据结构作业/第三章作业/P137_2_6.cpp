#include <stdio.h>
#include <string.h>

#define N 1000

typedef struct 
{
    int first;
    int second;
} PII;

PII num[N];
int tail, sum, idx;

void init_num() 
{
    for (int i = 0; i < 19; i++) {
        num[i].first = -1;
        num[i].second = i + 1;
    }
    num[19].first = -1;
    num[19].second = 0;
    tail = -1;
    sum = 0;
    idx = 0;
}

void init() 
{
    if (tail == -1) return;
    int head = num[tail].second;
    int current = head;
    do 
    {
        int next = num[current].second;
        num[current].first = -1;
        current = next;
    } while (current != head);
    
    tail = -1;
    sum = 0;
    idx = 0;
}

void IsEmpty() 
{
    if (tail == -1)
        printf("IsEmpty\n");
    else
        printf("NotEmpty\n");
}

int Push(int a) 
{
    if (sum == 20) 
    {
        printf("The queue is full!\n");
        return 0;
    }
    
    int new_node = idx;
    idx = num[idx].second;
    
    num[new_node].first = a;
    
    if (tail == -1) 
    {
        num[new_node].second = new_node;
        tail = new_node;
    } else 
    {
        int head = num[tail].second;
        num[tail].second = new_node;
        num[new_node].second = head;
        tail = new_node;
    }
    
    sum++;
    return 1;
}

int Pop() 
{
    if (tail == -1) 
    {
        printf("The queue is empty!\n");
        return -1;
    }
    
    int head = num[tail].second;
    int data = num[head].first;

    if (head == tail) 
    {
        num[head].second = idx;
        idx = head;
        tail = -1;
    } else {
        int new_head = num[head].second;
        num[tail].second = new_head;
        num[head].second = idx;
        idx = head;
    }
    
    sum--;
    return data;
}

int main() 
{
    init_num();
    while (1) 
    {
        char choice[20]; 
        scanf("%s", choice);

        if (strcmp(choice, "init") == 0) 
        {
            init();
        } else if (strcmp(choice, "isempty") == 0) 
        {
            IsEmpty();
        } else if (strcmp(choice, "Push") == 0) 
        {
            int a;
            scanf("%d", &a);
            Push(a);
        } else if (strcmp(choice, "Pop") == 0) 
        {
            int val = Pop();
            if (val != -1) {
                printf("Pop: %d\n", val);
            }
        } else if (strcmp(choice, "exit") == 0) 
        {
            break;
        }
    }
    return 0;
}