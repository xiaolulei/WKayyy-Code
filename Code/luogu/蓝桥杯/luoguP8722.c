#include<stdio.h>
int main()
{
    char str[6];
    int month,day;
    scanf("%s",str);
    if(str[0]=='J'){
        if(str[1]=='a') month=1;
        else if(str[2]=='n') month=6;
        else month=7;
        goto end;
    }
    if(str[0]=='F'){
        month=2;
        goto end;
    }
    if(str[0]=='M'){
        if(str[2]=='y') month=5;
        else month=3;
        goto end;
    }
    if(str[0]=='A'){
        if(str[1]=='p') month=4;
        else month=8;
        goto end;
    }
    if(str[0]=='S'){
        month=9;
        goto end;
    }
    if(str[0]=='O'){
        month=10;
        goto end;
    }
    if(str[0]=='N'){
        month=11;
        goto end;
    }
    if(str[0]=='D'){
        month=12;
    }
    end:
    day=(str[3]-'0')*10+(str[4]-'0');
    printf("%d %d\n",month,day);
    return 0;
}