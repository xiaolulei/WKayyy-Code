#include<stdio.h>
int main()
{
    int position;
    int n;
    int a[100];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        position = i;
        for(int j=i+1;j<=n;i++)
        {
            if(a[i]<a[j]) position=j;
        }
        if(position!=i)
        {
            int temp;
            temp=a[i];
            a[i]=a[position];
            a[position]=temp;
        }
    }
    return 0;
}