
// Greedy Algorithm: Thuật toán tham lam
/*
    Tại ngân hàng có các mệnh giá: 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. Tổng số tiền 
    cần đổi có giá trị bằng N. Hãy xác định xem co ít nhất bao nhiêu tờ tiền sau khi đổi tiền.


*/

#include<bits/stdc++.h>

int doiTien(int *arr, int sotien) {
    // int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    for(int i = 10 - 1; i >= 0; i--) {
        count += sotien/arr[i];
        sotien %= arr[i];
    }
    return count;
}

int main() {
    int sotien; std::cin >> sotien;
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    
    std::cout << doiTien(arr, sotien) << std::endl;

    return 0;
}