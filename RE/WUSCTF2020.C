#include<stdio.h>
int ptr[18]={198,232,816,200,1536,300,6144,984,51200,570,92160,1200,565248,756,1474560,800,6291456,1782,65536000};
int main()
{
    
    for(int i=1;i<=19;++i)
    {
        if(i&1)
        printf("%ld\n",(unsigned int)(ptr[i]<<i));
    }

    return 0;
}