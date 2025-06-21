#include <iostream>

using namespace std;

const int N =1e5 + 10;
int num[N];
int tt = -1 , hh;

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
       string op;
       int x;
       cin >> op ;
       if(op == "push")
       {
           cin >> x ;
           num[++ tt] = x;
       }
       else if(op == "pop") hh ++ ;
       else if(op == "query") cout << num[hh] << endl;
       else cout << (hh <= tt ? "NO" : "YES") << endl;
    }
    return 0;
}
