#include<stdio.h>
int two(int x){
    while(x!=1){
        if(x%2==1) return 0;
        else if(x/2==1) return 1;
        x/=2;
    }
}
int divide(int m,int n){
    int ans=0;
    if(m>n){
        int t=m;
        m=n,n=t;
    }
    if(m==0) return 0;
    else if(m==1) return n;
    else{
        for(int i=m;i>0;i--){ 
            if(two(i)){
                ans++;
                ans+=divide(m-i,n)+divide(i,n-i);
                break;
            }
        }
    }
    return ans;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",divide(m,n));

    return 0;
}
//O(nlog(n))