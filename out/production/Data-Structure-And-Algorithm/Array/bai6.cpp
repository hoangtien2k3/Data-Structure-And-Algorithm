
/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Hãy in lần lượt các số nguyên tố có trong dãy a ra màn hình, sau mỗi phần tử có đúng một khoảng trắng.
(Số nguyên tố là số nguyên dương có đúng 2 ước là 1 và chính nó. Số a được gọi là ước của b nếu b chia hết cho a). Biết rằng dãy sẽ có ít nhất một số nguyên tố.

Ví dụ:

Test mẫu 1:

Input	Output
4
1 2 3 4

2 3 
Với n = 4, a = [1, 2, 3, 4] thì kết quả mong muốn là: "2 3 ".


*/
#include<bits/stdc++.h>

bool nt(int a) {
    for (int i=2; i<=sqrt(a); i++) {
        if (a % i == 0) {
           return false;
        }
    }
    return a > 1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    for(int i=0; i<n; i++) {
        int x; std::cin >> x;
        a.push_back(x);
    }
    for (int i=0; i<n; i++)  {
        if (nt(a[i])) {
            std::cout << a[i] << " ";
        }
    }
    return 0;
}
