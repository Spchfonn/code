#include<bits/stdc++.h>
using namespace std;
int l[210][210];
int main(){
    string s, t;
    cin >> s >> t;
    int len_s = s.length(), len_t = t.length();
    for(int i=0;i<len_s;i++){
        for(int j=0;j<len_t;j++){
            int ans = 0;
            if(s[i]==t[j]) ans = l[i][j] + 1;
            l[i+1][j+1] = max(ans, l[i][j+1]);
            l[i+1][j+1] = max(l[i+1][j+1], l[i+1][j]);
        }
    }
    cout << l[len_s][len_t] << "\n";

    return 0;
}