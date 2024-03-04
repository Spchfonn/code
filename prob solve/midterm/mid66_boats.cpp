#include<bits/stdc++.h>
using namespace std;
int y[200010];
vector<int> set_x;
int main(){
    int n, m, x, ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        set_x.push_back(x);
    }
    sort(set_x.begin(), set_x.end());
    for(int i=0;i<m;i++){
        cin >> y[i];
    }
    for(int i=0;i<m;i++){
        auto it = lower_bound(set_x.begin(), set_x.end(), y[i]);
        if(*it < y[i] || set_x.empty()){
            ans = i;
            break;
        }
        set_x.erase(it);
    }
    cout << ans << "\n";
    
    return 0;
}

/*
5 6
10
20
5
7
10
4
17
9
10
1
2
*/