#include<stdio.h>
int main(){
    int n,sum=0;
    char a[51];
    scanf("%d",&n);
    char c=getchar();
    for(int i=0;i<51;i++){
        scanf("%c",&a[i]);
        sum++;
        if(a[i]=='\n') {
            break;
            }
    }
    for(int j = 0; a[j]; j++)
        printf("%c",a[j]); 

        printf("\n");
    return 0;
}