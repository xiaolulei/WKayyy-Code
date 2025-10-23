#include <iostream>

using namespace std;

const int N = 1e6 + 10;
typedef pair<int,int> PII;
PII x[N];
int res[N];
int idx_res = 0,head = 1;    
int n,m,p = 1;

void kick()
{
    while (n > 1) {
        
        int t;
        for (int i = 1; i < m; ++i) 
        {
            t = p;
            p = x[p].first;
        }
        res[idx_res++] = p;
        m = x[p].second;
        x[t].first = x[p].first;
        p = x[p].first;
        n--;
    }
    res[idx_res] = p;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        int num;
        cin >> num;
        x[i].second = num;
        if(i != n)
        {
            x[i].first = i + 1;
        }
        else
        {
            x[i].first = head;
        }
    }
    cin >> m;
    kick();
    for(int i = 0 ; i <= idx_res; i ++)
    {
       cout << res[i] << ' '; 
    }
    return 0;
}
