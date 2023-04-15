
## Thuật toán Bucket Sort:
Bucket Sort hữu dụng  khi cần sắp xếp các dãy số nằm trong một nằm trong một phạm vi nhỏ, thường là trong khoảng [0, 1) hoặc [0, k) với k là một số nguyên dương.
- ví dụ sắp xếp dãy số với các phần tử nằm trong khoảng 0.1 đến 1.0 hay là từ 1 đến 100.

![](https://resources.iostream.vn/content/article/5ef630c36b579e712606f869/resources/res-1597767753-1597767753526.png)

#### [Độ phức tạp của thuật toán là O(nlogn).]()

```java
    void bucketSort(float arr[], int n) {
	// Tạo các Bucket rỗng
	vector<int> b[n];

	// Đặt các phần tử vào các Bucket
	for (int i = 0; i < n; i++) {
            int bi = n * arr[i]; // Địa chỉ của Bucket
            b[bi].push_back(arr[i]);
	}

	// Sắp xếp trong từng Bucket
	for (int i=0; i<n; i++) {
            sort(b[i].begin(),b[i].end());
        }

	// Liên kết tất cả các Bucket lại
	int index = 0;
	for (int i = 0; i < n; i++) {
            for(int j=0;j<b[i].size();j++){
                arr[index++]=b[i][j];
            }
        }
    }
```



























