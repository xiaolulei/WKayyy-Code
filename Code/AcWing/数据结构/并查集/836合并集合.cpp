#include <iostream> 

using namespace std;

const int N = 1e5+10;

int n, m;
int g[N];

int find(int x)
{
    if(g[x] == x) return g[x];
    else g[x] = find(g[x]);
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)  g[i] = i; 

    char choice[2];
    int a,b;
    for(int i = 1 ; i <= m ; i ++)
    {
        cin >> choice >> a >> b;
        if(choice[0] == 'M')
        {
            g[find(b)] = find(a);  
        }
        else
        {
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}