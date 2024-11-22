#include <stdio.h> 
int getWeek(int day)
{
	/**********Begin**********/
	int year=day/10000;
    int month=(day/100)%100;
    int ri=day%100;
    int week=(ri+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
    return week;
    /**********End**********/
}

void printWeek(int w)
{
	/**********Begin**********/
    if(w==1) printf("Mon");
    if(w==2) printf("Tue");
    if(w==3) printf("Wed");
    if(w==4) printf("Thr");
    if(w==5) printf("Fri");
    if(w==6) printf("Sat");
    if(w==7) printf("Sun");
    /**********End**********/
}
int main()
{
	int date;
   scanf("%d",&date);
   int week = getWeek(date);
   printWeek(week);
	return 0;
}
