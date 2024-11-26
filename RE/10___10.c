#include <stdio.h>
int main() {
    int i;
    scanf("%d",&i);
    getchar();
    for(int j=1;j<=i;j++){
        char a;
        scanf("%c",&a);
        int cout = (int)a;
        printf("%d ",cout);
    }
    return 0;
}
//[42,70,39,34,78,44,34,40,73,63,43,64]