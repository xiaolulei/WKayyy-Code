#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
const int N = 10010;

int height[N];

int main()
{
    int n,m,h,p;
    set<pair<int,int>> plus;
    cin >> n >> m >> h >> p;
    height[1]=h;
    for(int i=1,a,b;i<=p;i++)
    {
        cin >> a >> b;
        if( a > b ) swap(a,b);
        if(!plus.count({a,b}))
        {
            plus.insert({a,b});
            height[a+1]--,height[b]++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        height[i]+=height[i-1];
        cout << height[i] << endl;
    }
    return 0;
}