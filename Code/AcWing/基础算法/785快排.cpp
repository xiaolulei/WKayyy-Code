#include<iostream>

using namespace std;

const int N=1e5+10;

int num[N];

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int i=l-1,j=r+1,x=q[(l + r) >> 1];
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}



int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    quick_sort(num,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    return 0;
}