#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10 , M = 31 * N;
int n;
int num[N],son[M][2];
int idx;

void insert(int x)
{
    int p = 0;
    for(int i = 30 ; i >= 0 ; i --)
    {
        int &s = son[p][x >> i & 1];
        if(!s)
        {
            s = ++ idx;
        }
        p = s;
    }
}

int query(int x)
{
    int p = 0 , res = 0;
    for(int i = 30 ; i >= 0 ; i --)
    {
        int s = x >> i & 1;
        if(son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
    else p = son[p][s];
    }
    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> num[i];
        insert(num[i]);
    }

    int res = 0;
    for(int i = 0 ; i < n; i ++)
    {
        res = max(res,query(num[i]));
    }

    cout << res << endl;
    return 0;
}