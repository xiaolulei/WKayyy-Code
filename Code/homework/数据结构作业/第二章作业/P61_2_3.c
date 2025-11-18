#include <stdio.h>

#define N 10 //假设链表最大容量为20

typedef struct 
{
    int first;
    int second;
} PII;

PII A[N], B[N], C[N * 2];
int head = 0;

//用于我们查询元素是否在B中
int value_exists_in_B(int value) 
{
    for (int i = 0; i < N; i++) 
    {
        if (B[i].first == value) 
        {
            return 1;
        }
    }
    return 0; 
}

int main()
{
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        A[i].first = num;
        if(i < N - 1)
            A[i].second = i + 1;
        else
            A[i].second = -1;
    }

    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        B[i].first = num;
        if(i < N - 1)
            B[i].second = i + 1;
        else
            B[i].second = -1;
    }
     
    int idxa = 0;
    int lidx = -1;
    head = -1;

    for (idxa = 0; idxa < N; idxa++) 
    {
        if (!value_exists_in_B(A[idxa].first)) 
        {
            if (head == -1) 
            {
                head = idxa;
                lidx = idxa;
            } else 
            { 
                A[lidx].second = idxa;
                lidx = idxa;
            }
        }
    }
    if (lidx != -1) 
    {
        A[lidx].second = -1;
    }

    printf("A:");
    int current_node_idx = head;
    if (current_node_idx == -1) 
    {
        printf("Kong");
    } else 
    {
        while(current_node_idx != -1)
        {
            printf("%d ", A[current_node_idx].first);
            current_node_idx = A[current_node_idx].second;
        }
    }
    printf("\n");
   
    return 0;
}