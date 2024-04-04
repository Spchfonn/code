//score: 20 [ ---PP----- ]
#include<bits/stdc++.h>
using namespace std;
int l[410][410];
list<char> sub;
int main(){
    string s, t;
    cin >> s >> t;
    if(s.length()<t.length()) swap(s,t);
    int len_s = s.length(), len_t = t.length();
    for(int i=0;i<len_s;i++){
        for(int j=0;j<len_t;j++){
            int ans = 0;
            if(s[i]==t[j]) ans = l[i][j] + 1;
            l[i+1][j+1] = max(ans, l[i][j+1]);
            l[i+1][j+1] = max(l[i+1][j+1], l[i+1][j]);
        }
    }
    //cout << l[len_s][len_t] << "\n";
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
    int cnt = 0;
    int k = 0, m = 0;
    while(!sub.empty()){
        if(s[k]==sub.front() && t[m]==sub.front()){
            k++;
            m++;
            sub.pop_front();
        }
        else{
            if(s[k]==sub.front()){
                cnt++;
                m++;
            }
            else if(t[m]==sub.front()){
                cnt++;
                k++;
            }
            else{
                cnt++;
                k++;
                m++;
            }
        }
    }
    cout << cnt+(len_s-k)+(len_t-m) << "\n";

    return 0;
}