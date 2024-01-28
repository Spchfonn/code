#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, d, c, finish = 0, mx = INT_MIN;
    cin >> n;
    while(n--){
        cin >> d >> c;
        v.push_back(make_pair(d, c));
    }
    sort(v.begin(), v.end());
    for(auto x:v){
        finish += x.second;
        int late = finish-x.first-10;
        if(late < 0) late = 0;
        mx = max(late, mx);
    }
    cout << mx*1000 << "\n";

    return 0;
}