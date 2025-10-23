#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n , m;
int g[N],cnt[N];

int find(int x)
{
    if(g[x] == x) return g[x];
    else g[x] = find(g[x]);
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
    {
        g[i] = i;
        cnt[i] ++;
    }

    for(int i = 1 ; i <= m ; i++)
    {
        string choice;
        cin >> choice;
        if(choice == "C")
        {
            int a , b;
            cin >> a >> b;
            a = find(a) , b = find(b);
            if (a != b)
            {
                g[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if(choice == "Q1")
        {
            int a,b;
            cin >> a >> b;
            if(find(a) == find(b)) cout << "Yes" <<endl;
            else cout << "No" << endl;
        }
        else
        {
            int a;
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}