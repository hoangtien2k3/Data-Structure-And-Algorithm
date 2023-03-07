
//! Prefix Sum: mảng cộng dồn
/*
    Công thức tổng quát: (mảng một chiều)
        + F[i] = F[i - 1] + A[i] // từ đầu đến vị trí thứ i

        + F[i...j] = F[j] - F[i - 1] // từ vị trí thứ i đến vị trí thứ j 


    Ex:
        5
        1 2 3 4 5
        1 3
    
    => solution() = 6 // 1 + 2 + 3 = 6 

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n + 1];
    int prefix[n + 1] = {0};
    for(int i=1; i<=n; i++) cin >> arr[i];
    
    for(int i=1; i<=n; i++) prefix[i] = prefix[i - 1] + arr[i];

    int l, r; cin >> l >> r; // từ vị trí l đến vị trí r
    cout << prefix[r] - prefix[l - 1] << endl;

    return 0;
}