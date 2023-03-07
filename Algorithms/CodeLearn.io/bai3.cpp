
// liên quan đến Sàng Nguyên Tố trong C++ Eratosthenes
/*
    Ví dụ: Tìm ra cái số chia nguyên tố chúng lớn nhất
    Với a = 12 và b = 18, đầu ra là greatestCommonPrimeDivisor(a, b) = 3;
    Với a = 12 và b = 13, đầu ra là greatestCommonPrimeDivisor(a, b) = -1.    // -1 nghĩa là ko tìm thấy 
*/

#include<iostream>
#include<string>
#include<cmath>
#include<stdbool.h>

#define max 1000001
int arr[max];

void solution(int min) {
    for(int i=0; i<=min; i++) {
        arr[i] = 1; // gán tất cả các số trong mảng arr[i] = 1 // nghĩa là ta cứ cho tất cả các số trong mảng arr[i] là số nguyên tố
    }
    arr[0] = arr[1] = 0; // loại bỏ số 0 và 1 (vì nó méo phải số nguyên tố)
    for(int i=2; i <= sqrt(min); i++) {
        if (arr[i] == 1) {
            for(int j = i * i; j <= min; j+=i) { // các bội
                arr[j] = 0; // vì nó à bội của số nguyên tố i nên méo phải là số nguyên tố
            }
        }
    }
}

int min(int a, int b){
    return (a > b) ? a : b;
}

int greatestCommonPrimeDivisor(int a, int b) {
    solution(min(a, b)); // min(a, b) để tìm ra số nhỏ lớn giữa a và b
    for(int i = min(a, b); i >=2; i--) {
        if (arr[i] && (!(a % i) && !(b % i))) {
            return i;
        }
    }
    return -1; // -1 là ko tìm thấy
}

int main() {
    int a, b;
    std::cin >> a >> b;

    int result = greatestCommonPrimeDivisor(a, b);
    std::cout << result;

    return 0;
}