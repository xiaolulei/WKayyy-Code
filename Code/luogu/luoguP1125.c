#include<stdio.h>
#include<math.h>

int a[26];
int main()
{
    char str[110];
    gets(str);
    for(int i = 0;str[i];i++)
    {
        a[str[i]-'a']++;
    }
    int max = -1,min = 110;
    int falg = 0;
    for(int i = 0;i<25;i++)
    {
        if(a[i]>0)
        {
            if(a[i]>max)max = a[i];
            if(a[i]<min) min = a[i];
        }
    }
    int t = max - min;
    if(t>2)
    {
        for(int i = 2;i<sqrt(t);i++)
        {
            if(t%i==0)
            {
                falg = 1;
                break;
            }
        }
    }
    
    if(falg||t==1||t==0)
    {
        printf("No Answer\n0");
    }
    else 
    {
        printf("Lucky Word\n%d",t);
    }
    return 0;
}