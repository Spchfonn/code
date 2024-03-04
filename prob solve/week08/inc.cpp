#include<bits/stdc++.h>
using namespace std;
int arr[1010], l[1010], indexx[1010], outputt[1010];

int main(){
    int n, mx = -2e9, index_mx;
    l[0] = 0, arr[0] = -2e9;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                if(l[j]+1 > l[i]){
                    indexx[i] = j;
                    l[i] = l[j] + 1;
                    if(l[i] > mx){
                        mx = l[i];
                        index_mx = i;
                    }
                }
            }
        }
    }
    cout << mx << "\n";
    int i = index_mx, nn = mx;
    while(i!=0){
        outputt[nn--] = arr[i];
        i = indexx[i];
    }
    for(int i=1;i<=mx;i++){
        cout << outputt[i];
        if(i!=mx) cout << " ";
    }
    
    return 0;
}

/*
10
3 1 4 1 5 9 2 6 8 5
*/