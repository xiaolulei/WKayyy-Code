#include<stdio.h>
int main()
{

    return 0;
}
int stringcmp(int *s1,int *s2){
    while(*s1||*s2){
        if(*s1-*s2){
            break;
        }
        else{
            s1++;s2++;
        }
    }
    return *s1-*s2;
}