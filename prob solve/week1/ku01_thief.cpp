#include<iostream>
using namespace std;
int data[50];
int main(){
    int n, k, t, cnt=0, state=0;
    cin >> n >> k >> t;
    while(1){
        state += k;
        if(state>=n) state -= n;
        cnt++;
        if(state==0) break;
        else if(state==t-1){
            cnt++;
            break;
        }
    }
    cout << cnt << "\n";
    return 0;
}