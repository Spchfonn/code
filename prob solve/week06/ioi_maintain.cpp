#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, week;
pair<pair<int,int>,int> edge[6010];
set<int> s;
int parents[210], ranks[210];

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
    cin >> n >> week;
    for(int i=0;i<week;i++){
        int total_weight = 0;
        for(int j=0;j<n;j++){
            parents[j] = j;
            ranks[j] = 1;
        }
        int a,b,w;
        cin >> a >> b >> w;
        a--; b--;
        edge[i] = {{a,b},w};
        for(int j=i;j>=0;j--){
            if(edge[j].second < edge[j-1].second) swap(edge[j],edge[j-1]);
            else break;
        }
        for(int j=0;j<i;j++){
            if(find(edge[j].first.first) != find(edge[j].first.second)){
                total_weight += edge[j].second;
                union_sets(edge[j].first.first, edge[j].first.second);
                s.insert(edge[j].first.first);
                s.insert(edge[j].first.second);
            }
        }
        int size = s.size();
        s.clear();
        if(size!=n) cout << "-1\n";
        else cout << total_weight << "\n";
    }
    return 0;
}

/*
4 6
1 2 10
1 3 8
3 2 3
1 4 3
1 3 6
2 1 2
*/