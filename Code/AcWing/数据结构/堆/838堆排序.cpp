#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int num[N],cnt;

void down(int i)
{
    int t = i;
    if(i * 2 <= cnt && num[t] > num[i * 2]) t = i * 2;
    if(i * 2 + 1 <= cnt && num[t] > num[i * 2 + 1]) t = i * 2 + 1;
    if(t != i)
    {
        swap(num[t],num[i]);
        down(t);
    }
}

int main()
{
    int n , m;
    cin >> n >> m;
    
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> num[i];
    }
    
    cnt = n;

    for(int i = n/2 ; i ; i --)
    {
        down(i);
    }

    for(int i = 1 ; i <= m ; i ++)
    {
        cout << num[1] << ' ';
        num[1] = num[cnt --];
        down(1);
    }
    
    return 0;
}