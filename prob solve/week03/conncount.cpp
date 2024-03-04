#include<bits/stdc++.h>
using namespace std;
list<int> a[100010], q;
int mark[100010];
int main(){
    int n, m, u, v, cnt = 1;
    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    q.push_back(1);
    mark[1] = cnt;
    for(int i=1;i<=n;i++){
        if(mark[i]==0) q.push_back(i);
        while(!q.empty()){
            int i = q.front();
            if(mark[i]!=0){
                for(auto j:a[i]){
                    if(mark[j]==0){
                        q.push_back(j);
                        mark[j] = mark[i];
                    }
                }
            }
            else{
                cnt++;
                mark[i] = cnt;
                for(auto j:a[i]){
                    if(mark[j]==0){
                        q.push_back(j);
                        mark[j] = mark[i];
                    }
                }
            }
            q.pop_front();
        }
    }
    cout << cnt << "\n";
    
    return 0;
}