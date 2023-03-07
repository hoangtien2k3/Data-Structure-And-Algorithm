
//! Tính số mũ của a ^ b

#include<bits/stdc++.h>
using namespace std;

//! cách 1:
// int Recursion(int a, int b) {
//     if (b == 0)
//         return 1;
//     int x = Recursion(a, b / 2);
//     if (b % 2 == 1) {
//         return a * x * x; // mũ lẻ
//     } else {
//         return x * x; // mũ chẵn
//     }
// }

//! cách 2:
int Recursion(int a, int b) {
    if (b == 0)
        return 1;
    return a * Recursion(a, b - 1);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << Recursion(a, b);
    return 0;
}
