#include<bits/stdc++.h>
using namespace std;
int arr[2000010], res[2000010];

void merge(int l, int mid, int r){
    int i = l, j = mid+1, k = i;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            res[k] = arr[i];
            i++;
        }
        else{
            res[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        res[k] = arr[i];
        k++; i++;
    }
    while(j <= r){
        res[k] = arr[j];
        k++; j++;
    }
    for(int i=l;i<=r;i++){
        arr[i] = res[i];
        res[i] = 0;
    }
}

void merge_sort(int l, int r){
    int mid = (r+l)/2;
    if(l==r) return;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    merge(l, mid, r);
}

int main(){
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++) cin >> arr[i];
        merge_sort(0,n-1);
        for(int i=0;i<n;i++){
            cout << arr[i];
            if(i!=n-1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}