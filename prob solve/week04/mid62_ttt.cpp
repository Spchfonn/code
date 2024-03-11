#include<bits/stdc++.h>
using namespace std;
list<int> arr[100010], q;
pair<int,int> edge[100010];
int mark[100010];
int main(){
    int n, m, u, v, ans = 0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
        edge[i] = make_pair(u, v);
    }
    for(int k=0;k<m;k++){
        ans = 0;
        for(int l=1;l<=n;l++){
            if(mark[l]!=0) continue;
            q.push_back(l);
            mark[l] = 1;
            while(!q.empty()){
                int i = q.front();
                q.pop_front();
                for(auto j:arr[i]){
                    if((j==edge[k].first && i==edge[k].second) || (i==edge[k].first && j==edge[k].second)) continue;
                    if(mark[i]==mark[j]){
                        ans = 1;
                        break;
                    }
                    if(mark[j]!=0) continue;
                    if(mark[j]==0){
                        q.push_back(j);
                        mark[j] = -mark[i];
                    }
                }
                if(ans==1) break;
            }
            if(ans==1) break;
        }
        if(ans==0){
            cout << edge[k].first << " " << edge[k].second << "\n";
            break;
        }
        if(!q.empty()) q.clear();
        memset(mark, 0, sizeof mark);
    }

    return 0;
}