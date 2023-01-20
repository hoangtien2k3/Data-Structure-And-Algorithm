
// chuyển từ ma trận kề sang danh sách cạnh

/*
    Cho đồ thị vô hướng G = <V, E> được biểu diễn dưới dạng ma trận kề. Hãy viết 
    chương trình chuyển đổi biểu diễn đồ thị về dạng danh sách cạnh.

    Cho n đỉnh (1 <= n <= 1000)


    5
    0 1 1 1 0
    1 0 1 1 1
    1 1 0 1 1 
    1 1 1 0 1 
    0 1 1 1 0

*/

#include<bits/stdc++.h>
using namespace std;


vector<pair<int, int>> edge;
int arr[100][100];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 && i < j) { // i < j để không bị lặp lại (VD: 1 - 4 thì lặp lại sẽ là 4 - 1).
                edge.push_back({i, j});
            }
        }
    }

    for(auto out : edge) {
        cout << out.first << "  " << out.second << endl;
    }

    return 0;
}