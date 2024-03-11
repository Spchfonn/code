// #include<bits/stdc++.h>
// using namespace std;
// struct Pair{
//     int start, end;
//     bool operator<(const Pair & other) const{
//         return start < other.start;
//     }
// };

// Pair allPairs[100005];
// Pair solution[100005];

// int main(){
//     freopen("input.in","r",stdin);
//     freopen("output.out","w",stdout);
//     int t, m;
//     cin >> t;
//     while(t--){
//         cin >> m;
//         int numPairs = 0;
//         while (cin >> allPairs[numPairs].start >> allPairs[numPairs].end,
//             allPairs[numPairs].start || allPairs[numPairs].end)
//         {
//             if(allPairs[numPairs].end > 0 && allPairs[numPairs].start < m)
//                 ++numPairs;
//         }        
//         sort(allPairs, allPairs + numPairs);  
//         allPairs[numPairs].start = m + 1;
//         int cnt = 0, currentX = 0, currentPair = 0;
        
//         while(currentX < m && currentPair < numPairs){
//             solution[cnt].end = 0;
//             for(;allPairs[currentPair].start <= currentX;++currentPair)
//                 if (allPairs[currentPair].end > solution[cnt].end)
//                     solution[cnt] = allPairs[currentPair];
            
//             if (solution[cnt].end == currentX) break;
//             currentX = solution[cnt].end;
//             ++cnt;
//         }
        
//         if(currentX >= m){
//             cout << cnt << endl;
//             for (int i=0;i<cnt;++i){
//                 cout << solution[i].start << " " << solution[i].end << endl;
//             }
//         }
//         else cout << "0" << endl;
//         if(t!=0) cout << "\n";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
struct Pair{
    int start, end;
    bool operator<(const Pair & other) const{
        return start < other.start;
    }
};

Pair allPairs[100005];
Pair solution[100005];

int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t, m;
    cin >> t;
    while(t--){
        cin >> m;
        int numPairs = 0;
        while (cin >> allPairs[numPairs].start >> allPairs[numPairs].end,
            allPairs[numPairs].start || allPairs[numPairs].end)
        {
            if(allPairs[numPairs].end > 0 && allPairs[numPairs].start < m)
                ++numPairs;
        }        
        sort(allPairs, allPairs + numPairs);  
        allPairs[numPairs].start = m + 1;
        int cnt = 0, currentX = 0, currentPair = 0;
        
        while(currentX < m && currentPair < numPairs){
            solution[cnt].end = 0;
            for(;allPairs[currentPair].start <= currentX;++currentPair)
                if (allPairs[currentPair].end > solution[cnt].end)
                    solution[cnt] = allPairs[currentPair];
            
            if (solution[cnt].end == currentX) break;
            currentX = solution[cnt].end;
            ++cnt;
        }
        
        if(currentX >= m){
            cout << cnt << endl;
            for (int i=0;i<cnt;++i){
                cout << solution[i].start << " " << solution[i].end << endl;
            }
        }
        else cout << "0" << endl;
        if(t!=0) cout << "\n";
    }
    return 0;
}