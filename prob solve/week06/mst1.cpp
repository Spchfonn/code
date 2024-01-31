#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> u,v;
vector<int> weights;
vector<pair<int,int>> ew;

int parents[200010];
int ranks[200010];
void init_union_find(){
    for(int i=0; i<n; i++){
        parents[i] = i;
        ranks[i] = 1;
    }
}

int find(int x){ 
    if(parents[x]==x) return x;
    else return find(parents[x]);
}

void union_sets(int x, int y){
    if(parents[x] == parents[y]) return;
    int py = find(y);
    int px = find(x);
    if(ranks[px] > ranks[py]) parents[py] = px;
    else if(ranks[py] > ranks[px]) parents[px] = py;
    else{
        parents[py] = px;
        ranks[px]++;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--; b--;
        u.push_back(a);
        v.push_back(b);
        weights.push_back(w);
        ew.push_back(make_pair(w,i));
    }
    sort(ew.begin(), ew.end());
    init_union_find();
    int total_weight = 0;
    for(int i=0; i<m; i++){
        int e = ew[i].second;   // end points are u[e] and v[e]
        if(find(u[e]) != find(v[e])){
            // add e to our solution
            total_weight += weights[e];
            union_sets(u[e], v[e]);
        }
    }
    cout << total_weight << "\n";
    return 0;
}
