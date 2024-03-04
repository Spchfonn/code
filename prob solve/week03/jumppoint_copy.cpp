#include <bits/stdc++.h>
using namespace std;
struct jud{
    int x,y;
};
int pointDis(jud a, jud b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
vector<jud> point;
queue<jud> q;
int main(){
    int n,r,a,b,cnt=0,chk=1;
    cin >> n >> r;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        point.push_back({a,b});
    }
    q.push({0,0});

    while(!q.empty()){
        if(!chk) break;
        int sz = q.size();
        while(sz--){
            jud cur = q.front();
            q.pop();
            if(pointDis(cur,{100,100})<=r*r){
                chk = 0;
                break;
            }
            for(auto& x: point){
                if(pointDis(cur,x)<=r*r && x.x!=-1 && x.y!=-1){
                    q.push(x);
                    x.x = -1;
                    x.y = -1;
                }
            }
        }
        cnt++;
    }

    cout << cnt << "\n";
    
    return 0;
}