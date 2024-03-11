#include<bits/stdc++.h>
using namespace std;
int l[210][210];
list<char> sub;
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
    int i = len_s, j = len_t;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            sub.push_front(s[i-1]);
            i--;
            j--;
        }
        else if(l[i][j-1] > l[i-1][j]) j--;
        else i--;
    }
    while(!sub.empty()){
        cout << sub.front();
        sub.pop_front();
    }

    return 0;
}