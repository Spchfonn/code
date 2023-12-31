#include<bits/stdc++.h>
#include<list>
#include<string>
using namespace std;
list<char> ans, cut;
int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    while(1){
        string w;
        cin >> w;
        if(w == "") break;
        int size = w.size(), ch = 0;
        for(int i=0;i<size;i++){
            if(w[i] == '[' && ch == 0){
                ch = 1;
            }
            else if(w[i] == '[' && ch == 1){
                ans.splice(ans.begin(),cut);
                cut.clear();
            }
            else if(w[i] == ']'){
                ans.splice(ans.begin(),cut);
                cut.clear();
                ch = 0;
            }
            else if(ch == 1){
                cut.push_back(w[i]);
            }
            else{
                ans.push_back(w[i]);
            }
            if(i==size-1 && !cut.empty()){
                ans.splice(ans.begin(),cut);
                cut.clear();
            }
        }
        for(auto i=ans.begin();i!=ans.end();i++){
            cout << *i;
        }
        cout << "\n";
        ans.clear();
    }
    return 0;
}