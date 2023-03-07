// Kiểm tra số nguyên tố trong c++

#include<iostream>
#include<cmath>
#include<string>
#include<stdbool.h>

bool SNT(int a) {
    if (a < 2) {
        return false;
    }
    for(int i=2; i<sqrt(a); i++){
        if (!(a % i)) {
            return false;
        }
    }
    return true;
}

int main() {
    int a;
    std::cin >> a;
    SNT(a);
    if (SNT(a)) {
        std::cout << "La so nguyen to";
    } else {
        std::cout << "Ko phai so nguyen to";
    }
    return 0;
}