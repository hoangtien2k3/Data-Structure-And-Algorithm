
//! Quick Sort: sắp xếp nhanh: O(n log(n)) // áp dụng chia để trị(devide and conquer).

#include<bits/stdc++.h>
using namespace std;

//! áp dụng phân hoạch Lomuto:
int partition(int arr[], int l, int r) { // O(n log(n))
    int pivot = arr[r]; // phan tu cuoi cung
    int i = l - 1; // -1
    for(int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    ++i; // dua chot ve giua
    swap(arr[i], arr[r]);
    return i; // vi tri
}

int * quickSort(int *arr, int l, int r) {
    if (l >= r) return arr;
    int p = partition(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
}

int main() {    
    int n; cin >> n;
    int arr[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    quickSort(arr, 0, n - 1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}




