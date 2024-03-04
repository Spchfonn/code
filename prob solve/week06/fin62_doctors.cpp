#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX_N = 100010;

int n, m, l;
vector<int> adj[MAX_N];
vector<int> weights[MAX_N];
int deg[MAX_N], r[MAX_N];
set<pair<int,int>> Q;

void read_input(){
    cin >> n >> m >> l;
    for(int u=0;u<n;u++){
        deg[u] = 0;
        cin >> r[u];
    }
    for(int i=0;i<m;i++){
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

int d[MAX_N];
const int INFINITY = 1000000000;
bool explored[MAX_N];
void dijkstra(int s){
    for(int u=0;u<n;u++){
        d[u] = INFINITY;
        explored[u] = false;
    }
    d[0] = 0;
    Q.insert(make_pair(0,s));
  
    while(!Q.empty()) {
        auto pu = *(Q.begin());
        Q.erase(Q.begin());
        int u = pu.second;
        if(explored[u])
            continue;
    
        //cout << u << " " << du << endl;
        explored[u] = true;
        for(int dd=0;dd<deg[u];dd++) {
            int v = adj[u][dd];
            if(d[v] > d[u] + weights[u][dd]) {
                d[v] = d[u] + weights[u][dd];
                Q.insert(make_pair(d[v],v));
            }
        }
    }
}

main(){
    int total_weight = 0;
    read_input();
    dijkstra(0);
    for(int i=0;i<n;i++){
        total_weight += min(d[i]*l, d[i]*r[i]);
    }
    cout << total_weight << endl;
}