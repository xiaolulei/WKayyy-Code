#include<stdio.h>
int main(){
    int N;
    int M;
    scanf("%d",&N);
    getchar();
    for(int i=1;i<=N;i++){
        scanf("%d",&M);
        getchar();
        int sum1=100/M;
        int a,b,c;
        char s[3];
        int sum2;
        float grade=0;
            for(int j=1;j<=M;j++){
                scanf("%d",&a);
                scanf("%c",&s[0]);
                scanf("%d",&b);
                scanf("%c",&s[1]);
                scanf("%d",&c);  
                if(b==0&&s[0]=='/') continue;
                if(!(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) continue;
                if(s[0]=='+'){
                    sum2=a+b;
                    if(sum2==c){
                        grade+=sum1;
                    }
                }
                if(s[0]=='-'){
                    sum2=a-b;
                    if(sum2==c){
                        grade+=sum1;
                    }
                }
                if(s[0]=='/'){
                    sum2=a/b;
                    if(sum2==c){
                        grade+=sum1;
                    }
                }
                if(s[0]=='*'){
                    sum2=a*b;
                    if(sum2==c){
                        grade+=sum1;
                    }
                }
            }
            printf("%.2f\n",grade);
        }
    return 0;
}