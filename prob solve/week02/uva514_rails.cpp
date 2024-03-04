#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack<int> st;
int arr[1010];
int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int n, state = 1;
    while(1){
        cin >> n;
        if(n==0) break;
        while(1){
            state = 1;
            cin >> arr[0];
            if(arr[0]==0) break;
            for(int i=0;i<n;i++){
                if(i!=0) cin >> arr[i];
                while(state<=arr[i]){
                    st.push(state);
                    state++;
                }
                if(arr[i]==st.top()) st.pop();
            }
            if(st.empty()) cout << "Yes\n";
            else{
                cout << "No\n";
                while(!st.empty()) st.pop();
            }
        }
        cout << "\n";
    }
    
    return 0;
}