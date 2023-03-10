
/*
    in ra bit thứ n của a 

    Ex: 11  3   
    => 0

*/

#include<bits/stdc++.h>

int main() {

    for(int i = 0; i < 10; i++) {
        std::cout << (1 << i) << "  "; // tương tự như 2^0 - 2^1 - 2^2 ... 2^(i-1)
    }

    std::cout << std::endl;

    std::cout << (8 >> 1) << std::endl;
    std::cout << (8 << 1) << std::endl; 

    return 0;
}