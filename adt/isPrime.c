#include<stdio.h>
#include<math.h>
int main(){
    int n,ch=0;
    scanf("%d",&n);
    if(n==0 || n==1) printf("0");
    else{
        for(int i=2;i<=pow(n,0.5);i++){
            if(n%i==0){
                printf("0");
                ch=1;
                break;
            }
        }
        if(ch==0) printf("1");
    }
    return 0;
}
//O(sqrt(n))