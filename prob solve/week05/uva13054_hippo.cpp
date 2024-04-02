#include <bits/stdc++.h>
using namespace std;
int hippo[100010], mark[100010];
int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int c, n, h, a, d;
    cin >> c;
    for(int i=1;i<=c;i++){
        int x = 0, y = 0;
        cin >> n >> h >> a >> d;
        for(int j=0;j<n;j++) cin >> hippo[j];
        sort(hippo, hippo+n);
        memset(mark, 0, sizeof(mark));
        int l = 0, r = n-1;
        while(l<=r){
            if(mark[l]==1) l++;
            if(l!=r && hippo[l]+hippo[r]<h && a*2>d){
                mark[l] = mark[r] = 1;
                r--;
                l++;
                y++;
            }
            else{
                mark[r] = 1;
                r--;
                x++;
            }
        }
        cout << "Case " << i << ": " << (x*a)+(y*d) << "\n";
    }

    return 0;
}