#include <stdio.h>
#include<math.h>
int panda[101] = { 1, 1, 1, 1, 2 };
/**********Begin**********/
int panda_(int n){
    if(n<=4){
        return 1;
    }
    else{
        return panda_(n-1)+panda_(n-4);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int sum=panda_(n);
    printf("%d",panda_(n)%((long long)pow(10,7)+7));
    return 0;
}	 

/**********End**********/