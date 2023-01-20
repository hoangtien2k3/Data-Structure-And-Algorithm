
#include<bits/stdc++.h>
using namespace std;


string sum(string a, string b) {
    string result = "";

    //! them 0 vao truoc chuoi nho hon, de 2 chuoi co do dai bang nhau.
    while(a.length() < b.length()) a = "0" + a;
    while(a.length() > b.length()) b = "0" + b;

    int carry = 0;

    for(int i = a.length() - 1; i >= 0; i--) {
        int temp = int(a[i] - '0') + int(b[i] - '0') + carry;
        result = char(temp % 10 + '0') + result;
        carry = temp / 10; 
    }

    if (carry > 0) return char(carry + '0') + result;

    return result;
}


int main() {
    string a, b;
    cin >> a >> b;

    cout << sum(a, b) << endl;


    return 0;
}