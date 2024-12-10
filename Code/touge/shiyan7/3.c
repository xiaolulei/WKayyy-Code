#include<stdio.h>
#include<math.h>
int main()
{
    int a[20],b[20];
    double ave1,ave2,sum=0;
    for(int i=0;i<20;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ave1=sum/20;
    int flag=0;
    int j=0;
    for(int i=0;i<20;i++){
        if((a[i]-ave1)>10||(a[i]-ave1)<-10){
        flag=1;
        b[j]=a[i];
        sum-=b[j];
        j++;
        }
    }
    if(flag){
        if(j<19){
            ave2=sum/(20-j);
            printf("所有评委平均分:%.3lf分.\n",ave1);
            printf("不合格得分:");
            for(int i=0;i<=(j-1);i++){
                printf("%d ",b[i]);
            }
            printf(".\n");
            printf("最后得分:%.3lf分.",ave2);
        }
        else{
            printf("所有评委平均分:%.3lf分.\n",ave1);
            printf("不合格得分:");
            for(int i=0;i<=(j-1);i++){
                printf("%d ",b[i]);
            }
            printf(".\n");
            printf("无合格打分.");
        }
    }
    else{
    ave2=ave1;
    printf("所有评委平均分:%.3lf分.\n",ave1);
    printf("无不合格得分.\n");
    printf("最后得分:%.3lf分.\n",ave1);
    }
    return 0;
}