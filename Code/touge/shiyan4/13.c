#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    while(a!=1)
    {
        if(a%2==0)
        {
            a/=2;
            printf("%d ",a);
        }
        else
        {
            a=a*3+1;
            printf("%d ",a);
        }
    }
    return 0;
}