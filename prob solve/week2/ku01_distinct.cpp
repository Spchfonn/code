#include<bits/stdc++.h>
#include<set>
#include<algorithm>
using namespace std;
set<int> ans;
int arr[110];
int main(){
    int n, cnt = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cnt = arr[i];
        for(int j=i;j<n;j++){
            if(i!=j) cnt += arr[j];
            if(!(ans.find(cnt) != ans.end())){
                ans.insert(cnt);
            }
        }
    }
    cout << ans.size() << "\n";

    return 0;
}