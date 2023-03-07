
// Tính tổng các phần tử trong mảng

#include<bits/stdc++.h>
using namespace std;

int Tong(int n, int a[]) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int a[101], n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << Tong(n, a) << endl;
    return 0;
}