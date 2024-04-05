#include <bits/stdc++.h>
using namespace std;
long long x[100010];
vector<long long> V;
int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    long long test, t=1;
    cin >> test;
    while(test--){
        long long n,k;
        cin >> n >> k;
        for(long long i=1;i<=n;i++){
            cin >> x[i];
        }
        for(long long i=1;i<=n;i++){
            long long v;
            cin >> v;
            long long dif=v-x[i];
            V.push_back(dif);
        }
        sort(V.begin(),V.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            if(V[i]<0 && k>0){
                k--;
                continue;
            }
            ans += V[i];
        }
        cout << "Case " << t++ << ": ";
        if(ans>0) cout << ans << "\n";
        else cout << "No Profit\n";
        while(!V.empty()) V.clear();
    }
    return 0;
}