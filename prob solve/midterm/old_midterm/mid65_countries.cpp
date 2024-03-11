#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const int MAX_N = 100010;
int n, m, r, c, a, b, x, y;
int arr[35][35];
vector<int> adj[MAX_N];
vector<int> weights[MAX_N];
int deg[MAX_N];
set<pair<int,int>> Q, collect;
set<int> myset;

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
    
    while(!Q.empty()){
        auto pu = *(Q.begin());
        Q.erase(Q.begin());
        int u = pu.second;
        if(explored[u]) continue;
        
        //cout << u << " " << du << endl;
        explored[u] = true;
        for(int dd=0;dd<deg[u];dd++){
            int v = adj[u][dd];
            if(d[v] > d[u] + weights[u][dd]){
                d[v] = d[u] + weights[u][dd];
                Q.insert(make_pair(d[v],v));
            }
        }
    }
}

main(){
    cin >> r >> c >> a >> b >> x >> y;
    int u = 0, v = 0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> arr[i][j];
            myset.insert(arr[i][j]);
            if((arr[i][j] != arr[i-1][j]) && i != 1){
                u = arr[i][j], v = arr[i-1][j];
            }
            // else if((arr[i][j] != arr[i+1][j]) && i != r){
            //     u = arr[i][j], v = arr[i+1][j];
            // }
            else if((arr[i][j] != arr[i][j-1]) && j != 1){
                u = arr[i][j], v = arr[i][j-1];
            }
            // else if((arr[i][j] != arr[i][j+1]) && j != c){
            //     u = arr[i][j], v = arr[i][j+1];
            // }
            if(u!=0 && v!=0){
                if(u>v) swap(u, v);
                auto it = collect.find(make_pair(u, v));
                if(it == collect.end()){
                    collect.insert(make_pair(u, v));
                } 
            }
        }
    }
    n = myset.size();
    for(int i=0;i<=n;i++) deg[i] = 0;
    for(auto i:collect){
        int u = i.first, v = i.second;
        //cout << u << " " << v << "\n";
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weights[u].push_back(1);
        weights[v].push_back(1);
        deg[u]++;
        deg[v]++;
    }
    dijkstra(0);
    cout << d[arr[x][y]-1] - d[arr[a][b]-1] << "\n";

    // cin >> n >> m;
    // for(int u=0;u<n;u++) deg[u] = 0;
    // for(int i=0;i<m;i++){
    //     int a,b,w;
    //     cin >> a >> b >> w;  a--; b--;
    //     adj[a].push_back(b);
    //     adj[b].push_back(a);
    //     weights[a].push_back(w);
    //     weights[b].push_back(w);
    //     deg[a]++;
    //     deg[b]++;
    // }
    // dijkstra(0);
    // cout << d[n-1] << endl;
}