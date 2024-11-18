#include<stdio.h>
int main()
{
    int repeat,n;
    scanf("%d",&repeat);
    for(int i=1;i<=repeat;i++)
    {
        int count[6]={0};
        int number[1000];
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            int rank;
            scanf("%d",&rank);
            if(rank==1) count[1]++;
            if(rank==2) count[2]++;
            if(rank==3) count[3]++;
            if(rank==4) count[4]++;
            if(rank==5) count[5]++;
        }
        int max=0;
        for(int i=1;i<=5;i++)
        {
            if(count[i]>max) max=count[i];
        }
        
            for(int i=1;i<=max;i++)
            {
                for(int s=1;s<=5;s++)
                {
                    if(count[s]>=i)
                    number[i]++;
                }
            }
        for(int j=max;j>0;j--)
        {   
            int sum=0;
            for(int i=1;i<=5;i++)
            {
                if(count[i]>=j) printf("*");
                else printf(" ");
                if(i<5) printf(" ");
            }
            printf("\n");
        }
        for(int i=1;i<=4;i++){
            printf("%d ",i);
        }
        printf("5\n");
    }
    return 0;
}
