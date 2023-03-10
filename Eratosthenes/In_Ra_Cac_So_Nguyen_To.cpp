
// VD: 12 = 2 * 2 * 3

#include<stdio.h>
#include<math.h>

int NguyenTo (int n) {
    if (n < 2) 
        return 0;
    for(int i=2; i<=n ; i++) {
        while(n % i == 0) {
            n /= i;
            if (n > 1) {
                printf("%d * ", i);
            } else {
                printf("%d", i);
            }
        }
    }
}

int main() {    
    int n;
    printf("Nhap vao n = ");
    scanf("%d", &n);
    NguyenTo(n);
    return 0;
}


//! ////////////////////////
// in ra các số nguyên tố từ 2 -> n (n nhập vào từ bàn phím)
#include <stdio.h>
#include <math.h>

void in_nguyen_to(int n) {
    for(int i=2; i<=n; i++) {
        int count = 0;
        for(int j=2; j<=sqrt(i); j++) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
        if (count == 0 && i > 1) {
            printf("%d\t", i);
        }
    }
}

int main() {
    int n;
    printf("Nhap vao n = ");
    scanf("%d", &n);
    in_nguyen_to(n);
    return 0;
}