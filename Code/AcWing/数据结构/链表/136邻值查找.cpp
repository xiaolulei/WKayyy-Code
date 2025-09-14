#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

typedef long long LL;
typedef pair <LL,int> PII;

PII a[N],ans[N];

int n;
int l[N],r[N],p[N];

int main()
{
    cin >> n;

    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1 , a + 1 + n);

    a[0].first = -1e9 , a[n + 1].first = 1e9;

    for(int i = 1 ; i <= n ; i ++)
    {
        l[i] = i - 1 , r[i] = i + 1;
        p[a[i].second] = i;
    }

    for(int i = n ; i > 1 ; i --)
    {
        int j = p[i] , left = l[j] , right = r[j];
        LL leftnum = abs(a[left].first - a[j].first);
        LL rightnum = abs(a[right].first - a[j].first);
        if(leftnum <= rightnum) ans[i] = {leftnum,a[left].second};
        else
        {
            ans[i] = {rightnum,a[right].second};
        }
        r[left] = right , l[right] = left;
    }

    for(int i = 2; i <= n ; i ++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}