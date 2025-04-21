#include<iostream>

using namespace std;

const int N = 1e5+10;

int num[N],temp[N];

long long merge_sort(int q[],int l,int r){
    if (l >= r) return 0;
    int mid= l + r >> 1;
    long long ans=merge_sort(q,l,mid) + merge_sort(q,mid+1,r);

    int i=l,j=mid+1,k=0;
    while( i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else
        {
            temp[k++] = q[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) temp[k ++ ] = q[i ++ ]; //  X
    while (j <= r) temp[k ++ ] = q[j ++ ]; //   X

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = temp[j]; // X

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    cout << merge_sort(num,0,n-1) << endl;
    return 0;
}