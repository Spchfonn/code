#include<bits/stdc++.h>
using namespace std;
long long x[500100], y[500100], z[500100], sum[3][500100];

long long find_max(long long xx, long long yy, long long zz){
    if(xx>yy && xx>zz) return xx;
    if(yy>xx && yy>zz) return yy;
    if(zz>xx && zz>yy) return zz;
    return 0;
}

int main(){
    long long n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    sum[0][1] = x[1], sum[1][1] = y[1], sum[2][1] = z[2];
    for(int i=2;i<=n;i++){
        sum[0][i] = find_max(sum[0][i-1], sum[1][i-2], sum[2][i-4]) + x[i];
        sum[1][i] = find_max(sum[0][i-1], sum[1][i-2], sum[2][i-4]) + y[i];
        sum[2][i] = find_max(sum[0][i-1], sum[1][i-2], sum[2][i-4]) + z[i];
    }
    cout << find_max(sum[0][n], sum[1][n], sum[2][n]);
    
    return 0;
}