#include<bits/stdc++.h>
using namespace std;
char arr[30][30];
int mark[30][30];
pair<int,int> tid[] = {{-1,0},{0,1},{1,0},{0,-1}};
queue<pair<pair<int,int>,int>> bfs;
int main(){
    int n, q, r, c, a, b, cnt = 1;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    while(q--){
        while(!bfs.empty()) bfs.pop();
        int ans = 0;
        cin >> r >> c >> a >> b;
        bfs.push({{r,c},1});
        while(!bfs.empty()){
            auto now = bfs.front();
            bfs.pop();
            if(mark[now.first.first][now.first.second]==cnt) continue;
            else mark[now.first.first][now.first.second] = cnt;
            if(now.first.first==a && now.first.second==b){
                ans = 1;
                break;
            }
            for(int i=0;i<4;i++){
                int ni = now.first.first+tid[i].first, nj = now.first.second+tid[i].second;
                if(ni<1 || nj<1 || ni>n || nj>n || arr[ni][nj]=='#') continue;
                if(arr[ni][nj]=='.'){
                    bfs.push({{ni,nj},now.second});
                }
                if(arr[ni][nj]=='O' && now.second==1){
                    bfs.push({{ni,nj},0});
                }
            }
        }
        cnt++;
        if(ans==1) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}