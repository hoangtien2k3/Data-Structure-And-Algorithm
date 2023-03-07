/*
    Chuyển số nhị phân sang thập phân.
        Hệ thập phân: 1234 = 1 * 10^3 + 2 * 10^2 + 3 * 10^1 + 4 * 10^0
        Hệ nhị phân: 101 = 1 * 2^2 + 0 * 2^1 + 1 * 2^0

        1234 => 1*10^0 + 2* 10^1 + 3*10^2 + 4*10^3 = 4321 ( đảo ngược )

    Cách chuyển:
        n = 8
        0, 4 => 8 % 2 * 10 ^ 0
        0, 2 => 4 % 2 * 10 ^ 1
        0, 1 => 2 % 2 * 10 ^ 2
        1, 0 => 1 % 2 * 10 ^ 3
        int kq = 1000

        Mục đích mà nhân với 10^0 ... 10^4 là để đảo ngược số đó 
*/
 
// //! Cách 1: chuyển dạng thập phân sang nhị phân
#include <stdio.h>
#include <math.h>
 
long long Dec2Bin(int decimalNumber) {
    long long binaryNumber = 0;
    int i = 0;
    while (decimalNumber != 0) {
        binaryNumber += (decimalNumber % 2) * pow(10, i);
        i++;
        decimalNumber /= 2;
    }
    return binaryNumber;
}
 
int main(){
    int decimalNumber;
    printf("\nInput decimalNumber: ");
    scanf("%d", &decimalNumber);
    printf("BinaryNumber = %d", Dec2Bin(decimalNumber));
}







// //! Chuyển từ Nhị phân về Thập phân:
#include<stdio.h>  
#include<conio.h>  
#include<math.h>

long long Binary_N (long long binaryNumber) {
    long long decimalNumber = 0, res;
    int i = 0; 
    while (binaryNumber != 0) {
        decimalNumber += (binaryNumber % 10) * pow(2, i);
        binaryNumber /= 10;
        i++;
    }
    return decimalNumber;
}

int main() {
    long long binaryNumber;
    printf ("Nhap vao binaryNumer = ");
    scanf ("%lld", &binaryNumber);

    printf ("DecimalNumber: %lld", Binary_N(binaryNumber));
    return 0;
}





//! Cách 3: dùng Bitwise chuyển từ thập phân sang nhị phân
#include<stdio.h>
#include<math.h>
#include<conio.h>

void Dec2Bin(int decimalNumber) {
    for (int i=31; i>=0; i--) {
        if (decimalNumber & (1 << i))
            printf ("1");
        else 
            printf ("0");
    }
}

int main() {
    int decimalNumber;
    printf ("Nhap vao decimalNumber = "); scanf ("%d", &decimalNumber);
    Dec2Bin(decimalNumber);
}





//! Cách 2: Dùng mảng chuyển từ thập phân sang nhị phân
#include<stdio.h>  
#include<conio.h>  
int a[30],n,i;
void Binary_N (int n, int a[]) {
    for(i=0;n>0;i++)  
    {  
        a[i] = n % 2;  
        n = n / 2;  
    }  
    printf("Nhi phan cua so vua nhap: ");  
    for(i=i-1;i>=0;i--)  
    {  
        printf("%d",a[i]);  
    }  
}

int main(){  
    char TL;
    do {
        printf("\nNhap mot so bat ky: ");  
        scanf("%d",&n);
        Binary_N(n, a);
        printf ("\nBan co muon tiep tuc(Y, N): ");
        fflush(stdin);
        TL = getchar();
    } while (TL == 'Y' || TL == 'y');
    
    return 0;
}







