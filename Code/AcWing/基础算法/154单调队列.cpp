#include<iostream>

using namespace std; 

const int N = 1e6 + 10;
int a[N],q[N];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n ; i ++) scanf("%d",&a[i]);
    
    int front = 0 , tail = -1 ; 
    for(int i = 0 ; i < n ; i ++)
    {
        if(front <= tail && i - k + 1 > q[front] ) front ++;
        while(front <= tail && a[q[tail]] >= a[i] ) tail -- ;
        q[ ++tail ] = i;
        if( i >= k - 1 ) printf("%d " , a[q[front]]);
    }

    printf("\n");

    front = 0 , tail = -1;
    for(int i= 0 ; i < n ; i ++)
    {
        if( front <= tail && q[front] < i - k + 1) front ++ ;
        while(front <= tail && a[q[tail]] <= a[i] ) tail --;
        q[++tail] = i;
        if(i >= k - 1) printf("%d ", a[q[front]]);
    }
    return 0;
}