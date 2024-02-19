#include<bits/stdc++.h>
using namespace std;
const int M = 199933;
int f[100010];

int main(){
    int n;
    cin >> n;
    f[0] = 0;
    f[1] = 1;
    for(int i=2;i<=n;i++){
        f[i] = f[i-1] + f[i-2];
        f[i] %= M;
    }
    cout << f[n] << "\n";
    
    return 0;
}
