#include<stdio.h>
#include<math.h>
int fac(int n){
    if(n==0) return 1;
    else return n*fac(n-1);
}
int main(){
    int q,n,num,i,ans,x;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&num);
        while(num>0){
            i=0,ans=num,n=num;
            int ch=0;
            for(int j=0;j<7;j++){
                x=n/(1000000/(int)pow(10,j));
                if(ch==0 && x==0){
                    continue;
                }
                else if(x>=0){
                    ch=1;
                    ans-=fac(x);
                }
                n-=x*(1000000/(int)pow(10,j));
            }
            if(ans==0){
                printf("%d\n",num);
                break;
            }
            num--;
        }
    }
    return 0;
}