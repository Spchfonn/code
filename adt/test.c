#include<stdio.h>
int main(){
    int x,y,z,ans;
    char a,b;
    scanf("%d %d %d %c %c",&x,&y,&z,&a,&b);
    ans=x;
    if(a=='y' || a=='Y'){
        ans+=y;
        if(b=='y' || b=='Y'){
            if(ans%z!=0){
                ans/=z;
                ans++;
            }
            else{
                ans/=z;
            }
        }
    }
    else{
        if(b=='y' || b=='Y'){
            if(ans%z!=0){
                ans/=z;
                ans++;
            }
            else{
                ans/=z;
            }
        }
    }
    printf("%d",ans);
    return 0;
}