
// Liệt kê tổ hợp chập K của N bằng BackTracking: X1, X2, X3 ... XN

#include<bits/stdc++.h>
using namespace std;

int N, K, X[100];

void in_ket_qua(int X[]) {
    for(int i = 1; i <= K; i++) {
        cout << X[i];
    }
    cout << endl;
}

void Try(int i) {
    // duyệt các khả năng xảy ra mà X[i] có thể nhận được 
    for(int j = X[i - 1] + 1; j <= N - K + i; j++) {
        X[i] = j;
        if (i == K) {
            in_ket_qua(X);
        } else {
            Try(i + 1);
        }
    }
}


int main() {
    system("cls");

    cin >> N >> K;
    Try(1);

    system("pause");
    return 0;
}