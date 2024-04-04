#include<bits/stdc++.h>
#include<string>
using namespace std;
string s, t;
int main(){
    cin >> s >> t;
    int len_s = s.length(), len_t = t.length();
    int j = 0, cnt = 0;
    for(int i=0;i<len_t;i++){
        if(t[i]==s[j]){
            j++;
            if(j==len_s){
                j = 0;
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    
    return 0;
}