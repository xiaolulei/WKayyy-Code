#include<stdio.h>
#include<math.h>
double len(double x1,double y1,double x2,double y2);
int main()
{
    double distance[3];
    double a[7];
    for(int i=0;i<6;i++){
        scanf("%lf",&a[i]);
    }
    distance[0]=len(a[0],a[1],a[2],a[3]);
    distance[1]=len(a[0],a[1],a[4],a[5]);
    distance[2]=len(a[2],a[3],a[4],a[5]);
    double temp=distance[0]+distance[1]+distance[2];
    printf("%.2lf\n",temp);
    return 0;
}
double len(double x1,double y1,double x2,double y2){
    double distance;
    distance=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return distance;
}