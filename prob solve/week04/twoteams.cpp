// score: 57 [ -P-P-PP ]
#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100010], q;
int mark[100010], check[100010];
void findqueue(int x){
    if(find(q.begin(), q.end(), x)!=q.end()) q.push_back(x);
    check[x] = 1;
    for(auto i:arr[x]){
        if(find(q.begin(), q.end(), i)!=q.end()){
            q.push_back(i);
            if(check[i]==0) findqueue(i);
        }
    }
}
int main(){
    int n, m, a, b, cnt = 0;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        if(mark[a]==0 && mark[b]==0){
            mark[a] = 1;
            mark[b] = -1;
        }
        else if(mark[a]==0) mark[a] = -mark[b];
        else if(mark[b]==0) mark[b] = -mark[a];
        else{
            if(mark[a]==mark[b]){
                while(!q.empty()) q.pop_back();
                memset(check, 0, sizeof(check));
                findqueue(b);
                for(auto i:q){
                    mark[i] = -mark[i];
                }
                if(mark[a]==mark[b]){
                    break;
                }
            }
        }
        cnt++;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    cout << cnt << "\n";

    return 0;
}