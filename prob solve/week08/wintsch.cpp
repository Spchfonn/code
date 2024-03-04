#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, s, t, cnt = 0;
    cin >> n;
    list<pair<int, int>> l;
    for(int i=0;i<n;i++){
        cin >> s >> t;
        l.push_back(make_pair(t,s));
    }
    l.sort();
    auto state = l.front();
    int last = state.first;
    cnt++;
    l.pop_front();
    while(!l.empty()){
        auto state = l.front();
        if(state.second>=last){
            cnt++;
            last = state.first;
        }
        l.pop_front();
    }
    cout << cnt << "\n";
    
    return 0;
}