#include<bits/stdc++.h>
using namespace std;
char a[510][510];
struct state{
    int i, j, ch, cnt;
};
vector<state> q;
int di[] = {-1,0,0,1}, dj[] = {0,-1,1,0}, di_m[] = {-2,-2,-1,-1,1,1,2,2}, dj_m[] = {-1,1,-2,2,-2,2,-1,1};
int check[510][510];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    q.push_back({1,1,1,0});
    while(q.back().i!=n && q.back().j!=n){
        auto current = q.back();
        if(current.i==n && current.j==n){
            break;
        }
        for(int k=0;k<4;k++){
            int nowi = current.i + di[k], nowj = current.j + dj[k];
            if(nowi < 1 || nowi > n || nowj < 1 || nowj > n || a[nowi][nowj] == '#') continue;
            if(check[nowi][nowj] == 1) continue;
            else if(a[nowi][nowj] == '.' && check[nowi][nowj] == 0){
                check[nowi][nowj] = 1;
                q.push_back({nowi,nowj,current.ch,current.cnt+1});
                break;
            }
        }
    }
    cout << q.back().cnt << "\n";
    
    return 0;
}

/*
7
.#...#.
...#...
#######
###.#.#
....#.#
.####.#
.......
*/