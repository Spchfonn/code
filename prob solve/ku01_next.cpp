#include<iostream>
using namespace std;
int data[100100], status[100100];
int main(){
    int n, cnt=1, mx=-1e9;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data[i];
    }
    for(int i=0;i<n;i++){
        if(status[i]==0){
            int check = i+1;
            int current = data[i];
            while(check!=current){
                status[current-1] = 1;
                cnt++;
                current = data[current-1];
            }
            mx = max(mx,cnt);
            cnt = 1;
        }
    }
    cout << mx << "\n";
    return 0;
}