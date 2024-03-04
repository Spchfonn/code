#include<bits/stdc++.h>
#include<list>
#include<algorithm>
using namespace std;
list<int> ans[300100];
list<int> :: iterator pos;
int main(){
    int n, x, y;
    cin >> n;
    for(int i=1;i<=n;i++){
        ans[i].push_back(i);
    }
    n--;
    while(n--){
        cin >> x >> y;
        if(!(ans[y].empty())){
            list<int>::iterator it = ans[y].begin(); 
            advance(it,1);
            ans[y].insert(it, ans[x].begin(), ans[x].end());
            ans[x].clear();
        }
        else{
            for(int i=1;i<=n;i++){
                if(ans[i].size()==0 || i==x) continue;
                else{
                    pos = find(ans[i].begin(), ans[i].end(), y);
                    if(!(pos != ans[i].end())) continue;
                    else{
                        advance(pos,1);
                        ans[i].insert(pos, ans[x].begin(), ans[x].end());
                        ans[x].clear();
                        break;
                    }
                }
            }
        }
        for(int k=0;k<300100;k++){
            if(ans[k].size()==0) continue;
            for(auto i=ans[k].begin();i!=ans[k].end();i++){
                cout << *i << " ";
            }
        }
        cout << "\n";
    }

    for(int k=0;k<300100;k++){
        if(ans[k].size()==0) continue;
        for(auto i=ans[k].begin();i!=ans[k].end();i++){
            cout << *i << " ";
        }
    }
    
    return 0;
}