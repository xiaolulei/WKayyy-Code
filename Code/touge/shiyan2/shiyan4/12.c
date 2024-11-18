#include<stdio.h>
void solve(int n)
{
    int a[6];
    for(int i = 0;i<6;i++)a[i] = 0;
    for(int i = 1;i<=n;i++)
    {
        int b;
        scanf("%d",&b);
        a[b]++;
    }

    int max = -1;
    for(int i = 1;i<=5;i++)
    {
        if(max<a[i])
        {
            max = a[i];
        }
    }
    char str[30][20];
    for(int i = 1;i<=max;i++)
    {
        for(int j = 1;j<=9;j++)
        {
            str[i][j] = ' ';
        }
    }
    for(int j = 1,p = 1;j<=5;j++,p+=2)//1 3 5 7 9
    {
        for(int i = max;i>(max-a[j]);i--)
        {
            str[i][p] = '*';
        }
    }
    int arr[6] = {0};
    for(int i = 1;i<=max;i++)
    {
        for(int j = 1;j<=9;j++)
        {
            if(str[i][j]=='*')arr[i] = j;
        }
    }
    for(int i = 1;i<=max;i++)
    {
        for(int j = 1;j<=arr[i];j++)
        {
            printf("%c",str[i][j]);
        }
        printf("\n");
    }
    for(int i = 1;i<5;i++)printf("%d ",i);
    printf("5");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        solve(n);
        printf("\n");
    }
    return 0;
}