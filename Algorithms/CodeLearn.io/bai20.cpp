
/*
    Cho một bảng có n hàng và m cột
Mỗi một ô trong bảng ở hàng i và cột j chứa 1 số  có giá trị bằng i * j (chỉ số hàng và cột đều được đếm bắt đầu từ 1)
Cho trước n và m, hãy tìm số lượng các số nguyên khác nhau nằm trong bảng
Ví dụ:
Với n = 3 và m = 2, thì kết quả differentValuesInMultiplicationTable2(n, m) = 5.
Có 5 giá trị khác nhau nằm trong bảng là: 1, 2, 3, 4, 6
Đầu vào/Đầu ra:
[Thời gian chạy] 0.5 giây
[Đầu vào] integer n,m
Điều kiện:
1 ≤ n ≤ 20
[Đầu ra] integer
*/

#include<bits/stdc++.h>
using namespace std;

int differentValuesInMultiplicationTable2(int n, int m) {
    set<int> set;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            set.insert(i*j); // set để nó chỉ insert phần tử duy nhất vào set
        }
    }
    return set.size();
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << differentValuesInMultiplicationTable2(n, m);
    return 0;
}
