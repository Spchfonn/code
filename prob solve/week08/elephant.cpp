#include<bits/stdc++.h>
using namespace std;
int seq[100010], arr[100010];
int main(){
    int n, x, y;
    cin >> n;
    cin >> x >> y;
    arr[0] = 0, arr[1] = 0, arr[2] = 0;
    for(int i=3;i<=n;i++){
        cin >> seq[i];
        arr[i] = max(arr[i-3] + seq[i], arr[i-1]);
    }
    cout << arr[n] << "\n";
    
    return 0;
}