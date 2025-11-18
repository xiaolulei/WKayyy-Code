#include <stdio.h>

#define N 100010

typedef struct 
{
    int first;
    int second;
} PII;

PII node[N];
int head = 1;

void initiate()
{
    for(int i = 1; i <= 19; i++)
    {
        node[i].first = i;
        node[i].second = i + 1;
    }
    node[20].first = 20;
    node[20].second = -1;
}

int main()
{
    initiate();

    int mink, maxk;
    scanf("%d %d", &mink, &maxk);

    int pre = 0;
    int current = head;

    while(current != -1)
    {
        int next_node = node[current].second;
        if(node[current].first < maxk && node[current].first > mink)
        {
            if(head == current)
            {
                head = next_node;
            }
            else
            {
                node[pre].second = next_node;
            }
        }
        else
        {
            pre = current;
        }
        current = next_node;
    }

    printf("New: ");
    current = head;
    while(current != -1)
    {
        printf("%d ", node[current].first);
        current = node[current].second;
    }
    printf("\n");

    return 0;
}