
// chuyển từ danh sách cạnh sang ma trận kề
/*
    cho đồ thị vô hướng: G=<V,E> biểu diễn dưới dạng danh sách cạnh. hãy viết chương trình biểu diễn chuyển đổi dưới dạng ma trận kề
    
    Ex:
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

    =>  0 1 1 1 
        1 0 1 1
        1 1 0 1
        1 1 1 0 
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];

int main() {    
    cin >> n >> m; // nhập vào n đỉnh và m cạnh
    for(int i=0; i<m; i++) { // duyệt m cạnh
        int x, y; cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }


    return 0;
}