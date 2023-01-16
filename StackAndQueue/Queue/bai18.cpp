
/*
    Số siêu nguyên tố là số:

    Bản thân nó là số nguyên tố.
    Khi xóa đi lần lượt các chữ số sau cùng của nó, thì số mới vẫn là số nguyên tố.
    Ví dụ 2393 là số siêu nguyên tố vì 2393, 239, 23, 2 là số nguyên tố.

    Cho một số n, hãy đưa số dãy số siêu nguyên tố nhỏ hơn hoặc bằng n, các số đã được sắp xếp tăng dần.

    Ví dụ:

    Test mẫu 1:

    Input Output
    30

    2 3 5 7 23 29 


    Với n = 30 thì superPrimeNumber(n) = [2, 3, 5, 7, 23, 29];
    Vì các số 2, 3, 5, 7, 23 và 29 đều là số siêu nguyên tố và nhỏ hơn hoặc bằng 30.

*/

#include<bits/stdc++.h>
using namespace std;
#include<queue>

bool nguyento(int n) {
    if (n < 1) return false;
    for(int i=2; i <= sqrt(n); i++) {
        if (n % i == 0) 
            return false;
    }
    return true;
}

void display(queue<int> q, int n) {
    for (int i = 2; i <= n, i < 10; i++){
        if (nguyento(i)){
            q.push(i);
        }
    }
    while (!q.empty()){
        for (int i = 1; i <= 9; i++){
            int k = q.front() * 10 + i;
            if ( k <= n && nguyento(k)){
                q.push(q.front() * 10 + i);
            }
        }
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n;
    cin >> n;
    
    display(q, n);
    return 0;
}