#include<stdio.h>
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        while(n/1000>0){
            printf("M");
            n-=1000;
        }
        while(n/900>0){
            printf("CM");
            n-=900;
        }
        while(n/500>0){
            printf("D");
            n-=500;
        }
        while(n/400>0){
            printf("CD");
            n-=400;
        }
        while(n/100>0){
            printf("C");
            n-=100;
        }
        while(n/90>0){
            printf("XC");
            n-=90;
        }
        while(n/50>0){
            printf("L");
            n-=50;
        }
        while(n/40>0){
            printf("XL");
            n-=40;
        }
        while(n/10>0){
            printf("X");
            n-=10;
        }
        while(n/9>0){
            printf("IX");
            n-=9;
        }
        while(n/5>0){
            printf("V");
            n-=5;
        }
        while(n/4>0){
            printf("IV");
            n-=4;
        }
        while(n/1>0){
            printf("I");
            n-=1;
        }
    }
    return 0;
}