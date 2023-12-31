#include<stdio.h>
int main(){
    int n;
    char x;
    scanf("%c %d",&x,&n);
    if(x=='N'){
        for(int i=0;i<=n;i++){
            for(int j=n-i;j>0;j--){
                printf(" ");
            }
            for(int j=i*2+1;j>0;j--){
                printf("#");
            }
            printf("\n");
        }
        for(int i=0;i<=n;i++){
            printf(" ");
            for(int j=0;j<n*2-1;j++){
                printf("#");
            }
            printf("\n");
        }
    }
    else if(x=='S'){
        for(int i=0;i<=n;i++){
            printf(" ");
            for(int j=0;j<n*2-1;j++){
                printf("#");
            }
            printf("\n");
        }
        for(int i=n;i>=0;i--){
            for(int j=n-i;j>0;j--){
                printf(" ");
            }
            for(int j=i*2+1;j>0;j--){
                printf("#");
            }
            printf("\n");
        }
    }
    else if(x=='E'){
        for(int i=0;i<n+1;i++){
            printf(" ");
        }
        printf("#\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n+3+i;j++){
                printf("#");
            }
            printf("\n");
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n*2+1-i;j++){
                printf("#");
            }
            printf("\n");
        }
        for(int i=0;i<n+1;i++){
            printf(" ");
        }
        printf("#\n");
    }
    else if(x=='W'){
        for(int i=0;i<n;i++){
            printf(" ");
        }
        printf("#\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                printf(" ");
            }
            for(int j=0;j<n+3+i;j++){
                printf("#");
            }
            printf("\n");
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<i+1;j++){
                printf(" ");
            }
            for(int j=0;j<n*2+1-i;j++){
                printf("#");
            }
            printf("\n");
        }
        for(int i=0;i<n;i++){
            printf(" ");
        }
        printf("#\n");
    }
    return 0;
}