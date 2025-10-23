#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int p[N],res[N];
int n,m,idx = 0,current = 0;

void kick()
{
    int tn = n;
    int i = 1;
    while (n > 0)
    {
        while (true)
        {
            if (p[i] != -1) 
            {
                current++;
                if (current % m == 0)  
                {
                    res[idx++] = p[i];  
                    p[i] = -1;          
                    n--;               
                    break;
                }
            }
            i++;
            if (i > tn) i = 1;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n ; i ++)
    {
        int value;
        cin >> value;
        p[i] = value;
    }
    
    cin >> m;
    
    kick();

    for(int i = 0; i < idx ; i ++)
    {
        cout << res[i] << ' '; 
    }

    return 0;
}