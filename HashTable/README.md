
## Bảng băm (Hash Table)
- Bảng băm là một CTDL thường được sử dụng như một từ điển: mỗi phần tử trong bảng băm là một cặp (khóa, giá trị).
- Nếu so sánh với mảng, khóa được xem như chỉ số của mảng, còn giá trị giống như giá trị mà ta lưu tại chỉ số tương ứng.
- Bảng băm không như các loại từ điển thông thường - ta có thể tìm được giá trị thông qua khóa của nó.


![](https://vnoi.info/wiki/uploads/data_structures_hash_table_hash_function.png)

```text
Giải thích hình minh họa:

- Ta cần lưu số điện thoại của 3 người:
  - John Smith: 521-1234
  - Lisa Smith: 521-8976
  - Sandra Dee: 521-9655

- Giá trị Hash của 3 người này lần lượt là: 1, 2 và 14.
- Sau khi tính được giá trị Hash của 3 người, ta lưu vào các bucket tương ứng là 1, 2 và 14.
```

## Độ phức tạp:
- n : là số phần tử ta cần lưu trong Hash table
- k : là số bucket
- Giá trị n/k được gọi là load factor. Khi load factor nhỏ (xấp xỉ 1), và giá trị của hàm Hash phân bố đều, độ phức tạp của các thao tác trên Hash table là O(1)


## Hash collision(va chạm)
- Trường hợp một hash bucket chứa nhiều hơn một giá trị ta gọi đó là Hash collision (va chạm). 
- Việc xử lý hash collision rất quan trọng đối với độ hiệu quả của bảng băm.
- Một trong những phương pháp đơn giản nhất là cài đặt các danh sách liên kết ở các bucket. Kĩ thuật này được gọi là Separate chaining:

![](https://vnoi.info/wiki/uploads/data_structures_hash_table_collision_linked_list.png)

```text
Giải thích hình minh họa:

- Mỗi bucket là 1 danh sách liên kết
- John Smith và Sandra Dee cùng có giá trị hàm hash là 152, nên ở bucket 152, ta có 1 danh sách liên kết chứa 2 phần tử.
```


## Open Addressing:
- Tư tưởng của Open Addressing là, khi xảy ra Hash collision, ta lưu vào một vị trí tiếp theo trong bảng băm. 

![](https://vnoi.info/wiki/uploads/data_structures_hash_table_collision_open_addressing.png)


## Cài đặt:

```c++
const int P = 1e6 + 3;

struct HashTable {
    vector< pair<int,int> > h[P];

public:
    void insert(int key, int value) {
        int hkey = getHash(key);
        for (auto p : h[hkey]) {
            if (p.first == key) {
                // key da ton tai trong Hash table, ta bo qua
                return;
            }
        }
        // Them (key, value) vao hash table
        h[hkey].emplace_back(key, value);
    }

    int find(int key) {
        int hkey = getHash(key);
        for(auto p : h[hkey]) {
            if (p.first == key) {
                // ton tai key trong Hash table, return value
                return p.value;
            }
        }
        // Khong tim thay
        return 0;
    }

private:
    int getHash(int key) {
        // Cho 1 key, tra lai Hash value la key % P
        return key % P;
    }
};
```














