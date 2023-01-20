
//! Chuyển từ danh sách cạnh sang ma trận kề

/*
    Cho một đồ thị vô hướng G = <V, E> được biểu dưới dạng danh sách cạnh. Hãy viết một chương
    trình thực hiện chuyển đổi đồ thị dưới dạng ma trận kề.

    dòng đầu tiên chứa 2 số n, m là số đỉnh và số cạnh của đồ thị ( 1 <= n <= 1000, 1 <= m <= n*(n-1)/2 )

    M dòng tiếp theo mỗi dòng là 2 số u, v biểu diễn cạnh u, v của đồ thị ( 1 <= u, v <= n). Các
    cạnh được liệt kê theo thứ tự tăng dần của các đỉnh đầu.

    intput:
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

    output: in ra ma trận tương ứng với đồ thị.

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, arr[101][101]; // n đỉnh và m cạnh
    cin >> n >> m;
    
    for(int i = 0 ; i < m; i++) {
        int x, y; cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

