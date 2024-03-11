#include<bits/stdc++.h>
using namespace std;
char arr[33][33];
int mark[33][33];
int n, m;
pair<int,int> di[] = {{0,1},{0,-1},{1,0},{-1,0}};

bool is_valid(int i, int j){
    return (i>=0 && i<n-1 && j>=0 && j<m-1);
}

void move_box(int i, int j){
    mark[i][j] = 1;
    if(i == n-2){
        cout << "yes\n";
        exit(0);
    }
    for(int k=0;k<4;k++){
        int nowi = di[k].first + i, nowj = di[k].second + j;
        if(!is_valid(nowi, nowj) || mark[nowi][nowj]) continue;
        if(arr[nowi][nowj]=='.' && arr[nowi][nowj+1]=='.' && arr[nowi+1][nowj]=='.' && arr[nowi+1][nowj+1]=='.'){
            move_box(nowi, nowj);
        }
    }
    mark[i][j] = 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for(int j=0;j<m;j++){
        if(arr[0][j]=='.' && arr[1][j]=='.' && arr[0][j+1]=='.' && arr[1][j+1]=='.') move_box(0,j);
    }
    cout << "no\n";

    return 0;
}