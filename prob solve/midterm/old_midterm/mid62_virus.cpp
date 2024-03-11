#include<bits/stdc++.h>
using namespace std;
list<int> l;
int main(){
    int n, m, t, x, y;
    cin >> n >>  m;
    while(n--){
        cin >> x;
        l.push_back(x);
    }
    auto it = l.begin();
    while(m--){
        cin >> t;
        if(t==1){
            it = l.begin();
        }
        else if(t==2){
            it++;
        }
        else if(t==3){
            cin >> y;
            auto pos = it;
            //pos--;
            if(pos==l.end()) pos = l.begin();
            l.insert(pos, y);
        }
        else if(t==4){
            cin >> y;
            auto pos = it;
            pos++;
            if(pos==l.end()) pos = l.begin();
            l.insert(pos, y);
        }
        if(it==l.end()) it = l.begin();
    }
    for(auto i:l) cout << i << "\n";

    return 0;
}