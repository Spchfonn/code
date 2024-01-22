#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, l, mx = INT_MIN;
    cin >> n >> k >> l;
    int x[n];
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    sort(x, x+n);
    for(int i=0;i<n-(k+l);i++){
        mx = max(x[i+k+l]-x[i], mx);
    }
    cout << mx << "\n";
    
    return 0;
}