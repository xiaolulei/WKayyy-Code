#include <stdio.h>
#include <stdlib.h>

#define N 11
#define M 100000 + 10
//假定链表的数据不超过1e5;
//假定我们的两个链表的长度都为10

typedef struct 
{
    int first;
    int second;
} PII;

PII A[N], B[N], C[2 * N];

int compare(const void* a, const void* b) 
{
    const PII* p1 = (const PII*)a;
    const PII* p2 = (const PII*)b;
    
    if (p1->first < p2->first) return 1;
    if (p1->first > p2->first) return -1;
    return 0;
}

int main() 
{
    for (int i = 0; i < 10; i++) 
    {
        int num;
        scanf("%d", &num);
        A[i].first = num;
        A[i].second = (i != 9) ? (i + 1) : -1;
        C[i].first = num;
        C[i].second = 0 * 10 + i; 
        // 用 second 记录来源 (0代表A) 和索引
    }

    for (int i = 0; i < 10; i++) 
    {
        int num;
        scanf("%d", &num);
        B[i].first = num;
        B[i].second = (i != 9) ? (i + 1) : -1;
        C[10 + i].first = num;
        C[10 + i].second = 1 * 10 + i; 
        // 用 second 记录来源 (1代表B) 和索引
    }

    qsort(C, 20, sizeof(PII), compare);

    for (int i = 0; i < 19; i++) 
    {
        int curr = C[i].second;
        int next = C[i + 1].second;

        int curr_arr = curr / 10;
        int curr_idx = curr % 10;
        int next_arr = next / 10;
        int next_idx = next % 10;

        if (curr_arr == 0) 
        {
            A[curr_idx].second = (next_arr == 0) ? (next_idx) : (10 + next_idx);
        } else
        {
            B[curr_idx].second = (next_arr == 0) ? (next_idx) : (10 + next_idx);
        }
    }

    int last = C[19].second;
    int last_arr = last / 10;
    int last_idx = last % 10;
    if (last_arr == 0) 
    {
        A[last_idx].second = -1;
    } 
    else 
    {
        B[last_idx].second = -1;
    }

    printf("cout:");
    int current_val = C[0].second;
    int current_arr = current_val / 10;
    int current_idx = current_val % 10;
    int current = (current_arr == 0) ? current_idx : 10 + current_idx;


    while (current != -1) 
    {
        if (current < 10) 
        {
            printf(" %d", A[current].first);
            current = A[current].second;
        } 
        else 
        {
            printf(" %d", B[current - 10].first);
            current = B[current - 10].second;
        }
    }
    printf("\n");

    return 0;
}