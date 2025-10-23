#include <iostream>

using namespace std;

const int Ma = 1e6 + 10;

int N, M;
int son[Ma][26];
int cnt[Ma];
char s[Ma];
int idx;

void insert(char s[])
{
    int p = 0;
    for(int i = 0; s[i] ; i ++)
    {
        int x = s[i] - 'a';
        if(!son[p][x]) son[p][x] = ++idx;
        p = son[p][x];
    }
    cnt[p]++;
}

int query(char s[])
{
    int p = 0 , res = 0;
    for(int i = 0 ; s[i] ; i ++)
    {
        int x = s[i] - 'a';
        if(!son[p][x]) break;
        p = son[p][x];
        res += cnt[p];
    }
    return res;
}

int main()
{
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i ++)
    {
        cin >> s;
        insert(s);
    }
    for(int i = 1; i <= M ; i ++)
    {
        cin >> s;
        cout << query(s) << endl;
    }
    
    return 0;
}