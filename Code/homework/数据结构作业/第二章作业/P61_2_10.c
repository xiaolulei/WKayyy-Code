#include <stdio.h>

#define N 100010

typedef struct 
{
    int first;
    int second;
} PII;

PII node[N];
int head = 1; //头指针
int tail = -1;

void initiate()
{
    for(int i = 1 ; i <= 19 ; i ++)
    {
        node[i].first =  i;
        node[i].second = i + 1;
    }
    node[20].first = 20;
    node[20].second = -1;
}

int main()
{
    initiate();

    int current = head;
    int item , pre = 0;
    scanf("%d", &item);
    while(current != -1)
    {
        if(node[current].first == item)
        {
            if(head == current) 
            {
                head = node[current].second;
            }
            else
            {
                node[pre].second = node[current].second;
            }
        }
        pre = current;
        current = node[current].second;
    }

    current = head;
    while(current != -1)
    {
        printf("%d ", node[current].first);
        current = node[current].second;
    }
    printf("\n");
    return 0;
}