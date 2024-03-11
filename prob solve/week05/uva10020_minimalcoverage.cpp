#include<bits/stdc++.h>
using namespace std;
pair<int,int> all[100010], solution[100010];

int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int t, m, l, r;
    cin >> t;
    while(t--){
        cin >> m;
        int numpairs = 0;
        while(1){
            cin >> l >> r;
            if(l==0 && r==0) break;
            if(r<0 || l>m) continue;
            all[numpairs] = {l, r};
            numpairs++;
        }    
        sort(all, all + numpairs);
        int cnt = 0, currentX = 0, currentPair = 0;
        while(currentX < m && currentPair < numpairs){
            solution[cnt].second = currentX;
            while(all[currentPair].first<=currentX && currentPair<numpairs){
                if(all[currentPair].second > solution[cnt].second){
                    solution[cnt] = all[currentPair];
                }
                currentPair++;
            }
            if(solution[cnt].second == currentX) break;
            currentX = solution[cnt].second;
            cnt++;
        }
        if(currentX >= m){
            cout << cnt << "\n";
            for(int i=0;i<cnt;++i){
                cout << solution[i].first << " " << solution[i].second << endl;
            }
        }
        else cout << "0\n";
        if(t!=0) cout << "\n";
    }
    return 0;
}