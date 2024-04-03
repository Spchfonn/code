#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100010];
stack<int> q;
int mark[100010];
int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int n, m;
	while(1){
		int ch = 0;
		cin >> n >> m;
		if(n==0 && m==0) break;
		while(m--){
			int u, v;
        	cin >> u >> v;
        	arr[u].push_back(v);
        	mark[v]++;
    	}
    	for(int i=1;i<=n;i++){
        	if(mark[i]==0) q.push(i);
    	}
        while(!q.empty()){
            int current = q.top();
			q.pop();
            for(auto x:arr[current]){
                mark[x]--;
                if(mark[x]==0) q.push(x);
            }
			if(ch) cout << " ";
            cout << current;
			ch++;
        }
		cout << "\n";
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			if(mark[i]!=0) mark[i] = 0;
		}
		for(int i=0;i<n;i++) arr[i].clear();
	}
	return 0;
}