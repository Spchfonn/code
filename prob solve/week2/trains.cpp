#include<bits/stdc++.h>
#include<list>
using namespace std;
list<int> mylist[100100];
int main(){
    int m, x, i, j;
    char menu;
    cin >> m;
    while(m--){
        cin >> menu;
        if(menu=='N'){
            cin >> x >> i;
            mylist[i].push_back(x);
        }
        else if(menu=='M'){
            cin >> i >> j;
            mylist[j].splice(mylist[j].end(), mylist[i]);
        }
    }
    for(int k=0;k<100100;k++){
        if(mylist[k].size()==0) continue;
        for(auto i=mylist[k].begin();i!=mylist[k].end();i++){
            cout << *i << "\n";
        }
    }
    
    return 0;
}