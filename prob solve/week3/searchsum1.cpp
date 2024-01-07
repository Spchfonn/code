#include<bits/stdc++.h>
using namespace std;
long long arr[100010];
int main() {
    long long n, k, sum = 0, price, money;
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> price;
        sum += price;
        arr[i] = sum;
    }
    while (k--) {
        cin >> money;
        if (money>=arr[n-1]) {
            cout << n << "\n";
        } else {
            int index = upper_bound(arr, arr+n, money) - arr;
            cout << index << "\n";
        }
    }

    return 0;
}
