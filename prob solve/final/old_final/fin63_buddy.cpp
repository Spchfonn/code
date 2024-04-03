#include<bits/stdc++.h>
using namespace std;
int group[100010], data[100010];
vector<int> arr[100010];
set<int> s;

int find_group(int x){
    return (group[x] == x) ? x : (group[x] = find_group(group[x]));
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> data[i];
        group[i] = i;
        arr[i].push_back(i);
    }
    for(int i=1;i<=n;i++){
        int x = i, y = data[i];
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
    for(int i=1;i<=n;i++) s.insert(group[i]);
    cout << s.size() << "\n";
    
    return 0;
}