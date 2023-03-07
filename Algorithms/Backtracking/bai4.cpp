
// Quay lui bài toán N con hậu

#include<bits/stdc++.h>
using namespace std;

int N, X[100], cot[100], d1[100], d2[100];

int arr[100][100];

void in_ket_qua(int X[]) {
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= N; i++) {
        arr[i][X[i]] = 1;
    }
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i) {
    for(int j = 1; j <= N; j++) {
        if (cot[j] == 1 && d1[i - j + N] == 1 && d2[i + j - 1] == 1) {
            X[i] = j;
            cot[j] = d1[i - j + N] = d2[i + j - 1] = 0;
            if (i == N) {
                in_ket_qua(X);
            } else {
                Try(i + 1);
            }
            //backtracking
            cot[j] = d1[i - j + N] = d2[i + j - 1] = 1;
        }
    }
}

int main() {
    system("cls");

    cout << "Nhao vao N <= 8(ban co 8x8 = 64): ";
    cin >> N; 
    
    for(int i = 1; i <= 100; i++) {
        cot[i] = d1[i] = d2[i] = 1;
    }
    Try(1);

    system("pause");
    return 0;
}