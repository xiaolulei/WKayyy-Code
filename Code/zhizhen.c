#include<stdio.h>
void sort(int(*p[])[7],int n);
int main()
{
    int score[4][7]={{1,80,82,95,88,93,438},
                     {2,86,54,80,95,97,372},
                     {3,80,70,56,88,93,387},
                     {4,95,89,87,80,96,447}
                    };
    
    int n=4,(*p[4])[7];
    for(int i = 0; i < n; i++) {
        p[i]=&score[i];
    }
    sort(p,4);
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            printf("%d ",*(*p[i]+j));
        }
        printf("\n");
    }
    return 0;
}
void sort(int(*p[])[7],int n){
    for(int i=0;i<n-1;i++){
        int post=i;
        for(int j=i+1;j<n;j++){
            if(*(*p[i]+6)<*(*p[j]+6)){
                post=j;
            }
        }
        if(post!=i){
            int (*temp)[7];
            temp=p[i];
            p[i]=p[post];
            p[post]=temp;
        }
    }
}