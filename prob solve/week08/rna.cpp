#include<bits/stdc++.h>
using namespace std;
int dp[210][210];
int main(){
    string rna;
    cin >> rna;
    int size = rna.size();
    for(int j=1;j<=size;j++){
        for(int i=j;i>0;i--){
            if(j>=i-4){
                dp[i][j] = dp[i][j-1];
                for(int k=i;k<=j;k++){
                    if((k < j-4) && ((rna[k-1] == 'A' && rna[j-1] == 'U') || (rna[k-1] == 'U' && rna[j-1] == 'A') || (rna[k-1] == 'G' && rna[j-1] == 'C') || (rna[k-1] == 'C' && rna[j-1] == 'G'))){
                        dp[i][j] = max(dp[i][j],dp[i][k-1]+dp[k+1][j-1]+1);
                    }
                }
            }
        }
    }
    cout << dp[1][size] << "\n";
    return 0;
}