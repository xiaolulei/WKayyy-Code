#include<iostream>

using namespace std;

const int N=1e5+10;
int num[N],tmp[N];

void merge_sort(int q[],int l,int r)
{
    if(l >= r) return ;
    int mid=l + r >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    /*
    1. 初始调用：merge_sort(0,3)
   ├─ 分解为左半区 [5,3] (0,1) 和右半区 [8,2] (2,3)
   ├─ 调用 merge_sort(0,1) 排序左半区
   │  ├─ 分解为 [5] (0,0) 和 [3] (1,1)
   │  ├─ 调用 merge_sort(0,0) → 直接返回（基线条件）
   │  ├─ 调用 merge_sort(1,1) → 直接返回（基线条件）
   │  └─ 合并 [5] 和 [3] → [3,5]
   └─ 调用 merge_sort(2,3) 排序右半区
      ├─ 分解为 [8] (2,2) 和 [2] (3,3)
      ├─ 调用 merge_sort(2,2) → 直接返回（基线条件）
      ├─ 调用 merge_sort(3,3) → 直接返回（基线条件）
      └─ 合并 [8] 和 [2] → [2,8]
   └─ 合并 [3,5] 和 [2,8] → [2,3,5,8]
    */
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    merge_sort(num,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",num[i]);
    return 0;
}
