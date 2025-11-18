#include <stdio.h>
#include <string.h>

const int m = 20; 
int Q[m];       
int front = 0;      
int rear = 0;      
int tag = 0;     

void enqueue(int a) 
{
    if (front == rear && tag == 1) 
    {
        printf("The queue is full!\n");
        return;
    }
    Q[rear] = a;
    rear = (rear + 1) % m;
    if (front == rear) 
    {
        tag = 1;
    }
}

int dequeue() 
{
    if (front == rear && tag == 0) 
    {
        printf("The queue is empty!\n");
        return -1;
    }
    int data = Q[front];
    front = (front + 1) % m;  
    if (front == rear) 
    {
        tag = 0; 
    }
    return data;
}

int main() 
{
    while(1) 
    {
        char choice[20];
        scanf("%s", choice);
        if (strcmp(choice, "enqueue") == 0) 
        {
            int a;
            scanf("%d", &a);
            enqueue(a);
        } 
        else if (strcmp(choice, "dequeue") == 0) 
        {
            int val = dequeue();
            if (val != -1) 
            {
                printf("dequeue: %d\n", val);
            }
        } 
        else if (strcmp(choice, "exit") == 0) 
        {
            break;
        }
    }
    return 0;
}