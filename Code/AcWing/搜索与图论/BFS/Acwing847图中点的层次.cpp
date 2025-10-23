#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n,m;
int e[N],ne[N],h[N],idx;
int d[N];

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx ++;
}
    
int bfs()
{
    memset(d,-1,sizeof d);
    queue<int> q;
    d[1] = 0;
    q.push(1);

    while(q.size())
    {
        auto t = q.front();
        q.pop();

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1)
            {
                q.push(j);
                d[j] = d[t] + 1;
            } 
        }
    }

    return d[n];
}

int main()
{
    memset(h,-1,sizeof h);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }

    cout << bfs() << endl;
    return 0;
}