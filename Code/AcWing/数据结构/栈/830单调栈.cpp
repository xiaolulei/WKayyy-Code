#include <iostream>

using namespace std;

const int N = 1e5+10;

int num[N],n,tt;

int main()
{
    cin >> n ;
    while(n--)
    {
        int x;
        cin >> x;
        while(tt && num[tt] >= x) tt --;
        if(tt) cout << num[tt] << ' ';
        else cout << -1 << ' ';
        num[++ tt] = x;
    }
    return 0;
}