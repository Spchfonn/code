// score: 50 [ PPPPPTTTTT ]
#include<bits/stdc++.h>
using namespace std;
list<int> arr;

int main(){
    int n, x, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        arr.push_back(x);
    }
    for(int i=0;i<n;i++){
        int cnt = 0;
        int ch = 1;
        for(auto j:arr){
            if(j==ch) cnt++;
            ch++;
        }
        ans = max(ans, cnt);
        int tmp = arr.front();
        arr.pop_front();
        arr.push_back(tmp);
    }
    cout << ans << "\n";
    
    return 0;
}