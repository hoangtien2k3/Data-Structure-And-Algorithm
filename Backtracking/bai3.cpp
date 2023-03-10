
// Quay lui sinh xâu hoán vị của N phần tử.

#include<bits/stdc++.h>
using namespace std;

int N, X[100], used[100];

void in_ket_qua(int X[]) {
    for(int i = 1; i <= N; i++) {
        cout << X[i];
    }
    cout << endl;
}

void Try(int i) {
    // duyệt các khả năng xảy ra mà X[i] có thể nhận được 
    for(int j = 1; j <= N; j++) {
        // xét xem liệu là có thể gán X[i] = j hay không
        if (used[j] == 0) { // used[j] chưa được sử dụng
            X[i] = j;
            used[j] = 1; // đánh dấu là đã được duyệt qua.
            if (i == N) {
                in_ket_qua(X);
            } else {
                Try(i + 1);
            }
            //backtracking
            used[j] = 0;
        }
    }    



}

int main() {
    system("cls");

    cin >> N;
    Try(1);
    memset(used, 0, sizeof(used)); // khởi tạo các phần tử mảng used đều là 0

    system("pause");
    return 0;
}