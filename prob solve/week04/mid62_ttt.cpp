#include<bits/stdc++.h>
using namespace std;
list<int> arr[100010], q;
pair<int,int> edge[100010];
int mark[100010];
int main(){
    int n, m, u, v, ans = 0;
    cin >> n >> m;
    while(m--){
        int i = 0;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
        edge[i++] = make_pair(u, v);
    }
    for(int k=0;k<m;k++){
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
        if(ans==0){
            cout << edge[k].first << " " << edge[k].second << "\n";
            break;
        }
        else if(ans==1) continue;
        for(int i=1;i<=n;i++){
            arr[i].clear();
            mark[i] = 0;
        }
        if(!q.empty()) q.clear();
        memset(mark,0,sizeof mark);
    }

    return 0;
}