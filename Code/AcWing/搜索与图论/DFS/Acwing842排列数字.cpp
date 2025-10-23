#include <iostream>

using namespace std;

const int N = 10;

int n;
bool status[N];
int num[N];

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0 ; i < n; i ++)
        {
            printf("%d ",num[i]);
        }
        puts("");
        return;
    }
    
    for(int i = 1 ; i <= n; i ++)
    {
        if(!status[i])
        {
            num[u] = i;
            status[i] = true;
            dfs(u + 1);
            status[i] = false;
        } 
    }

}

int main()
{
    cin >> n;
    
    dfs(0);

    return 0;
}