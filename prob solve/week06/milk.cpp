#include<bits/stdc++.h>
using namespace std;
int group[100010];
vector<int> arr[100010];

int find_group(int x){
    return (group[x] == x) ? x : (group[x] = find_group(group[x]));
}

int main(){
    int n, q, x, y;
    char menu;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        group[i] = i;
        arr[i].push_back(i);
    }
    while(q--){
        cin >> menu >> x >> y;
        if(menu=='q'){
            if(find_group(x)==find_group(y)) cout << "yes\n";
            else cout << "no\n";
        }
        else if(menu=='c'){
            int gx = find_group(x), gy = find_group(y);
            if(gx!=gy){
                if(arr[gx].size()<arr[gy].size()){
                    swap(gx, gy);
                }
                for(int i:arr[gy]){
                    group[i] = gx;
                    arr[gx].push_back(i);
                }
                arr[gy].clear();
            }

        }
    }
    
    return 0;
}