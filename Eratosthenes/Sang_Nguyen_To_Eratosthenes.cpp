
// Thuật toán sàng nguyên tố Eratosthenes:

// Ex: 12 => 2 3 5 7 11

// nếu bạn muốn sàng các số nguyên tố không vượt quá n
// phải tạo một mảng có kích thước là n + 1 phần tử

#include<stdio.h>
#include<math.h>

#define max 10000001
int arr[max];

void Sang_Nguyen_To() {
    for(int i=0; i<=max; i++) { //
        arr[i] = 1; // gán tất cả giá trị của mảng = 1 ( coi như tất cả các giá trị đều là số nguyên tố)
    }
    arr[0] = arr[1] = 0; // loại bỏ số 0 và số 1.
    for(int i=2; i<=sqrt(max); i++) {
        if (arr[i] == 1) { // nếu i  là số nguyên tố
            for(int j = i*i; j <= max; j+=i){
                arr[j] = 0; // j không còn là số nguyên tố nữa
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap vao n = ");
    scanf("%d", &n);
    Sang_Nguyen_To();
    for(int i=0; i<=n; i++) {
        if (arr[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}







//! Cách 2: không dùng sàng nguyên tố ( làm bằng cách thông thường )

//! ////////////////////////
// in ra các số nguyên tố từ 2 -> n (n nhập vào từ bàn phím)
// #include <stdio.h>
// #include <math.h>

// void in_nguyen_to(int n) {
//     for(int i=2; i<=n; i++) {
//         int count = 0;
//         for(int j=2; j<=sqrt(i); j++) {
//             if (i % j == 0) {
//                 count++;
//                 break;
//             }
//         }
//         if (count == 0 && i > 1) {
//             printf("%d\t", i);
//         }
//     }
// }

// int main() {
//     int n;
//     printf("Nhap vao n = ");
//     scanf("%d", &n);
//     in_nguyen_to(n);

//     return 0;
// }




    
