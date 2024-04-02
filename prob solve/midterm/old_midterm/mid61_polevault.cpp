#include<bits/stdc++.h>
using namespace std;
int arr[1010], qt[100010];
set<int> s;
int main(){
    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<q;i++) cin >> qt[i];
    for(int i=0;i<n;i++){
        int x = arr[i];
        s.insert(x);
        for(int j=i+1;j<n;j++){
            x += arr[j];
            s.insert(x);
        }
    }
    for(int i=0;i<q;i++){
        if(s.find(qt[i])!=s.end()) cout << "Y";
        else cout << "N";
    }
    
    return 0;
}

/*
5 4
2 2 1 2 2
2 4 6 2
*/