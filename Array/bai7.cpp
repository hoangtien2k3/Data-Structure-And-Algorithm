
/*
    Nhập và một số nguyên dương n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số, hãy đếm tần số (số lần xuất hiện) của các số trong dãy và in nó ra màn hình dưới dạng sau: "a1 - t1; a2 - t2; ... an - tn; ", trong đó t1 là số lần xuất hiện của số a1, t2 là số lần xuất hiện của a2, ... a1, a2, .. an không trùng nhau và được sắp xếp tăng dần (xem ví dụ để rõ hơn).

Ví dụ:

Test mẫu 1:

Input	Output
6
4 2 2 5 6 5

2 - 2; 4 - 1; 5 - 2; 6 - 1;
Với a = [4, 2, 2, 5, 6, 5] thì kết quả mong muốn là: "2 - 2; 4 - 1; 5 - 2; 6 - 1; "

*/


#include<bits/stdc++.h>
using namespace std;

void tan_Xuat(vector<int> v) {
    vector<int> b(254, 0);
    for(int i=0; i<v.size(); i++) {
        b[v[i]]++;
    }
    for(int i=0; i< 254; i++) {
        if (b[i] > 0) {
            cout << i << " - " << b[i] << ";" << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    tan_Xuat(v);

    return 0;
}