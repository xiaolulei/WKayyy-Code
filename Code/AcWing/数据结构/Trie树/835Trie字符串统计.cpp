#include <iostream>

using namespace std;

const int N = 1e5+10;

int idx;
int son[N][26];
int cnt[N];
char b[N];

void insert(char str[])
{
    int p = 0;
    for(int i = 0 ; str[i] ; i ++)
    {
        int u = str[i] - 'a'; 
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for(int i = 0 ; str[i] ; i ++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}



int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n; i ++)
    {
        char a[2];
        scanf("%s%s", a, b);
        if(a[0] == 'I')
        {
            insert(b);
        }
        else
        {
            printf("%d\n", query(b));
        }
    }
    return 0;
}