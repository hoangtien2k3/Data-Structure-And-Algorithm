
// chuyển từ hệ thập phân sang hệ nhị phân bằng Stack

#include<bits/stdc++.h>
using namespace std;

int main() {
    system("cls");

    int n; cout << "Decimal: "; cin >> n;
    stack<int> stack;

    while(n) {
        int temp = n % 2;
        stack.push(temp);
        n /= 2;
    }

    cout << "Bianry: ";
    while(stack.size()) {
        cout << stack.top();
        stack.pop();
    }

    cin.get();
    return 0;
}