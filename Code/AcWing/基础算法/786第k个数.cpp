#include<iostream>

using namespace std;

int n,k;
int num[100010];

int quick_sort(int q[],int l,int r,int k){
    if(l==r) return q[l];
    int x=q[(l+r)>>1],i=l-1,j=r+1;
    while(i<j){
        while(q[++i]<x);
        while(q[--j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    int s=j-l+1;
    if(s<k) return quick_sort(q,j+1,r,k-s);
    else return quick_sort(q,l,j,k);
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++) scanf("%d",&num[i]);
    printf("%d\n",quick_sort(num,0,n-1,k));
    return 0;
}