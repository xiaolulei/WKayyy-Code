#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char sex;
    char name[20];
}dancer;

typedef struct 
{
    dancer* base;
    int front;
    int rear;
}dancerqueue;

void initqueue(dancerqueue* a)
{
    a = malloc(sizeof(dancerqueue));
    a -> base = malloc(sizeof(dancer) * 100);
    if(!a || !(a -> base))
    {
        printf("Error");
        exit(-1);
    }
}

int IsEmpty(dancerqueue* a)
{
    return (a -> front == a -> rear);    
}

void pushqueue(dancerqueue* a,dancer* b)
{
    if(IsEmpty(a))
    {
        a -> base[a -> front].sex = b -> sex;
        strcpy(a -> base[a -> front].name , b -> name);
        a -> rear ++;
    }   
    else
    {
        a -> base[a -> rear].sex = b-> sex;
        strcpy(a -> base[a -> rear].name, b-> name);
        a -> rear ++;
    }
}

dancer* popqueue(dancerqueue* a)
{
    if(IsEmpty(a))
    {
        printf("Error");
        exit(-1);
    }
    dancer* temp;
    temp -> sex = a -> base[a -> front].sex;
    strcpy(temp -> name , a -> base[a -> front].name);
    a -> front ++;
}

int main()
{
    

    return 0;
}