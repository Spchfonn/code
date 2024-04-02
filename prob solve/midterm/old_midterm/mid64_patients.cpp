#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> arr;
int main(){
    int n, l, a, b, cnt = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> l;
        for(auto j:arr){
            int bb = j.first-1, aa = j.second;
            arr.erase(j);
            if(bb>0){
                arr.insert({bb, aa});
            }
            else if(bb==0){
                cnt -= aa;
            }
        }
        while(l--){
            cin >> a >> b;
            cnt += a;
            arr.insert({b, a});
        }
        for(auto j:arr){
            cout << "jj " << j.first << " " << j.second << "\n";
        }
        cout << "x " << cnt << "\n";
    }
    
    return 0;
}

/*
8
2 10 2 10 5
2 5 1 4 3
0
1 3 10
0
0
0
0
*/