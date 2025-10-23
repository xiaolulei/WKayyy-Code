#include <iostream>

using namespace std;

const int N = 20;

char g[N][N];
bool col[N],dix[N],udix[N];

int n;

void dfs(int u)
{
    if( u == n)
    {
        for(int i = 0 ; i < n ; i ++)
        {
            puts(g[i]);
        }
        puts("");
        return;
    }

    for(int i = 0 ; i < n ; i ++)
    {
        if(!col[i] && !dix[u - i + n] && !udix[ u + i ])
        {
            g[u][i] = 'Q';//相当于标记当前节点已经用过了
            col[i] = dix[u - i + n] = udix[u + i] = true;
            dfs(u + 1);
            col[i] = dix[u - i + n] = udix[u + i] = false;
            g[u][i] = '.';//取消该节点的标记
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            g[i][j] = '.';
        }
    }

    dfs(0);

    return 0;
}