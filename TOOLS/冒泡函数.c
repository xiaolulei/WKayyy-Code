#include <stdio.h>
void bubblesort(int arr[],int len);
int main(){
    int arr[]={5,3,8,6,2,7,1,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void bubblesort(int arr[],int len){
    int i,j,temp;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}