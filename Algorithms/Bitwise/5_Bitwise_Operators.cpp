
//* Bitwise Operators: toán tử so sánh bit
/*
+ Bitwise Operators in C/C++:

    ! 1. The & (bitwise AND):   + số giống nhau thì AND là số đó
                                + số khác nhau thì AND là: 0 
        VD: 0   0 |     0
            0   1 |     0      
            1   0 |     0
            1   1 |     1
            
    ! 2. The | (bitwise OR):    + số khác nhau thì OR lấy số lớn hơn 
                                + số giống nhau thì OR là chính số giống nhau đó
        VD: 0   0 |     0
            0   1 |     1      
            1   0 |     1
            1   1 |     1

    ! 3. The ^ (bitwise XOR): + số giống nhau thì Xor = 0
                              + số khác nhau thì Xor lấy số lớn hơn là 1
        VD: 0   0 |     0
            0   1 |     1      
            1   0 |     1
            1   1 |     0

        Tính Chất: 
            + A ^ A = 0
            + A ^ 0 = A

    ! 4. The << (left shift): (dịch trái <<)
        VD: a;
            a = a << x => a * 2^(x)
        VD: A             0000 1100
                                <—
            B = A << 2    0011 0000

    ! 5. The >> (right shift): (dịch phải >>)
        VD: a;
            a = a << x => a / 2^(x)
        VD: A             0000 1100
                                —>
            B = A >> 2    0000 0011

    ! 6. The ~ (bitwise NOT): đảo ngược lại số nhị phân đó
        VD: A :       0000 1100
            B = ~A    1111 0011
        
        
*/


#include <iostream>
using namespace std;
  
int main() {
    system("cls");
    // //* a = 5(00000101), b = 9(00001001)
    int a = 5, b = 9;
  
    cout<<"a = " << a <<","<< " b = " << b <<endl;

    cout << "a & b = " << (a & b) << endl;
    

    cout << "a | b = " << (a | b) << endl;
  
 
    cout << "a ^ b = " << (a ^ b) << endl;
  

    cout << "~(" << a << ") = " << (~a) << endl; 
    cout << "~(" << b << ") = " << (~b) << endl; 


    cout<<"b << 1" <<" = "<< (b << 1) <<endl;  //todo: 9*2^1 = 18
    cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;


    cout << "a << 3" << " = " << (a << 3) << endl;
    cout << "a >> 3" << " = "  << (a >> 3) << endl;

    cin.get();
    return 0;
}


