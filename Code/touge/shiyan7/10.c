    #include<stdio.h>
    int num[101];
    int main()
    {
        int N,s;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&num[i]);
        }
        scanf("%d",&s);
        int flag=num[0];
        int gap=s-num[0];
        if(gap==0) {
                printf("%d",num[0]);
                return 0;
            }
        for(int i=1;i<N;i++){
            int temp=s-num[i];
            if(temp==0) {
                printf("%d",num[i]);
                return 0;
            }
            if(temp<0) temp=temp*(-1);
            if(temp<gap){
                flag=num[i];
                gap=temp;
            }
        }
        printf("%d",flag);
        return 0;
    }