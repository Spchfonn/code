#include<bits/stdc++.h>
using namespace std;
int x[1010], y[1010], dis[1010];
int main(){
    int n, r, x_now = 0, y_now = 0, mx = INT_MIN, index = 0, cnt = 0, ans = 0;
    cin >> n >> r;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    x[n] = 100;
    y[n] = 100;
    while((x_now<100) && (y_now<100)){
        for(int i=0;i<=n;i++){
            if((x[i]>=x_now || y[i]>=y_now) && !(x[i]==x_now && y[i]==y_now)){
                dis[i] = ((x[i]-x_now)*(x[i]-x_now))+((y[i]-y_now)*(y[i]-y_now));
                if(dis[i]<=r*r){
                    mx = max(dis[i],mx);
                    index = i;
                }
            }
            else{
                dis[i] = -1;
            }
        }
        if(index==0 && mx==INT_MAX){
            ans = -1;
            break;
        }
        else{
            dis[index] = -1;
            x_now = x[index];
            y_now = y[index];
            cnt++;
        }
        
    }
    if(ans==-1) cout << ans << "\n";
    else cout << cnt << "\n";

    return 0;
}

/*
5 60
50 0
100 0
100 50
50 30
70 50
*/