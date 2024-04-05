#include<bits/stdc++.h>
using namespace std;
int dp[200010], arr[200010];
int main(){
    int n , q, x, menu, num;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> x;
        if(i==0) dp[i] = x;
        else dp[i] = min(x, dp[i-1]);
        arr[n-i-1] = dp[i];
    }
    // for(int i=0;i<n;i++){
    //     ch[n-i-1] = arr[i];
    // }
    while(q--){
        cin >> menu >> num;
        if(menu==1){
            cout << dp[num-1] << "\n";
        }
        else if(menu==2){
            int ans = lower_bound(arr, arr+n, num) - arr;
            cout << n - ans << "\n";
        }
    }
    return 0;
}