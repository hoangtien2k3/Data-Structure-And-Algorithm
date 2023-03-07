
//! Quick Sort: sắp xếp nhanh: O(n log(n))

#include<bits/stdc++.h>
using namespace std;

//! Cách 2: áp dụng phân hoạch Hoare:
void quickSort(int arr[], int l, int r) {
	int pivot = arr[(l + r) / 2];
	int i = l, j = r;
	while(i < j) {
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot) 
			j--;
		if (i <= j) {
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


//! Cách 2: áp dụng phân hoạch Hoare:
int partition(int arr[], int l, int r) {
	int pivot = arr[l];
	int i = l, j = r;
	while(true) {
		while(arr[i] < pivot)
			++i;
		while(arr[j] > pivot)
			--j;
		if (i < j) {
			swap(arr[i], arr[j]);
			i++; 
			j--;
		} else {
			return j;
		}
	}
}

void quickSort(int arr[], int l, int r) {
	if (l >= r) return;
	int p = partition(arr, l, r); // return j
	quickSort(arr, l, p);
	quickSort(arr, p + 1, r);
}


int main() {    
	system("cls");
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
	cin.get();
    return 0;
}



