
/*
    Nhập vào một số nguyên dương n.
Hãy in ra tất cả chuỗi nhị phân có độ dài n, các chuỗi sắp xếp tăng dần theo thứ tự từ điển, sau mỗi chuỗi có đúng một dấu cách.

Ví dụ:

Test mẫu 1:

Input	Output
1	
Với n = 1 thì kết quả mong muốn là: "0 1 ".

Test mẫu 2:

Input	Output
3	000 001 010 011 100 101 110 111
Với n = 3 thì kết quả mong muốn là: "000 001 010 011 100 101 110 111 ".

*/

#include<bits/stdc++.h>
using namespace std;

void dequy(int n, string s){
	if (n == 0) 
        cout << s << " ";
	else {
		for (int i = 0; i <= 1; i++) {
			dequy(n - 1, s + char(i + '0'));
		}
	}
}
int main(){
	int n; cin >> n;
	dequy(n, "");
    return 0;
}

