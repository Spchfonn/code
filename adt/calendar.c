#include<stdio.h>
#include<math.h>
int main(){
    int y,m;
    char mont[20][20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    char day[40][5] = {"   ","  1","  2","  3","  4","  5","  6","  7","  8","  9"," 10"," 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20"," 21"," 22"," 23"," 24"," 25"," 26"," 27"," 28"," 29"," 30"," 31"};
    int days[20] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int ofs[20] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    printf("Enter year: ");
    scanf("%d",&y);
    printf("Enter month: ");
    scanf("%d",&m);
    printf("====================\n");
    printf("%s %d\n",mont[m-1],y);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int cnt = 0, wan = 1;
    int four = 0;
    for(int i=1990;i<y;i++){
        if(i%4==0 && i%100!=0) four++;
        else if(i%400==0) four++;
    }
    int temp = ofs[m-1]%7;
    if(((y%4==0 && y%100!=0) || y%400==0) && m>=2){
        if(m==2) days[2]=29;
        else four++;
    }
    int tmp = (1+four+temp+(y-1990))%7;
    for(int i=0;i<tmp;i++){
        printf("%s",day[0]);
        printf(" ");
        cnt++;
    }
    for(int i=1;i<=days[m];i++){
        printf("%s",day[i]);
        cnt++;
        printf(" ");
        if(cnt%7==0) printf("\n");
        else if(i==days[m]) printf("\n");
    }
    return 0;
}