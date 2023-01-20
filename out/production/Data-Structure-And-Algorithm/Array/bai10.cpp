
// Tính tổng các phân tử trong mảng 2 chiều

#include<bits/stdc++.h>
using namespace std;

int sum(int m, int n, int arr[][200]) {
    int sum = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    int m, n ;
    int arr[100][200];
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << sum(m, n, arr);
}