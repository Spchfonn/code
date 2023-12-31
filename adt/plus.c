#include<stdio.h>
#include<string.h>
char x[100000],y[100000];
char a[100000],b[100000];
int main(){
    int ans[100000];
    int m,n,mx,tod=0,cnt=0;
    scanf("%s",&x);
    scanf("%s",&y);
    m=strlen(x),n=strlen(y);
    if(m>n) mx=m;  
    else mx=n;
    for(int i=strlen(x)-1,o=0;o<mx;i--,o++){
        if(o>=strlen(x)) a[o]='0';
        else a[o]=x[i];
    }
    for(int i=strlen(y)-1,o=0;o<mx;i--,o++){
        if(o>=strlen(y)) b[o]='0';
        else b[o]=y[i];
    }
    for(int i=0;i<mx;i++){
        if(i==mx-1){
            if((a[i]-'0')+(b[i]-'0')+tod>=10){
                ans[i] = (((a[i]-'0')+(b[i]-'0')+tod)%10);
                ans[i+1] = 1;
                cnt+=2;
            }
            else{
                ans[i] = (((a[i]-'0')+(b[i]-'0')+tod)%10);
                cnt+=1;
            }
        }
        else{
            ans[i] = (((a[i]-'0')+(b[i]-'0')+tod)%10);
            cnt+=1;
            if((a[i]-'0')+(b[i]-'0')+tod>=10){
                tod=1;
            }
            else tod=0;
        }
    }
    for(int i=cnt-1;i>=0;i--){
        printf("%d",ans[i]);
    }
    return 0;
}