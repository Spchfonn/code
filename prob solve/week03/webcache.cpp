#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int mark[1000010];
int main(){
    int n, m, x, cnt = 0;
    cin >> n >> m;
    while(m--){
        cin >> x;
        if(mark[x]==0){
            int size = q.size();
            if(size==n){
                int front = q.front();
                mark[front] = 0;
                q.pop();
            }
            cnt++;
            q.push(x);
            mark[x] = 1;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}