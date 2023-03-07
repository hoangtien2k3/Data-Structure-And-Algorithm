

//!  Code tắt bit thứ n của số a:    a = a & ~(1 << (n - 1));
        
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    //ex: a = 27, n = 4
    int a = 27, n = 4; // 27 = 11011

    a = a & ~(1 << (n - 1)); // code tắt bit thứ n của a
    // 11011 -> 10011 = 19

    cout << a << endl;



}