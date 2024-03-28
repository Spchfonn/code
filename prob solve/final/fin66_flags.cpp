#include<bits/stdc++.h>
using namespace std;
long long more[10010], les[10010];
pair<long long, long long> arr[10010];
int main(){
    long long n, x, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        arr[i] = make_pair(x, i);
    }
    for(int i=0;i<n;i++){
        long long cntmak = 0, cntnoi = 0;
        for(int j=i+1;j<n;j++){
            if((arr[j].first<arr[i].first) && j!=n-1) cntnoi++;
            else if(arr[j].first>arr[i].first) cntmak++;
        }
        more[arr[i].second] = cntmak;
        les[arr[i].second] = cntnoi;
    }
    sort(arr, arr+n);
    // for(int i=0;i<n;i++){
    //     cout << arr[i].first << " " << arr[i].second << "\n";
    //     cout << "xx" << more[i] << " " << les[i] << "\n";
    // }
    for(int i=0;i<n;i++){
        if(les[arr[i].second]!=0){
            for(int j=i-1;j>=0;j--){
                if(arr[j].second>arr[i].second) ans += more[arr[j].second];
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}

/*
6
10
7
12
5
8
9
*/