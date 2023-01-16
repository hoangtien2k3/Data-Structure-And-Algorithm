
/*
    + Queue(hàng đợi) là một loại container, được thiết kế để hoạt động theo kiểu 
    FIFO (First- in first – out) (vào trước ra trước), tức là một kiểu danh sách 
    mà việc bổ sung được thực hiển ở cuối danh sách và loại bỏ ở đầu danh sách.


    Trong queue, có hai vị trí quan trọng là vị trí đầu danh sách (front), nơi phần tử được lấy ra, 
    và vị trí cuối danh sách (back), nơi phần tử cuối cùng được thêm vào.



    ! Các phương thức (ngôn ngữ C++):
        + size() :	Trả về số lượng phần tử của queue
        + empty() :	Trả về true(1) nếu queue rỗng, ngược lại là false (0)
        + front() :	Truy xuất phần tử ở đầu queue (phần tử đầu tiên được thêm vào)
        + back() :	Truy xuất phần tử ở cuối queue (phần tử cuối cùng được thêm vào)
        + push (const x) :	Thêm phần tử có giá trị x vào cuối queue. Kích thước queue tăng thêm 1.
        + pop () :	Loại bỏ phần tử ở đầu queue. Kích thước queue giảm đi 1.

*/

#include <iostream>

using namespace std;

int size = 10;
int front = 0;
int rear = -1;
int queue[10];


// kiểm tra rỗng
bool isEmpty() {
    return (front < 0 || front > rear) ? true : false;
}


// kiểm tra xem queue có đầy hay không
bool isFull() {
    return rear == size - 1 ? true : false;
}



void enqueue(int item) {
    if (isFull()) {
        cout << "Hàng đợi đầy rùi má ơi, không enqueue được nữa đâu!" << endl;
        return;
    }
    rear++;
    queue[rear] = item;
}


// kiểm tra rỗng
void dequeue() {
    if (isEmpty()) {
        cout << "Uầy, hàng đợi rỗng má ơi, có gì đâu mà dequeue!" << endl;
        return;
    }
    queue[front] = 0;
    front++;
}


int peek() {
    return queue[front];
}

int main() {
    
    

    
    return 0;
}