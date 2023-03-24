```c++

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Hàm thực hiện Bucket Sort để sắp xếp mảng
void bucketSort(float arr[], int n)
{
    // Khởi tạo một mảng chứa các bucket
    vector<float> bucket[n];

    // Đưa các phần tử của mảng vào bucket tương ứng
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i];
        bucket[bucketIndex].push_back(arr[i]);
    }

    // Sắp xếp các phần tử trong từng bucket bằng insertion sort
    for (int i = 0; i < n; i++)
        sort(bucket[i].begin(), bucket[i].end());

    // Đưa các phần tử đã sắp xếp trở lại vào mảng
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucket[i].size(); j++)
            arr[index++] = bucket[i][j];
}

// Hàm in ra mảng
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    printArray(arr, n);
    return 0;
}

```
