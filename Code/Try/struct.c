#include<stdio.h>


int min(int x,int y)
{
    if(x<y) return x;
    else return y;
}


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[m];
    int t=1000;
   
    for(int i = 0;i < m;i ++)
    {
        scanf("%d", &a[i]);
    }
    if((n-m)>=2)
    {
        t=0;
    }
    else if((n-m)==1)
    {
        for(int i=0;i<m;i++)
        {
            t = min(t,a[i]);
        }
    }
    else{
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<m-1-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        t=a[1];
    }
    int num=20+t;
    printf("%d",num);
    return 0;
}