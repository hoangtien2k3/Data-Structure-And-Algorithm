
/*
    Nhập vào một số nguyên dương n, tiếp theo nhập n số nguyên lần lượt là các phần tử của queue. Cuối cùng nhập vào một số tự nhiên k.

    Một phép biến đổi sẽ dịch chuyển phần tử đầu tiên ra sau phần tử cuối cùng của dãy, hãy trả về dãy sau khi đã biến đổi k lần. In tất cả 
    các phần tử ra màn hình, sau mỗi phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

    Input	
    4
    1 2 3 4
    1
    Output
    2 3 4 1
    
    Với queue = [1, 2, 3, 4] và k = 1, thì kết quả mong muốn là: "2 3 4 1 ".


*/

#include<bits/stdc++.h>
#include<queue>
using namespace std;


int main() {
    queue<int> q;
    int n, k;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        q.push(x);
    }
    cin >> k;
    for(int i=0; i<k; i++) {
        int res = q.front();
        q.pop();
        q.push(res);
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}