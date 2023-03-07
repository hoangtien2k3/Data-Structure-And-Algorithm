
//! Shell Sort: thuật toán 
/*
    + Shell Sort là một giải thuật sắp xếp mang lại hiệu quả cao dựa trên giải 
    thuật sắp xếp chèn (Insertion Sort).

    Đầu tiên, giải thuật này sử dụng giải thuật sắp xếp chọn trên các phần tử có khoảng cách xa nhau, 
    sau đó sắp xếp các phần tử có khoảng cách hẹp hơn. Khoảng cách này còn được gọi là khoảng (interval).

    interval sẽ nhận giá trị lần lượt là n/2, n/4, n/8 cho đến khi interval = 1.

    Giải thuật này khá hiệu quả với các tập dữ liệu có kích cỡ trung bình khi mà độ phức tạp 
    trường hợp xấu nhất và trường hợp trung bình là O(n), với n là số phần tử.

*/

#include<bits/stdc++.h>
using namespace std;

int * shellSort(int *arr, int n) { // O(n)
	int interval, i, j, value;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			value = arr[i];
			for(j = i; j >= interval && arr[j - interval] > value; j -= interval){
				arr[j] = arr[j - interval];				
			}
			arr[j] = value;
		}
    }
    return arr;
}

int main(){
	int n;
	cin >> n;
    int arr[100001];
	for(int i = 0; i < n; i++){
		cin >> arr[i];		
	}
	shellSort(arr, n);
	for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}