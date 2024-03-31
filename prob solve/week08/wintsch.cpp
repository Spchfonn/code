#include<bits/stdc++.h>
using namespace std;
int dp[1010], t[1010], w[1010];
pair<int, int> s[1010];
vector<int> ans;
int main(){
    int n, st;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> st >> t[i] >> w[i];
        s[i] = make_pair(st, i);
    }
    sort(s, s+n);
    for(int i=1;i<=n;i++){
        int j;
        for(j=i-1;j>0;j--){
            if(t[j]<=s[i].first) break;
        }
        // dp[i] = max(dp[i-1], dp[j]+w[s[i].second]);
        if(dp[j]+w[s[i].second] > dp[i-1]){
            dp[i] = dp[j]+w[s[i].second];
            ans.push_back(i);
        }
        else dp[i] = dp[i-1];
    }
    // cout << "\n";
    // for(int i=1;i<=n;i++) cout << dp[i] << " ";
    cout << "\n";
    cout << dp[n] << "\n";
    for(auto i:ans){
        cout << i << " ";
    }
    
    
    return 0;
}


/*
3
1 3 2
2 4 3
3 5 2
*/