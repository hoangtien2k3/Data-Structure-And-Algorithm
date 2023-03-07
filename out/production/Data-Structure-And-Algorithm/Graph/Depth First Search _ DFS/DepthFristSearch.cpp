
//! Depth First Search: giải thuật tìm kiếm theo chiều sâu

/*
    + Giải thuật tìm kiếm theo chiều sâu (Depth First Search – viết tắt là DFS), 
    còn được gọi là giải thuật tìm kiếm ưu tiên chiều sâu, là giải thuật duyệt 
    hoặc tìm kiếm trên một cây hoặc một đồ thị và sử dụng stack (ngăn xếp) để 
    ghi nhớ đỉnh liền kề để bắt đầu việc tìm kiếm khi không gặp được đỉnh liền 
    kề trong bất kỳ vòng lặp nào


    Ex:
        9 9
        1 2 
        1 3
        1 5
        2 4
        3 6
        3 7 
        3 9
        5 8 
        8 9


*/

// Đồ thị vô hướng

#include<bits/stdc++.h>
using namespace std;


int n, m;
vector<int> adj[1001];
bool visited[1001];

void DFS(int u) { // trị trí cần xét đầu tiên
    cout << u << endl;
    visited[u] = true;
    for(int v : adj[u]) {
        if (visited[v] == false) {
            DFS(v);
        }
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) { // duyệt qua m cạnh
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // C1
    memset(visited, false, sizeof(visited)); // dùng để gán tất cả giá trị mảng visited về false 
    // for(int i = 1; i <= n; i++) visited[i] = false; // C2

    DFS(1);

    return 0;
}

