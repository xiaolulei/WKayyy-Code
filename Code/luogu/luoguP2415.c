#include<stdio.h>
#include<stdlib.h>
int main()
{
    char num[31];
    int i=0;
    while((scanf("%d",&num[i]))!='\n'){
        atoi(&num[i]);
        i++;
    }
    for(int j=0;j<=i;j++){
        printf("%d ",num[j]);
    }
    return 0;
}