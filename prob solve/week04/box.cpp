#include<bits/stdc++.h>
using namespace std;
char arr[33][33], new_arr[33][33];

bool move_box(int i, int j, int ed){
    // if(new_arr[i+1][j] == '.') move_box(i+1,j,ed);
    // if(new_arr[i][j+1] == '.') move_box(i,j+1,ed);
    // if(new_arr[i][j-1] == '.') move_box(i,j-1,ed);
    if(i==ed-1) return true;
    if(new_arr[i+1][j] == '#' && new_arr[i][j+1] == '#' && new_arr[i][j-1] == '#') return false;
    return move_box(i+1,j,ed) || move_box(i,j+1,ed) || move_box(i,j-1,ed);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    bool chk = false;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    cout << "xxx\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j+1] == arr[i][j]) new_arr[i][j] = arr[i][j];
            else new_arr[i][j] = '#';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << new_arr[i][j];
        }
        cout << "\n";
    }

    for(int j=0;j<m;j++){
        if(new_arr[0][j] == '.') chk = move_box(0,j,n);
    }

    if(chk) cout << "yes\n";
    else cout << "no\n";

    return 0;
}

/*
7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.

7 14
..............
..............
..............
..............
..............
..............
..............

7 14
##############
##############
##############
##############
##############
##############
##############
*/