#include<stdio.h>
int Leopard(char a,char a1,char b,char b1,char c,char c1);
int Flush_straight(char a,char a1,char b,char b1,char c,char c1);
int Flush_straight1(char a,char a1,char b,char b1,char c,char c1);
int Straight(char a,char a1,char b,char b1,char c,char c1);
int Straight1(char a,char a1,char b,char b1,char c,char c1);
int Same_king(char a,char a1,char b,char b1,char c,char c1);
int Same_king1(char a,char a1,char b,char b1,char c,char c1);
int Pair(char a,char a1,char b,char b1,char c,char c1);
int Pair1(char a,char a1,char b,char b1,char c,char c1);
int General(char a,char a1,char b,char b1,char c,char c1);
int General1(char a,char a1,char b,char b1,char c,char c1);
int sort(int a,int b,int c);
int chosesort(int flag[]);
int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        char a,b,c;//数字
        char a1,b1,c1;//字符
        int character[7];
        scanf("%c%c%c%c%c%c",&a,&a1,&b,&b1,&c,&c1);
        int flag[7]={0};
        flag[1]=Leopard(a,a1,b,b1,c,c1);
            if(flag[1]==1) character[1]=a+48;
            if(character[1]==49) character[1]=65;
            if(character[1]==59) character[1]=74;
            if(character[1]==60) character[1]=75;
            if(character[1]==61) character[1]=76; 
        flag[2]=Flush_straight(a,a1,b,b1,c,c1);
            if(flag[2]==1) character[2]=Flush_straight1(a,a1,b,b1,c,c1)+48;
            if(character[2]==59) character[2]=74;
            if(character[2]==49) character[2]=65;
            if(character[2]==60) character[2]=75;
            if(character[2]==61) character[2]=76;
        flag[3]=Straight(a,a1,b,b1,c,c1);
            if(flag[3]==1) character[3]=Straight1(a,a1,b,b1,c,c1)+48;
            if(character[3]==59) character[3]=74;
            if(character[3]==60) character[3]=75;
            if(character[3]==61) character[3]=76;
            if(character[3]==49) character[3]=65;
        flag[4]=Same_king(a,a1,b,b1,c,c1);
            if(flag[4]==1) character[4]=Same_king1(a,a1,b,b1,c,c1)+48;
            if(character[4]==59) character[4]=74;
            if(character[4]==60) character[4]=75;
            if(character[4]==61) character[4]=76;
            if(character[4]==49) character[4]=65;
        flag[5]=Pair(a,a1,b,b1,c,c1);
            if(flag[5]==1) character[5]=Pair1(a,a1,b,b1,c,c1)+48;
            if(character[5]==59) character[5]=74;
            if(character[5]==60) character[5]=75;
            if(character[5]==61) character[5]=76;
            if(character[5]==49) character[5]=65;
        flag[6]=General(a,a1,b,b1,c,c1);
            if(flag[6]==1) character[6]=General1(a,a1,b,b1,c,c1)+48;
            if(character[6]==59) character[6]=74;
            if(character[6]==60) character[6]=75;
            if(character[6]==61) character[6]=76;
            if(character[6]==49) character[6]=65;
        if(flag[1]!=0) flag[1]+=6;
        if(flag[2]!=0) flag[2]+=5;
        if(flag[3]!=0) flag[3]+=4;
        if(flag[4]!=0) flag[4]+=3;
        if(flag[5]!=0) flag[5]+=2;
        if(flag[6]!=0) flag[5]+=1;
        int position=chosesort(flag);
        if(position==1) {
            printf("Leopard ");
            printf("%c\n",character[1]);
        }
        if(position==2) {
            printf("Flush straight ");
            printf("%c\n",character[2]);
        }
        if(position==3) {
            printf("Straight ");
            printf("%c\n",character[3]);
        }
        if(position==4) {
            printf("Same king ");
            printf("%c\n",character[4]);
        }
        if(position==5) 
        {printf("Pair ");
        printf("%c\n",character[5]);
        }
        if(position==6) 
        {printf("General ");
        printf("%c\n",character[6]);
        }
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
int Flush_straight1(char a,char a1,char b,char b1,char c,char c1)
{
    int number[3];
    number[0]=(int)a-48;
    number[1]=(int)b-48;
    number[2]=(int)c-48;
    int flag=sort(number[0],number[1],number[2]);
    if(a1==b1&&b1==c1&&flag)
    {
        return number[0];
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
int Straight1(char a,char a1,char b,char b1,char c,char c1)
{
    int number[3];
    number[0]=(int)a-48;
    number[1]=(int)b-48;
    number[2]=(int)c-48;
    int flag=sort(number[0],number[1],number[2]);
    if(a1!=b1&&b1!=c1&&a1!=c1)
    {
        return number[0];
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
int Same_king1(char a,char a1,char b,char b1,char c,char c1)
{
        if(a1==b1&&b1==c1){
            int number[3];
            number[0]=(int)a-48;
            number[1]=(int)b-48;
            number[2]=(int)c-48;
            int flag=sort(number[0],number[1],number[2]);
            return number[0];
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
int Pair1(char a,char a1,char b,char b1,char c,char c1)
{
    if((a==b&&a!=c)||(a==c&&a!=b)||(b==c&&a!=b))
    {
        if(a1!=b1&&b1!=c1&&a1!=c1) {
            int number[3];
            number[0]=(int)a-48;
            number[1]=(int)b-48;
            number[2]=(int)c-48;
            int flag=sort(number[0],number[1],number[2]);
            return number[0];
        }
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
int General1(char a,char a1,char b,char b1,char c,char c1)
{
    if(a!=b&&b!=c)
    {
        int number[3];
            number[0]=(int)a-48;
            number[1]=(int)b-48;
            number[2]=(int)c-48;
            int flag=sort(number[0],number[1],number[2]);
            return number[0];
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