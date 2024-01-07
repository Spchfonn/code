#include<bits/stdc++.h>
using namespace std;
set<int> set_x;
int main() {
    int n, m, x, y;
    cin >> n >> m;
    while(n--){
        cin >> x;
        set_x.insert(x);
    }
    while(m--){
        cin >> y;
        auto it1 = set_x.lower_bound(y);
        auto it2 = set_x.lower_bound(y);
        it1--;
        if(abs(y-*it1)<=abs(y-*it2)){
            cout << *it1 << "\n";
        }
        else{
            cout << *it2 << "\n";
        }
    }

    return 0;
}
