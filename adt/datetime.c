#include <stdio.h>
typedef struct datetime {
    int date; // 1-31
    int month; // 1-12
    int year; // 1970++
    int dayOfWeek; // 0-6
    int hour; // 0-23
    int minute; // 0-59
    int second; // 0-59
} datetime_t;
datetime_t createDate(int t) {
    datetime_t mydate;
    int day=t/(24*60*60);
    t-=day*(24*60*60);
    mydate.dayOfWeek=(4+day)%7;
    mydate.year=1970;
    mydate.month=1;
    mydate.hour=0,mydate.minute=0;
    int leap=0;
    while(day>=365+leap){
        if((mydate.year%4==0 && mydate.year%100!=0) || mydate.year%400==0) leap=1;
        else leap=0;
        mydate.year++;
        day-=365+leap;
    }
    int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((mydate.year%4==0 && mydate.year%100!=0) || mydate.year%400==0) m[1]++;
    for(int i=0;i<12;i++){
        if(day>=m[i]){
            day-=m[i];
            mydate.month++;
        }
    }
    mydate.date=day+1;
    while(t>=60*60){
        mydate.hour++;
        t-=60*60;
    }
    while(t>=60){
        mydate.minute++;
        t-=60;
    }
    mydate.second=t;
    return mydate;
}
datetime_t printDate(datetime_t mydate) {
    char dayofweek[10][5]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char month[20][20]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    printf("%s %d %s %d ",dayofweek[mydate.dayOfWeek],mydate.date,month[mydate.month-1],mydate.year);
    printf("%02d:%02d:%02d\n",mydate.hour,mydate.minute,mydate.second);
}
int main(void) {
    datetime_t inputDate;
    int timestamp;
    scanf("%d", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}