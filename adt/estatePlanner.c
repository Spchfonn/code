#include<stdio.h>
int main(){
    int m,n,ans=0,ch=0;
    int size[] = {65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2};
    scanf("%d %d",&m,&n);
    if(m%2==1 || n%2==1){
        ans+=(m+n);
        if(m%2==1 && n%2==1) ans--;
        m--,n--;
    }
    int curm=m,curn=n;
    for(int i=0;i<16;i++){
        while(ch==0 && curm>=size[i] && curn>=size[i]){
            ans++;
            curm-=size[i];
            curn-=size[i];
            ch=1;
        }
        if((m>=size[i] && curn>=size[i]) || (n>=size[i] && curm>=size[i])){
            if((m>=size[i] && curn>=size[i]) && (n>=size[i] && curm>=size[i])){
                ans--;
            }
            if(m>=size[i] && curn>=size[i]){
                ans+=(m/size[i]);
                curn-=size[i];
            }
            if(n>=size[i] && curm>=size[i]){
                ans+=(n/size[i]);
                curm-=size[i];
            }
        }
    }
    printf("%d",ans);
    return 0;
}