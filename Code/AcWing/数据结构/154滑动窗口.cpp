#include <iostream>

using namespace std;

const int N = 1e6;

int a[N] , b[N];
int k,n;

int main()
{
    scanf("%d %d", &n , &k);
    for(int i = 0 ; i < n ; i ++ ) scanf("%d", &a[i]);
    
    int h = -1 , t = 0;  
    for(int i = 0 ; i < n ; i ++)
    {
        if( h >= t && b[t] < i - k + 1) t ++; 
        while ( h >= t && a[b[h]] >= a[i]) h --; 
        b[ ++h ] = i;

        if( i >= k - 1 ) printf("%d ", a[b[t]]); 
    }

    cout  << endl ;

    h = -1 , t = 0;  
    for(int i = 0 ; i < n ; i ++)
    {
        if( h >= t && b[t] < i - k + 1) t ++;  
        while ( h >= t && a[b[h]] <= a[i]) h --;  
        b[ ++h ] = i;

        if( i >= k - 1 ) printf("%d ", a[b[t]]);
    }

    puts("");
    return 0;
}
    