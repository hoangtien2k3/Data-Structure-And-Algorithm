
//! Interpolation Search: tìm kiếm nội suy:  O(log(log(n))).
/*
    + Thuật toán tìm kiếm nội suy là một sự cải tiến của tìm kiếm nhị phân Binary Search. 
    Nó có xu hướng tiến gần đến vị trí, giá trị tìm kiếm. Do đó tốc độ tìm kiếm được 
    tối ưu rất cao và nhanh hơn nhiều so với Binary Search.

    + Cách thức hoạt động của nó dựa trên Binary Search, nhưng có sự cải tiến hơn. 
    Đó chính là nó tìm ra phần tử gần với giá trị tìm kiếm nhất và bắt đầu từ đó để tìm.


*/

#include<bits/stdc++.h>
using namespace std;

int InterpolationSearch(int arr[], int n, int x) { // O(log(log(n)))
    int left = 0, right = n - 1; 
    while(left <= right && x >= arr[left] && x <= arr[right]) {
        double val1 = (double) (x - arr[left]) / (arr[right] - arr[left]);
        int mid = left + (right - left) * val1;
        if (arr[mid] < x)
            left = mid + 1;
        else if (arr[mid] > x)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    
    cout<<"NHAP SO CAN TIM: "; cin >> x;

    int index = InterpolationSearch(arr, n, x);
    if (index != -1)
        cout << "Da tim thay "<< x << " trong mang tai vi tri " << index;
    else
        cout << "Khong tim thay "<< x <<" trong mang.";
        
    return 0;
}