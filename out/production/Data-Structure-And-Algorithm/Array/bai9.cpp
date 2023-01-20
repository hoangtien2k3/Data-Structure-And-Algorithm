
/*
    Cho dãy a gồm n số nguyên, và dãy b gồm m số nguyên, cả hai dãy đều được sắp xếp không giảm.
Hãy gộp hai dãy thành một dãy c, sao cho dãy c cũng là dãy không giảm. In dãy c ra màn hình, sau mỗi phần tử có đúng một dấy cách.

Ví dụ:

Test mẫu 1:

Input	Output
3
1 3 4
4
1 2 3 5

1 1 2 3 3 4 5 
Với a = [1, 3, 4] và b = [1, 2, 4, 5] thì kết quả mong muốn là: "1 1 2 3 4 4 5 ".

Test mẫu 2:

Input	Output
3
1 2 3
3
2 3 4

1 2 2 3 3 4 
Với a = [1, 2, 3] và b = [2, 3, 4] thì kết quả mong muốn là: "1 2 2 3 3 4 ".

*/


#include<bits/stdc++.h>
using namespace std;


void check(vector<int> a, vector<int> b) {
    vector<int> c;
    for(int i=0; i < a.size(); i++)
        c.push_back(a[i]);
    for(int i=0; i<b.size(); i++)
        c.push_back(b[i]);
    sort(c.begin(), c.end());
    for(int x : c) {
        cout << x << " ";
    }
}

int main() {
    vector<int> a;
    vector<int> b;
    int n, m;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int z; cin >> z;
        b.push_back(z);
    }
    check(a, b);
    return 0;
}