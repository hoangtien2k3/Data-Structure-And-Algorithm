
// Interchange sort : sắp xếp đổi chỗ trực tiếp 

/*
    Ý tưởng:
    * Bắt đầu từ phần tử ở vị trí đầu, tính từ vị trí đoạn chưa được sắp xếp,
    so sánh với các phần tử còn lại trong danh sách.
    - Trong các cặp so sánh, nếu phần tử ở vị trí đầu lớn hơn phần tử ở vị trí sau thì sẽ hoán vị.
    - Ngược lại, phần tử sau lớn hơn thì không hoán vị.

    CÁC BƯƠC:
        Bắt đầu từ vị trí đầu tiên i = 0 trong danh sách a[]
            Lặp cho đến khi i < n - 1.
                * Xét phần tử tại vị trí j = i + 1
                    Lặp trong khi j < n
                    + Nếu a[i] > a[j] thì hoán đổi giá trị của của a[i] và a[j]
                    + j++
                * i++
*/

#include<stdio.h>
// 3 , 5, 7, 3, 8, 9
// 0   1  2  3  4  5
int * interchangeSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
            }
        }
    }
    return a;
}

int main() {
    int a[5] = {1,5,7,3,9};
    int n = sizeof(a)/ sizeof(a[0]);
    interchangeSort(a, n);
    for (int i = 0; i < n; i++) {
        printf ("%d ", a[i]);
    }
    return 0;
}