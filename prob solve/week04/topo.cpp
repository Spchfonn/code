#include<bits/stdc++.h>
using namespace std;
list<int> arr[100010];
queue<int> q;
int mark[100010];
int main(){
    int n, m, u, v;
    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        arr[u].push_back(v);
        mark[v]++;
    }
    for(int i=1;i<=n;i++){
        if(mark[i]==0) q.push(i);
    }
    if(q.empty()) cout << "no\n";
    else{
        while(!q.empty()){
            int current = q.front();
            for(auto x:arr[current]){
                mark[x]--;
                if(mark[x]==0) q.push(x);
            }
            cout << current << "\n";
            q.pop();
        }
    }
    
    return 0;
}