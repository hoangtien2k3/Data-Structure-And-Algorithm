
/*
    Nhập vào một số nguyên n (1 ≤ n ≤ 9).

Hãy đưa ra các chuỗi hoán vị của các số từ 1 đến n, các chuỗi tăng dần theo thứ tự từ điển, sau mỗi chuỗi hoán vị có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
3	123 132 213 231 312 321
Với n = 3 thì kết quả mong muốn là: "123 132 213 231 312 321 ".

Test mẫu 2:

Input	Output
4	1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2431 3124 3142 3214 3241 3412 3421 4123 4132 4213 4231 4312 4321
Với n = 4 thì kết quả mong muốn là: "1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2431 3124 3142 3214 3241 3412 3421 4123 4132 4213 4231 4312 4321 "

*/

#include<iostream>
using namespace std;

bool b[11];
int x[11];
void printArray(int a[], int n){
	for (int i = 1; i <= n; i++){
		cout << a[i];
	}
	cout <<" ";
}
void dequy(int k, int n){
	for (int i = 1; i <= n; i++){
		if (b[i]){
			x[k] = i; // 123
			if (k == n){
				printArray(x, n); // 123
			} else {
				b[i] = false; // b[1], b[2], b[3]
				dequy(k+1, n);
				b[i] = true;
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++){
		b[i] = true;
	}
	dequy(1, n);
}

//! Cach 2:
// #include<iostream>
// using namespace std;

// bool check(string s, char x){
//     for(int i = 0; i < s.length(); i++){
//         if(x == s[i]) 
// 			return false;
//     }
//     return true;
// }

// void deQuy(int n, string s, int temp){
//     if(n == 0) 
// 		cout << s << " ";
//     else {
//         for(int i = 1; i <= temp; i++) {
//         	if(check(s, char(i + '0'))) 
// 				deQuy(n - 1, s + char(i + '0'), temp);
//     	}
// 	}
// }
// int main(){
//     int n;
//     cin >> n;
//     deQuy(n, "", n);
// 	return 0;
// }
