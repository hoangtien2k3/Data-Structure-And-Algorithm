
// chuyển từ thập phân sang nhị phân

#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main() {
    stack<int> st;
    int n;
    cin >> n;

    while(n > 0) {
        st.push(n % 2);
        n /= 2;
    }

    while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
    
    return 0;
}




// hoặc dùng vector cũng được
// int main() {
//     vector<int> a;
//     int n; cin >> n;
//     int binary;

//     while(n != 0) {
//         a.push_back(n % 2);
//         n /= 2;
//     }
//     for(int i = a.size() - 1 ; i >= 0; i--) {
//         cout << a[i];
//     }
// }