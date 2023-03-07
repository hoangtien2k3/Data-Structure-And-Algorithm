
// SelectionSort : sắp xếp lựa chọn

#include<stdio.h>
#include<math.h>

// tăng dần
void selectionSort (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[max] > arr[j]) {
                max = j;
            }
        }
        if (max != i) {             //! biến min đã được thay đổi
            int temp = arr[max];
            arr[max] = arr[i];      //* a[i] đang là phần tử đầu tiên trong mảng
            arr[i] = temp;
        }
    }
}

int main() {
    int arr[100], n;
    printf ("Nhap so phan tu: n = ");
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        printf ("arr[%d] = ", i);
        scanf ("%d", &arr[i]);
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    return 0;
}