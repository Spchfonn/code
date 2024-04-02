#include <bits/stdc++.h>
using namespace std;
int mor[110],eve[110];
int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int n,d,r;
    while(1){
        int cnt = 0;
        cin >> n >> d >> r;
        if(n==0 && d==0 && r==0) break;
        for(int i=0;i<n;i++) cin >> mor[i];
        for(int i=0;i<n;i++) cin >> eve[i];
        sort(mor, mor+n);
        sort(eve, eve+n);
        for(int i=0;i<n;i++){
            cnt += max(0,(mor[i]+eve[n-i-1])-d);
        }
        cout << cnt*r << "\n";
    }

    return 0;
}