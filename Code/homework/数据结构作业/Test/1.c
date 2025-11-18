#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int value;
    link* nextnode;
}link;

link* firstnode;

int initlist()
{
    firstnode = malloc(sizeof(link));
}

link* querry(link* firstnode,int i)
{
    link* p;
    while(i --)
    {
        p = p->nextnode;
    }
    return p;
}

link* find(link* firstnode,int value)
{
    link* p;
    while(p != NULL)
    {
        if(p->value == value) break;
        else p = p->nextnode;
    }
    return p;
}

int insertnode(link* firstnode,int i,int insert_value)
{
    link* p = firstnode;
    int j = 0;
    while((j < i) && p)
    {
        p = p->nextnode;
        ++j;
    }
    if(j == i)
    {
        link* s = malloc(sizeof(link));
        if(s == NULL) return -1;
        s->nextnode = p->nextnode;
        p->nextnode = s;
        s->value = insert_value;
    }
    else
    {
        return -1;
    }
}

int main()
{
    

    return 0;
}