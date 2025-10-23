#include <iostream> 
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int ne[N],point[N],value[N],idx;

void insert(int x)
{
    int hash = (x % N + N) % N;
    value[idx] = x;
    ne[idx] = point[hash];
    point[hash] = idx ++;
}

bool query(int x)
{
    int hash = (x % N + N) % N;
    int t = point[hash];
    while(t != -1)
    {
        if(value[t] == x) return true;
        t = ne[t];
    }
    return false;
}

int main()
{
    memset(point,-1,sizeof point);
    int n ;
    cin >> n;
    for(int i = 1 ; i <= n; i ++)
    {
        char str[2];
        int num;
        cin >> str >> num;
        if(*str == 'I')
        {
            insert(num);
        }
        else
        {
            if(query(num))
            {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
    }


    return 0;
}