
//! Dùng tham lam để giải bài toán xếp gạch:

/*
        Anh Lộc làm nghề phụ hồ cho một công ty xây dựng, Anh nhận thấy rằng mỗi loại gạch đều có độ cứng khác nhau.
    Giả sử rằng viên gạch có độ cứng k chỉ có thể chịu được tối đa k viên gạch khác chồng lên nó, nếu nhiều hơn thì nó sẽ bị vỡ.

    Cho mảng a gồm n số nguyên dương lần lượt là độ cứng của các viên gạch.

    Anh Lộc muốn lấy gạch và xếp chúng chồng lên nhau thành một chồng gạch cao nhất có thể mà không để vỡ viên gạch nào

    Hãy tìm và in ra màn hình xem anh Lộc có thể xếp chồng gạch có độ cao lớn nhất là bao nhiêu.

    Ví dụ: 

    Test mẫu 1:

    Input	Output
    5
    1 1 2 1 1
    => 3

    Với a = [1, 1, 2, 1, 1], thì kết quả sẽ arrangeBricks(a) = 3.
    Ta có
    a[0] = 1 nghĩa là nó có thể chịu được 1 viên gạch xếp ở trên.
    a[1] = 1 nghĩa là nó có thể chịu được 1 viên gạch xếp ở trên.
    a[2] = 2 nghĩa là nó có thể chịu được 2 viên gạch xếp ở trên.
    a[3] = 1 nghĩa là nó có thể chịu được 1 viên gạch xếp ở trên.
    a[4] = 1 nghĩa là nó có thể chịu được 1 viên gạch xếp ở trên.

*/

#include<bits/stdc++.h>
using namespace std;


int partition(int arr[], int l, int r) {
	int pivot = arr[l];
	int i = l, j = r;
	while(true) {
		while(arr[i] < pivot) ++i;
		while(arr[j] > pivot) --j;
		if (i < j) {
			swap(arr[i], arr[j]);
            i++; j--;
		} else return j;
	}
}

void quickSort(int arr[], int l, int r) {
	if (l >= r) return;
	int p = partition(arr, l, r); // return j
	quickSort(arr, l, p);
	quickSort(arr, p + 1, r);
}


int solve(int arr[], int n){
	int count = 1;
	quickSort(arr, 0, n - 1);
	int ans = arr[n-1]; // 2
	for (int i = n-2; i >= 0; i--){
		count = count + 1;
		ans = ans - 1;
		if (ans > arr[i]) { 
            ans = arr[i]; 
        }
		if (ans == 0) 
            return count;
	}
	return n;
}


int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(arr, n) << endl;

    return 0;
}

