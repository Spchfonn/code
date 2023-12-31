#include<iostream>
using namespace std;
int data[50];
int main(){
    int n, cnt=0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> data[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(data[i]>data[j]) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}