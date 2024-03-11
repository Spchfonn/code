#include<bits/stdc++.h>
using namespace std;
list<int> ans[300100];
int root[300100];
int main(){
    int num, n, x, y;
    cin >> num;
    n = num;
    for(int i=1;i<=n;i++){
        ans[i].push_back(i);
        root[i] = i;
    }
    n--;
    while(n--){
        cin >> x >> y;
        if(!(ans[y].empty())){
            auto it = ans[y].begin(); 
            advance(it,1);
            for(auto i:ans[x]){
                ans[y].insert(it, i);
                root[i] = root[y];
            }
            ans[x].clear();
        }
        else{
            int i = root[y];
            auto pos = find(ans[i].begin(), ans[i].end(), y);
            advance(pos,1);
            for(auto j:ans[x]){
                ans[i].insert(pos, j);
                root[j] = root[y];
            }
            ans[x].clear();
        }
    }
    for(int k=1;k<=num;k++){
        for(auto i:ans[k]) cout << i << " ";
    }
    
    return 0;
}

