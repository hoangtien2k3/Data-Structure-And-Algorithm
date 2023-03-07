
/*
    * Khái niệm về cây nhị phân hoàn chỉnh:
        + Cấy nhị phân hoàn chình là cây nhị phân mà trong đó tất cả các cấp(level)
        được lấy đầy hoàn toàn. Ngoại trừ có thể là cấp thấp nhất và được điền từ bên trái.

        + Tất cả các phần tử lá phải nghiêm về bến trái.


    ! Cấu trúc dữ liệu Heap:
        + Heap là một cây nhị phân hoàn chỉnh.

        + Chia làm hai loại:
            - Max-heap: để sắp xếp tăng dần.
            - Min-heap: để sắp xếp giảm dần.

*/

#include<bits/stdc++.h>
#include<algorithm>

void heapity(int *arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) 
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapity(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapity(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--) {
        std::swap(arr[i], arr[0]);
        heapity(arr, i, 0);
    }
}

int main() {
    system("cls");

    int arr[] = {2, 7, 3, 10, 34, 76, 23, 56, 123, 134};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cin.get();
    return 0;
}