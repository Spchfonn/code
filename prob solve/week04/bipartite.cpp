#include<bits/stdc++.h>
using namespace std;
list<int> arr[100010], q;
int mark[100010];
int main(){
    int k, n, m, u, v, ans;
    cin >> k;
    while(k--){
        ans = 0;
        cin >> n >> m;
        while(m--){
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        q.push_back(1);
        mark[1] = 1;
        while(!q.empty()){
            int i = q.front();
            for(auto j:arr[i]){
                if(mark[j]==0){
                    q.push_back(j);
                    mark[j] = -mark[i];
                }
                else if(mark[i]==mark[j]){
                    ans = 1;
                    break;
                }
            }
            if(ans==1) break;
            q.pop_front();
        }
        if(ans==0) cout << "yes\n";
        else cout << "no\n";
        for(int i=1;i<=n;i++){
            arr[i].clear();
            mark[i] = 0;
        }
        if(!q.empty()) q.clear();
    }

    return 0;
}