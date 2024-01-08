#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main(){
    int m, menu, type, n;
    cin >> m;
    while(m--){
        cin >> menu;
        if(menu==1){
            cin >> type >> n;
            if(mp.find(type)!=mp.end()){
                mp[type] += n;
            }
            else mp[type] = n;
        }
        else if(menu==2){
            cin >> type;
            if(mp.find(type)!=mp.end()){
                cout << mp[type] << "\n";
            }
            else cout << 0 << "\n";
        }
        else if(menu==3){
            cin >> type >> n;
            if(mp.find(type)!=mp.end()){
                if(n<=mp[type]){
                    cout << n << "\n";
                    mp[type] -= n;
                }
                else{
                    cout << mp[type] << "\n";
                    mp[type] = 0;
                }
            }
            else cout << 0 << "\n";
        }
    }

    return 0;
}