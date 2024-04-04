#include<bits/stdc++.h>
using namespace std;
int dp[1010][110], mw[110];
pair<int,int> arr[1010];

int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int t, n, g, max_w;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
        cin >> g;
        int cnt = 0;
        for(int i=0;i<g;i++){
            memset(dp, 0, sizeof(dp));
            cin >> mw[i];
            max_w = mw[i];
            for(int j=1;j<=n;j++){
                for(int k=1;k<=max_w;k++){
                    if(arr[j-1].second > k) dp[j][k] = dp[j-1][k];
                    else dp[j][k] = max(dp[j-1][k], dp[j-1][k-arr[j-1].second] + arr[j-1].first);
                }
            }
            cnt += dp[n][max_w];
        }
        cout << cnt << "\n";
    }
    return 0;
}