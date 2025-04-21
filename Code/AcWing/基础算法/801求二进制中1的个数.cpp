#include<iostream>

using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int temp,ans=0;
        cin >> temp;
        while(temp)
        {
            temp -= lowbit(temp);
            ans++;
        }
        printf("%d ",ans);
    }
    
    return 0;
}