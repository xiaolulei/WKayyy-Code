#include <stdio.h>
#include <string.h>

int main()
{
    char a[19];
    fgets(a,sizeof(a),stdin);
    printf("%d",strlen(a));
    return 0;
}