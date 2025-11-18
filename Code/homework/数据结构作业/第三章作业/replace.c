#include <stdio.h>
#include <string.h>

#define maxlen 100

int position[maxlen]; //存储v出现的起始地址
int position_idx = 0;

void KMP(char* s,char* v,int slen,int vlen)
{
    int ne[maxlen];
    ne[0] = -1;
    for(int i = 1,j = -1; i < vlen; i ++)
    {
        while(j != -1 && v[i] != v[j + 1]) j = ne[j];
        if(v[i] == v[j + 1]) j ++;
        ne[i] = j;
    }

    for(int i = 0,j = -1; i < slen; i ++)
    {
        while(j != -1 && s[i] != v[j + 1]) j = ne[j];
        if(s[i] == v[j + 1]) j ++;
        if( j == vlen - 1)
        {
            position[position_idx++] = i - j;
            j = ne[j]; 
        }
    }
}

void cout_t(char* t,int tlen)
{
    for(int i = 0 ; i < tlen ; i ++) printf("%c",t[i]);
}

void replace(char* s,char* v,char* t,int slen,int vlen, int tlen)
{
    KMP(s,v,slen,vlen);
    for(int i = 0,tidx = 0; i < slen; i ++)
    {
        if(tidx < position_idx && position[tidx] == i)
        {
            tidx ++;
            cout_t(t,tlen);
            i += vlen - 1;
            continue;
        }
        printf("%c",s[i]);
    }
}

int main()
{
    printf("Enter the s:");
    char s[maxlen];
    fgets(s,sizeof(s),stdin);
    printf("Enter the v:");
    char v[maxlen];
    fgets(v,sizeof(v),stdin);
    printf("Enter the t:");
    char t[maxlen];
    fgets(t,sizeof(t),stdin);
    int vlen = strlen(v) - 1,slen = strlen(s) - 1, tlen = strlen(t) - 1;
    replace(s,v,t,slen,vlen,tlen);
    return 0;   
}