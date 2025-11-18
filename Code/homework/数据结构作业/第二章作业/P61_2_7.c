#include <stdio.h>

typedef struct 
{
    int first;
    int second;
} PII; 
//假定前者存储数据 后者存储位置 并且我们设有头指针

#define N 100000 //假定总数据量是1e5,其中有可能会存在被删除的元素，有头节点和尾节点
                     //但是为了模拟方便我们直接设计连续的20个指针，即1~20

PII node[N];
int head = 1; //头指针
int tail = -1;

void initiate()
{
    int data[] = 
    {
        88, 12, 56, 3, 91, 23, 74, 45, 68, 7,
        99, 31, 50, 18, 42, 66, 29, 81, 15, 37
    };
    
    for(int i = 1 ; i <= 19 ; i ++)
    {
        node[i].first = data[i-1];
        node[i].second = i + 1;
    }
    node[20].first = data[19];
    node[20].second = -1;
}

int main()
{
    initiate();
    int prev = -1;
    int current = head;
    
    while(current != -1)
    {
        int next_temp = node[current].second; // 保存下一个节点
        node[current].second =  prev;          // 反转指针
        prev = current;                       // 移动prev
        current = next_temp;                  // 移动current
    }

    head = prev; // 新的头节点是原来的尾节点

    current = head;

    while(current != -1)
    {
        printf("%d ", node[current].first);
        current = node[current].second;
    }
    printf("\n");
    return 0;
}