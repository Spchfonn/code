#include<bits/stdc++.h>
using namespace std;
int dp1[50][50], dp2[50][50], dp3[50][50], dp4[50][50], arr[50][50];
int main(){
    int m, n;
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp1[i][j] = arr[i][j] + dp1[i][j-1];
            dp2[i][n-j+1] = arr[i][n-j+1] + dp2[i][n-j+2];
            dp3[i][j] = arr[i][j] + dp3[i-1][j];
            dp4[m-i+1][j] = arr[m-i+1][j] + dp4[m-i+2][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int ans = min(dp1[i][j],dp2[i][j]);
            ans = min(ans, dp3[i][j]);
            ans = min(ans, dp4[i][j]);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
4 5
1 15 8 9 12
20 3 2 1 2
4 5 1 2 6
10 4 15 2 3
*/