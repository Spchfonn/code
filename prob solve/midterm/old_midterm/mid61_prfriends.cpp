#include<bits/stdc++.h>
using namespace std;

vector<int> segmentedSieve(int left, int right) {
    const int limit = right - left + 1;
    vector<bool> prime(limit, true);
    int sqrt_right = sqrt(right);
    vector<bool> base_primes(sqrt_right+1, true);
    for(int p=2;p*p<=sqrt_right;p++){
        if(base_primes[p]){
            for (int i=p*p;i<=sqrt_right;i+=p) base_primes[i] = false;
        }
    }
    for(int p=2;p<=sqrt_right;p++){
        if(base_primes[p]){
            int start = max(p*p, (left+p-1)/p*p);
            for(int i=start;i<=right;i+=p) prime[i-left] = false;
        }
    }
    vector<int> primes;
    for(int i=0;i<limit;i++){
        if (prime[i] && (i+left)>1) primes.push_back(i+left);
    }

    return primes;
}

int main(){
    int l, r, cnt = 0;
    cin >> l >> r;
    vector<int> primes = segmentedSieve(l, r);
    int len = primes.size();
    for(int i=1;i<len;i++){
        if(primes[i]-primes[i-1]==2) cnt++;
    }
    cout << cnt;
    
    return 0;
}
