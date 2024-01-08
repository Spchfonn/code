#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main(){
    int n, x, mx = INT_MIN, ans;
    cin >> n;
    while(n--){
        cin >> x;
        if(mp.find(x)!=mp.end()){
            mp[x]++;
        }
        else{
            mp[x] = 1;
        }
        if(mp[x]>=mx){
            mx = mp[x];
            ans = x;
        }
        cout << ans << "\n";
    }
    
    
    return 0;
}