#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 110;

int n,m;
typedef pair<int,int> PII;
int g[N][N],d[N][N];

int bfs()
{
    queue<PII> q;

    memset(d,-1,sizeof d);
    d[0][0] = 0;
    q.push({0,0});
    
    int dx[4] = {-1, 0 , 1 , 0},dy[4] = {0 , 1 , 0 ,-1};
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        for(int i = 0 ; i < 4; i ++)
        {
            int x = t.first + dx[i],y = t.second + dy[i];
            if(d[x][y] == -1 && x < n && y < m && x >= 0 && y >= 0 && g[x][y] == 0)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x,y});
            }
        }
    }
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            cin >> g[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}