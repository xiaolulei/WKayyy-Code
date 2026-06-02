#include <stdio.h>

#define N 100

void sort(int arr[], int n)
{
    int temp[n];
    int idx = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] < 0)
            temp[idx++] = arr[i];

    for(int i = 0; i < n; i++)
        if(arr[i] >= 0)
            temp[idx++] = arr[i];

    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main()
{
    int n;
    int num[N];
    printf("Please enter n\n");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++)
    {
        scanf("%d",&num[i]);
    }
    sort(num,n);
    for(int i = 0 ; i < n ; i ++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}

//单选 10 10分
//填空 5 10分
//计算与应用 如给出哈夫曼编码
//算法设计 写算法 完善算法
//问题分析题 给出一段话有实际应用背景需求，对该问题求解怎么样组织数据