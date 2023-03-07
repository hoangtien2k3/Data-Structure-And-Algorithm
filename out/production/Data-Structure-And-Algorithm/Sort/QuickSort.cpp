
//! Quick Sort: thật toán sắp xếp nhanh: O(n log(n))

#include<bits/stdc++.h>
using namespace std;


//! Cách 1: áp dụng phân hạch Lomuto
// int partition(int arr[], int l, int r) { 
//     int pivot = arr[r]; // phan tu cuoi
//     int i = l - 1; // -1
//     for(int j = l; j < r; j++) {
//         if (arr[j] <= pivot) {
//             ++i;
//             swap(arr[i], arr[j]);
//         }
//     }
//     ++i; // dua chot ve giua
//     swap(arr[i], arr[r]); 
//     return i; // vi tri
// }

// int * quickSort(int *arr, int l, int r) { //! O(n log(n))
//     if (l >= r) return arr;
//     int p = partition(arr, l, r);
//     quickSort(arr, l, p - 1);
//     quickSort(arr, p + 1, r);
// }


//! Cách 2: áp dụng phân hoạch Hoare:
void quickSort(int arr[], int l, int r){
	int pivot = arr[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (i < r)
		quickSort(arr, i, r);
	if (l < j)
		quickSort(arr, l, j);
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




