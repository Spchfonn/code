#include<bits/stdc++.h>
#include<list>
using namespace std;
int arr[60];
int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    int n;
    while(1){
        int cnt = 2, check = 1, remain;
        cin >> n;
        if(n==0) break;
        int i = 1;
        cout << "Discarded cards:";
        while(1){
            if(cnt==2){
                arr[i] = 1;
                if(check==n){
                    cout << "\n";
                    remain = i;
                    break;
                }
                if(check==1) cout << " ";
                cout << i;
                if(check<n-1) cout << ", ";
                arr[i] = 1;
                cnt = 0;
                check++;
            }
            if(i==n) i=0;
            i++;
            if(arr[i]!=1) cnt++;
        }
        cout << "Remaining card: " << remain << "\n";
        for(int i=1;i<=n;i++) arr[i]=0;
    }    
    
    return 0;
}