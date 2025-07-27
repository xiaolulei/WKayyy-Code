#include <iostream>

using namespace std;

int n;
int order[20];
bool chosen[20];

void calc(int x)
{
    if( x == n + 1)
    {
        for(int i = 1; i <= n ; i ++)
        {
            printf("%d ",order[i]);
        }
        puts("");
        return ;
    }
    for(int i = 1; i<=n; i++)
    {
        if(chosen[i]) continue;
        order[x] = i;
        chosen[i] = 1;
        calc(x + 1);
        chosen[i] = 0;
        order[x] = 0;
    }
}


int main()
{
    cin >> n;
    calc(1);
    return 0;
}


/*
    n = 2;
    calc(1)
    order[1] = 1;
    chosen[1] = 1;
    calc(2)
    order[2] = 2;
    chosen[2] = 1;
    calc(3)
    printf
    calc(2) k = 2
    order[2] = 0;
    chosen[2]= 0;
    calc(1) k = 1
    order[1] = 0;
    order[1] = 0;   
    进入for循环让2和1进行交换；
*/