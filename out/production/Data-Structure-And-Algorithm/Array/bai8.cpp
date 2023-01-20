
/*
    Nhập và một số nguyên dương n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số a. Hãy kiểm tra xem dãy a có phải là dãy đơn điệu hay không, trả về "YES" nếu có, "NO" nếu không.

Một dãy đơn điệu khi nó là dãy số tăng (a[i] > a[i-1]), hoặc dãy số giảm (a[i] < a[i-1]).

Ví dụ:

Test mẫu 1:

Input	Output
5
1 2 3 4 5

YES
Với a = [1, 2, 3, 4, 5] thì kết quả mong muốn là "YES".

Test mẫu 2:

Input	Output
4
5 3 1 -4

YES
Với a = [5, 3, 1, -4] thì kết quả mong muốn là "YES".

Test mẫu 3:

Input	Output
5
1 2 4 3 -2

NO
Với a = [1, 2, 4, 3, -2] thì kết quả mong muốn là "NO".

*/


#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> v) {
    int count = 0, temp = 0;
    for(int i=0; i<v.size() - 1; i++) {
        if (v[i] < v[i + 1])
            count++;
        if (v[i] > v[i + 1])
            temp++;
    }
    if (count == v.size() - 1) {
        return true;
    } else if (temp == v.size() - 1){
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    if (check(v))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
