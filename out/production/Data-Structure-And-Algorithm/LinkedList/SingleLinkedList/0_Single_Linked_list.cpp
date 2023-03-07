
// Link: https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/

/*
    Danh sách liên kết đơn (Single Linked List) là một cấu trúc dữ liệu động, nó là một danh sách 
    mà mỗi phần tử đều liên kết với phần tử đúng sau nó trong danh sách. Mỗi phần tử 
    (được gọi là một node hay nút) trong danh sách liên kết đơn là một cấu trúc có hai thành phần:

        + Thành phần dữ liệu: lưu thông tin về bản thân phần tử đó.
        + Thành phần liên kết: lưu địa chỉ phần tử đứng sau trong danh sách, nếu phần tử đó là phần tử cuối cùng thì thành phần này bằng NULL.



    ! Đặc điểm của danh sách liên kết đơn:
        * Do danh sách liên kết đơn là một cấu trúc dữ liệu động, được tạo nên nhờ việc cấp phát động nên nó có một số đặc điểm sau đây:

        + Được cấp phát bộ nhớ khi chạy chương trình.
        + Có thể thay đổi kích thước qua việc thêm, xóa phần tử.
        + Kích thước tối đa phụ thuộc vào bộ nhớ khả dụng của RAM.
        + Các phần tử được lưu trữ ngẫu nhiên (không liên tiếp) trong RAM.


        * Và do tính liên kết của phần tử đầu và phần tử đứng sau nó trong danh sách liên kết đơn, nó có các đặc điểm sau:

        + Chỉ cần nắm được phần tử đầu và cuối là có thể quản lý được danh sách.
        + Truy cập tới phần tử ngẫu nhiên phải duyệt từ đầu đến vị trí đó.
        + Chỉ có thể tìm kiếm tuyến tính một phần tử.


*/

/*
    !Tạo Node:
        Danh sách liên kết đơn được tạo thành từ nhiều node
        * Một node gồm hai thành phần: là 
            + thành phần dữ liệu.
            + thành phần liên kết.

        Ex: 
            struct Node
            {
                int data;
                Node* next;
            };

        * Để tạo một node mới, ta thực hiện cấp phát động cho node mới, khởi tạo giá trị ban đầu và trả về địa chỉ của node mới được cấp phát.

            Node* CreateNode(int init_data)
            {
                Node* node = new Node;
                node->data = init_data;
                node->next = NULL;      //  node vừa tạo chưa thêm vào danh sách nên chưa liên 
                                            kết với phần tử nào cả nên phần liên kết gán bằng NULL
                return node;
            }
*/

/*
    ! Tạo danh sách liên kết đơn:
        

*/

#include<bits/stdc++.h>
using namespace std;


//! khai báo Node
struct Node {
    int data;
    Node *next;
};


//! tạo Node
Node * makeNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}


//! Kiểm tra Node có rỗng hay không
bool empty(Node *a) {
    return a == NULL;
}


//! Lấy ra size của danh sách liên kết
int Size(Node *a) {
    int count = 0;
    while(a != NULL) {
        ++count;
        a = a->next; // cho node hiện tại nhảy sang node tiếp theo // (giống như i++)
    }
    return count;
}

//! 1. thêm phần tử vào đầu danh sách:
Node *addHead(Node* &a, int x) {
    Node *temp = makeNode(x);

    if (a == NULL) {
        a = temp; // gán luôn a cho node ta thêm vào( vì a là phần tử đầu danh sách liên kết)
    } else {
        temp->next = a; // liên kết temp với danh sách liên kết
        a = temp; // a nhảy về phần tử đầu tiên.
    }

    // có thể viết ngắn gọn như sau:
    // if (a != NULL) {
    //     temp->next = a;
    // }
    // a = temp;

    return a;
}

//! 2. thêm phần tử vào cuối danh sách:
Node * addTail(Node* &a, int x) {
    Node *temp = makeNode(x);
    if (a == NULL) {
        a = temp;
    } else {
        Node *p = a; // để danh sách không bị biến đổi
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return a;
}


//! 3. thêm một phân tử vào giữa: (chỉ số bắt đâu từ 1)
Node * addMiddle(Node* &a, int x, int pos) {
    int n = Size(a);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri chen khong hop le!" << endl;
    } else if (pos == 1) {
        a = addHead(a, x); 
    } else if (pos == n + 1) {
        a = addTail(a, x);
    } else {
        Node *p = a;
        for(int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        Node *temp = makeNode(x);
        temp->next = p->next;
        p->next = temp;
    }
    return a;
}


//! 4. xóa phần tử ở đầu:
Node * deleteHead(Node* &a) {
    if (a == NULL) return NULL;
    a = a->next;
    return a;
}


//! 5. xóa phần tử ở cuối:
// Node * deleteTail(Node* &a) {
//     if (a == NULL) return NULL;
//     Node *truoc = NULL;
//     Node *sau = a;
//     while(sau->next != NULL) {
//         truoc = sau;
//         sau = sau->next;
//     }
//     if (truoc == NULL) {
//         a = NULL;
//     } else {
//         truoc->next = NULL;
//     }
//     return a;
// }


//* 5. xoá phần tử ở cuối:
Node * deleteTail(Node* &a) {
    if (a == NULL || a->next == NULL)
        return deleteTail(a);
    Node *p = a;
    while(p->next->next != NULL) { // p->next->next != NULL tương tự như sau != NULL
        p = p->next;
    }
    p->next = p->next->next; // truoc->next = NULL;
    return a;
}


//! 6. xóa phần tử ở giữa: (chỉ số bắt đâu từ 1)
// Node * deleteMiddle(Node* &a, int pos) {
//     if (pos <= 0 || pos > size(a)) return NULL;
//     Node *truoc = NULL;
//     Node *sau = a;
//     for(int i = 1; i < pos; i++) {
//         truoc = sau;
//         sau = sau->next;
//     }
//     if (truoc == NULL) {
//         a = a->next;
//     } else {
//         truoc->next = sau->next; // truoc->next = truoc->next->next;
//     }
//     return a;
// }


//! 6. xóa phần tử ở giữa: (chỉ số bắt đâu từ 1)
// Node *deleteMiddle(Node* &a, int pos) {
//     int n = Size(a);
//     if (pos == 0 || a == NULL || a->next == NULL) {
//         a = deleteHead(a);
//     } else {
//         int k = 2; // vì p->next->next nên k = 2
//         Node *p = a;
//         while(p->next->next != NULL && k != pos) {
//             ++k;
//             p = p->next;
//         }
//         if (k != pos) {
//             a = deleteTail(a);
//         } else {
//             p->next = p->next->next;
//         }
//     }
//     return a;
// }

//! 6. xóa phần tử ở giữa: (chỉ số bắt đâu từ 1)
Node *deleteMiddle(Node* &a, int pos) {
    int n = Size(a);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri xoa khong hop le!";
    } else if (pos == 1) {
        a = deleteHead(a);
    } else if (pos == n) {
        a = deleteTail(a);
    } else {
        Node *p = a;
        for(int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        p->next = p->next->next;
    }
    return a;
}


//! 7. sắp xếp theo thứ tự tăng dần trong danh sách liên kết:
Node * sapxep(Node* &a) { // selection sort
    for(Node *p = a; p->next != NULL; p = p->next) {
        Node *min = p;
        for(Node *q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data) {
                min = q;
            }
        }
        int temp = min->data;
        min->data = p->data;
        p->data = temp;
    }
    return a;
}


//! sortList: sắp xếp tăng dần
// Node * SortList(Node* &a) {
//     for(Node *p = a; p != NULL; p = p->next) {
//         for(Node *q = p->next; q != NULL; q = q->next) {
//             if (p->data > q->data) {
//                 int temp = p->data;
//                 p->data = q->data;
//                 q->data = temp;
//             }
//         }
//     }
//     return a;
// }


//! 8. Lấy giá trị ở vị trí bất kỳ(index): 
int getValue(Node* &a, int index) {
    int k = 0;
    Node *p = a;
    while(p->next != NULL && k != index) {
        ++k;
        p = p->next;
    }
    return p->data;
}


//! 9. tìm kiếm này sẽ trả về chỉ số của Node đầu tiên có giá trị bằng với giá trị cần tìm, không tìm thấy, chúng ta trả về -1.
int Search(Node* &a, int value) {
    int position = 0;        
    for(Node *p = a; p != NULL; p = p->next) {
        if(p->data == value) {
            return position;
        }
        ++position;
    }
    return -1;
}


//! 10. Hàm xóa tất cả các Node trong danh sách liên kết:
Node *deleteAllNode(Node* &a, int value) {
    int pos = Search(a, value);
    while(pos != -1) {
        deleteMiddle(a, pos);
        pos = Search(a, value);
    }
    return a;
}


//! 11. reverse linkedlist
Node * reverseSingleLinkedList(Node *a) {
    Node *current = a;
    Node *previous = NULL;
    Node *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}


//! Xóa Node có giá trị giống nhau trong danh sách liên kết:
Node *delete_Node_The_Same_Value(Node *&a) {
    Node *current = a;
    while(current != NULL) {
        Node *p = current->next;
        while(p != NULL && current->data == p->data) {
            p = p->next;
        }

        current->next = p;
        current = p;
        if (p != NULL) {
            p = p->next;
        }
    }
    return a;
}

//! in danh sach:
void in_danh_sach(Node *a) {
    cout << "\n____________________________\n";
    while(a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n____________________________\n";
}


int main() {
    system("cls");
    
    Node *head = NULL; // node đầu tiên bằng NULL

    while(1) {
        cout << "____________Menu________________\n";
        cout << "1. chen phan tu vao dau danh sach\n";
        cout << "2. chen phan tu vao cuoi danh sach\n";
        cout << "3. chen phan tu vao giua danh sach\n";
        cout << "4. xoa phan tu o dau\n";
        cout << "5. xoa phan tu o cuoi\n";
        cout << "6. xoa phan tu o giua\n";
        cout << "7. sap xep phan tu tang dan\n";
        cout << "8. xoa tat ca cac Node trong danh sach\n";
        cout << "9. in ra danh sach lien ket !!!\n";
        cout << "10. Dao nguoc danh sach lien ket don!\n";
        cout << "11. Xoa phan tu giong nhau trong danh sach!\n";
        cout << "0. KET THUC CHUONG TRINH\n";
        cout << "________________________________\n";
        cout << "---Nhap lua chon---: ";
        int lc; cin >> lc;
        if (lc == 1) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            addHead(head, x);
        } else if (lc == 2) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            addTail(head, x);
        } else if (lc == 3) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            addMiddle(head, x, pos);
        } else if (lc == 4) {
            deleteHead(head);
        } else if (lc == 5) {
            deleteTail(head);
        } else if (lc == 6) {
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(head, pos); 
        } else if (lc == 7) {
            sapxep(head);
        } else if (lc == 8){
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteAllNode(head, pos);
        } else if (lc == 9) {
            in_danh_sach(head);
        } else if (lc == 0) {
            break;
        } else if (lc == 10) {
            head = reverseSingleLinkedList(head);
        } else if (lc == 11) {
            delete_Node_The_Same_Value(head);
        }
    }   

    while(head) {
        Node *temp = head;
        temp = temp->next;
        delete temp;
    }

    delete[] head;

    cin.get();
    return 0;
}


