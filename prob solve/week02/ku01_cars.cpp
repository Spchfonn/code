#include<bits/stdc++.h>
using namespace std;
int v[200010];
int main(){
    int n, p, cnt = 0, mx = INT_MIN;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p >> v[i];
    }
    for(int i=n-1;i>=0;i--){
        if(mx<v[i]){
            mx = max(mx,v[i]);
        }
        else if(v[i]<mx){
            cnt++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}