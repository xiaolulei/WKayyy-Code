#include<stdio.h>
int findLongest(char str[]);
int main(){
    char sArr[100]={0};
    int loc,i;
    gets(sArr);
    loc=findLongest(sArr);
    for(i=loc;sArr[i]!=' '&&sArr[i]!='\0';i++){
        putchar(sArr[i]);
    }
    return 0;
}

int findLongest( char str[] ){
    int i = 0, Loc = 0, len = 0, lLoc = 0;
    while (str[i] != '\0') {
    while (str[i] == ' ')
    i++;
    lLoc = i;
    while (str[i] != ' ' && str[i] != '\0')
    i++ ; 
    if (i -lLoc > len) {
    len=i-lLoc; 
    Loc = lLoc;
    }
    } 
    return Loc;
}
