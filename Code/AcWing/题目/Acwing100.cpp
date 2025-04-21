#include<iostream>
#include <algorithm>

using namespace std;

const int N=1e5+10;
int a[N],b[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin >> a[i];
    long long neg=0,pos=0;
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++)
    if(b[i]>0) pos+=b[i];
    else if(b[i]<0) neg-=b[i];
    cout << min(pos,neg)+abs(pos-neg) << endl;
    cout << abs(pos - neg) + 1 << endl;    
    return 0;
}