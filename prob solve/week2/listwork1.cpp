#include<bits/stdc++.h>
#include<list>
using namespace std;
int main(){
    int m, x;
    char menu;
    list<int> mylist;
    cin >> m;
    while(m--){
        cin >> menu >> x;
        if(menu=='I'){
            mylist.push_front(x);
        }
        else if(menu=='D'){
            list<int>::iterator ii=mylist.begin();
            for(int i=0;i<x-1;i++){
                if(ii==mylist.end()) continue;
                ii++;
            }
            if(ii!=mylist.end()) mylist.erase(ii);
        }
    }
    for(auto i=mylist.begin();i!=mylist.end();i++){
        cout << *i << "\n";
    }
    
    return 0;
}