#include<stdio.h>
int max(int a,int b){
    if(a>=b) return a;
    else return b;
}
int main(){
    int q,n,mx=-999999999;
    scanf("%d",&q);
    int arr[110]={0};
    while(q--){
        scanf("%d",&n);
        arr[n]++;
        mx = max(arr[n],mx);
    }
    for(int i=0;i<110;i++){
        if(arr[i]==mx){
            printf("%d ",i);
        }
    }
    return 0;
}