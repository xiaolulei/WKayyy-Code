#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
     for(int i=1;i<=N;i++)
    {
        char a,b,c;//数字
        char a1,b1,c1;//字符
        int character[7];
        scanf("%c%c%c%c%c%c",&a,&a1,&b,&b1,&c,&c1);
    }
    return 0;
}
int Leopard(char a,char a1,char b,char b1,char c,char c1)
{
    if(a==b&&b==c)  return 1;
}
int Flush_straight(char a,char a1,char b,char b1,char c,char c1)
{
    int number[3];
    number[0]=(int)a-48;
    number[1]=(int)b-48;
    number[2]=(int)c-48;
    int flag=sort(number[0],number[1],number[2]);
    if(a1==b1&&b1==c1&&flag)
    {
        return 1;
    }
    else return 0;
}
int Straight(char a,char a1,char b,char b1,char c,char c1)
{
    int number[3];
    number[0]=(int)a-48;
    number[1]=(int)b-48;
    number[2]=(int)c-48;
    int flag=sort(number[0],number[1],number[2]);
    if(a1!=b1&&b1!=c1&&a1!=c1)
    {
        return 1;
    }
    else return 0;
}
int Same_king(char a,char a1,char b,char b1,char c,char c1)
{
        if(a1==b1&&b1==c1){
            return 1;
        }
        else return 0;
}
int Pair(char a,char a1,char b,char b1,char c,char c1)
{
    if((a==b&&a!=c)||(a==c&&a!=b)||(b==c&&a!=b))
    {
        if(a1!=b1&&b1!=c1&&a1!=c1) return 1;
        else return 0;
    }
    else return 0;
}
int General(char a,char a1,char b,char b1,char c,char c1)
{
    if(a!=b&&b!=c)
    {
        return 1;
    }
    else return 0;
}
int sort(int a,int b,int c)
{
    int number[3];
    number[0]=a;
    number[1]=b;
    number[2]=c;
    int position=0;
    for(int i=0;i<=2;i++)
    {
        int p=0;
        if(number[position]<number[i]) position=i;
    }
    if(position!=0)
    {
        int temp=number[0];
        number[0]=number[position];
        number[position]=temp;
    }
    if(number[1]>number[2])
    {
        int temp=number[1];
        number[1]=number[2];
        number[2]=temp;
    }
    if(number[0]-1==number[1]&&number[1]-1==number[2])
    return 1;
    else return 0;
}
int chosesort(int flag[])
{
    int position=1;
    for(int i=1;i<=5;i++)
    {
        if(flag[i]>flag[position]) position=i;
    }
    return position;
}