#include<bits/stdc++.h>
#include<string>
using namespace std;
int a[1010], arr[110][4];
pair<int, int> nub[110];
int main(){
    int k, n, mn = INT_MAX;
    cin >> k >> n;
    for(int i=0;i<k;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;j<k;j++){
            if(a[i] > arr[j][2]){
                nub[j].second = 9999;
            }
            else{
                nub[j].first += a[i];
                if(nub[j].first > arr[j][2]){
                    nub[j].first = a[i];
                    nub[j].second++;
                }
                if(i==n-1){
                    nub[j].second++;
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        mn = min(mn, arr[i][0] + nub[i].second*arr[i][1]);
    }
    cout << mn << "\n";
    
    return 0;
}