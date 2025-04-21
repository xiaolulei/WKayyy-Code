#include <iostream>

using namespace std;

const long int N = 1e5+10 ;

int n , k ;
long long x,temp;
long long a[N];
long long res,last;

int main()
{
    int t;
    cin >> t ;
    while(t--)
    {
        res = 0 ;
        cin >> n >> k >> x;
        temp = x;
        last = n * k ;
        long long temp_sum = 0;
        for(int i = 1 ;i <= n ; i ++)
        {
            cin >> a[i];
            temp_sum += a[i];
            a[i] += a[i-1];
        }
        temp = x % temp_sum;
        res +=  x / temp_sum ;
        for(int i = 1 ; i <= n ; i++)
        {
            if( a[i] > temp )
            {
                res += i;
                break;
            }
            
        }
        cout << last - res + 1 << endl ;
    }
    return 0;
}