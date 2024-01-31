#include<bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

int n,m;
vector<int> adj[100010], weights[100010];
int deg[100010];
set<pair<int,int>> Q;

void read_input(){
    cin >> n >> m;
    for(int i=0; i<n; i++) deg[i] = 0;
    for(int i=0; i<m; i++) {
        int a,b,w;
        cin >> a >> b >> w;  a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[a].push_back(w);
        weights[b].push_back(w);
        deg[a]++;
        deg[b]++;
    }
}

int d[100010];
const int inf = 1000000000;
bool explored[100010];
void dijkstra(int s){
    for(int i=0; i<n; i++){
        d[i] = inf;
        explored[i] = false;
    }
    d[0] = 0;
    Q.insert(make_pair(0,s));
    while(!Q.empty()) {
        auto pu = *(Q.begin());
        Q.erase(Q.begin());
        int u = pu.second;
        if(explored[u]) continue;
        explored[u] = true;
        for(int dd=0; dd<deg[u]; dd++) {
            int v = adj[u][dd];
            if(d[v] > d[u] + weights[u][dd]) {
	            d[v] = d[u] + weights[u][dd];
	            Q.insert(make_pair(d[v],v));
            }
        }
    }
}

main(){
    read_input();
    dijkstra(0);
    cout << d[n-1] << "\n";
}