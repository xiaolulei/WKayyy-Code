#include<iostream>

using namespace std;

const int N = 100010;
int num[N];

int main()
{
    int n,q;
    cin >> n >> q;
    for(int i = 0;i < n; i ++) cin >> num[i];

    while(q--)
    {
        int temp;
        cin >> temp;

        int l = 0 , r = n - 1;
        while(l < r)
        {
            int mid = r + l >> 1;
            if(num[mid] >= temp) r = mid; 
            else l = mid + 1;
        }

        if(num[l] != temp) cout << "-1 -1" << endl;
        else
        {
            cout << l << " " ;

            int l = 0 , r = n - 1;
            
            while(l < r)
            {
            int mid = r + l + 1 >> 1;
            if(num[mid] <= temp) l = mid;
            else r = mid - 1;
            }
            cout << l << endl ;
        }
    }
    return 0;
}