
// số nguyên tố:
/*
    Với n = 24, kết quả factorSum(n) = 5.
    24 -> (2 + 2 + 2 + 3) = 9 -> (3 + 3) = 6 -> (2 + 3) = 5 -> 5.
    Vì vậy kết quả trong trường hợp n = 24 là 5.
*/

#include<iostream>
#include<cmath>
#include<string>

int solution(int n) {
    int sum = 0;
    for(int i=2; i<=n; i++) {
        while(!(n % i)) {
            sum += i;
            n /= i;
        }
    }
    return sum;
}

int factorSum(int n) {
    while(n != solution(n)) {
        n = solution(n);
    }
    return n;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << factorSum(n);

    return 0;
}