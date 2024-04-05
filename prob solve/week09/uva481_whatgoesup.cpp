#include <bits/stdc++.h>
using namespace std;
vector<int> seq;

void print(const vector<int> &seq,
           const vector<int> &path,
           int                pos)
{
    if(pos == -1) return;
    print(seq, path, path[pos]);
    cout << seq[pos] << "\n";
}

int main(){  
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    int n;
    while(cin >> n) seq.push_back(n);
    vector<int> L(seq.size()), L_id(seq.size()), path(seq.size());
    int lisEnd = 0, lisCount = 0, size = seq.size();
    for(int i=0;i<size;i++){
        size_t pos = lower_bound(L.begin(), L.begin() + lisCount, seq[i]) - L.begin();
        L[pos] = seq[i];
        L_id[pos] = i;
        path[i] = pos? L_id[pos - 1] : -1;
        if(pos == lisCount){
            ++lisCount;
            lisEnd = i;
        }
    }
    cout << lisCount << "\n-\n";
    print(seq, path, lisEnd);

    return 0;
}