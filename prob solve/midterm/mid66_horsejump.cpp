#include<bits/stdc++.h>
using namespace std;
char a[510][510];
struct state{
    int i, j, ch, cnt;
};
vector<state> q;
int di[] = {-1,0,0,1}, dj[] = {0,-1,1,0}, di_m[] = {-2,-2,-1,-1,1,1,2,2}, dj_m[] = {-1,1,-2,2,-2,2,-1,1};
int check[510][510] ,mark[510][510];
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
        cout << "... " << current.i << " " << current.j << " " << current.ch << " " << current.cnt << "\n";
        if(current.i==n && current.j==n){
            break;
        }
        if(check[current.i][current.j] == 0){
            check[current.i][current.j] = 1;
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
            for(int k=0;k<8;k++){
                int nowi = current.i + di_m[k], nowj = current.j + dj_m[k];
                if(nowi < 1 || nowi > n || nowj < 1 || nowj > n || a[nowi][nowj] == '#') continue;
                if(check[nowi][nowj] == 1) continue;
                else if(a[nowi][nowj] == '.' && check[nowi][nowj] == 0){
                    mark[nowi][nowj] = 1;
                    break;
                }
            }
        }
        else{
            for(int k=0;k<8;k++){
                int nowi = current.i + di_m[k], nowj = current.j + dj_m[k];
                if(nowi < 1 || nowi > n || nowj < 1 || nowj > n || a[nowi][nowj] == '#') continue;
                if(check[nowi][nowj] == 1) continue;
                else if(a[nowi][nowj] == '.' && check[nowi][nowj] == 0){
                    mark[nowi][nowj] = 1;
                    check[nowi][nowj] = 1;
                    q.push_back({nowi,nowj,current.ch-1,current.cnt+1});
                    break;
                }
            }
        }
        if(q.back().i==current.i && q.back().j==current.j){
            while(1){
                q.pop_back();
                if(mark[q.back().i][q.back().j]==1) break;
            }
        }
    }
    cout << q.back().cnt << "\n";
    
    return 0;
}