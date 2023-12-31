#include<iostream>
using namespace std;
int data[60], y[60];
int main(){
    int n, t;
    cin >> n >> t;
    data[0] = n;
    for(int i=1;i<=n;i++) cin >> data[i];
    if(t==1){
        for(int i=1;i<=n;i++){
            if(data[i]==data[i-1]-1) cout << 0 << "\n";
            else if(data[i]-1==data[i-1]) cout << 1 << "\n";
        }
    }
    else if(t==2){
        y[0] = n;
        y[1] = data[1];
        for(int i=2;i<=n;i++){
            if(y[i-1]*2<data[i]) y[i] = y[i-1]+1;
            else y[i] = y[i-1]-1;
        }
        for(int i=1;i<=n;i++){
            if(y[i]==y[i-1]-1) cout << 0 << "\n";
            else if(y[i]-1==y[i-1]) cout << 1 << "\n";
        }
    }
    return 0;
}