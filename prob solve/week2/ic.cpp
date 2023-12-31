#include<bits/stdc++.h>
#include<list>
#include<string>
using namespace std;
int main(){
    int m, x;
    string menu;
    list<int> mylist;
    cin >> m;
    while(m--){
        cin >> menu;
        if(menu=="li"){
            cin >> x;
            mylist.push_front(x);
        }
        else if(menu=="ri"){
            cin >> x;
            mylist.push_back(x);
        }
        else if(menu=="lr"){
            mylist.push_back(mylist.front());
            mylist.pop_front();
        }
        else if(menu=="rr"){
            mylist.push_front(mylist.back());
            mylist.pop_back();
        }
    }
    for(auto i=mylist.begin();i!=mylist.end();i++){
        cout << *i << "\n";
    }
    
    return 0;
}
