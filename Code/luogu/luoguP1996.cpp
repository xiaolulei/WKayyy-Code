#include <iostream>

using namespace std;

const int N = 110;

int ne[N] , e[N] , head = 1;

void remove(int num1, int num2)
{
    ne[num2] = ne[num1];
    ne[num1] = -1;
    printf("%d ",e[num1]);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1 ; i <= n ; i ++)
    {
        e[i] = i ;
        if(i != n)
        ne[i] = i + 1;
        else
        ne[i] = 1;
    }
    int remaining = n;  
    int current = head;
    int prev = n;
    while(remaining--)
    {
        int next = current;
        for(int i = 0 ; i < m - 1; i ++)
        {
            prev = next;      
            next = ne[next];   
        }
        
        head = ne[next];     
        remove(next, prev); 
        current = head;   
    }
    return 0;
}