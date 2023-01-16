
/*
    Chuyển từ danh sách cạnh sang danh sách kề

    input:  
        5 9 
        
        1 2
        1 3
        1 4
        2 3
        2 4
        2 5
        3 4
        3 5
        4 5


*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr[1001]; // arr[i] dùng để lưu danh sách kề của đỉnh i

int main() {
    cin >> n >> m;

    for(int i = 0; i < m ; i++) {
        int x, y; cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    } 

    for(int i = 1; i <= n; i++) {
        cout << i << " : ";
        for(int x : arr[i]) {
            cout << x << "  ";
        }
        cout << endl;
    }


    return 0;
}

