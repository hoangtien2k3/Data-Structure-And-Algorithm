
// đếm  số bit có giá trị 1 của n

#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	while (n != 0) {
		if (n & 1) {
			count++;
		}
		n >>= 1;
	}
	cout << "answer = " << count;
	return 0;
}