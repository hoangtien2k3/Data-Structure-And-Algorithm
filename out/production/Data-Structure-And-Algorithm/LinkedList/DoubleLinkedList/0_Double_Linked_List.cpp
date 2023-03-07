
// Double Linked List: Danh sách liên kết đôi C++

/*
    + Danh sách liên kết đôi (Doubly Linked List) là một dạng mở rộng của danh sách liên kết đơn. 
    Trong danh sách liên kết đôi cũng bao gồm nhiều các Node (nút) và điều đặc biệt ở danh sách 
    liên kết đôi là các Node liên kết với nhau với 2 con trỏ và theo hai chiều trước – sau. 


    - Một Node (hay phần tử) trong danh sách liên kết đôi bao gồm 3 thành phần chính
        + Data: lưu trữ dữ liệu của node
        + Next: Lưu trữ địa chỉ của node (hay phần tử) đừng sau. 
        + Previous: Lưu trữ địa chỉ của node (hay phần tử) đứng trước.


    + Thành phần pHead sẽ được dùng để lưu trữ địa chỉ phần tử đầu danh sách: NODE* pHead;
    + Thành phần pTail lưu địa chỉ phần tử cuối danh sách: NODE* pTail;

*/

#include<bits/stdc++.h>
using namespace std;

// hàm khai báo Node
struct Node {
    int data;
    Node *next;
    Node *previous;
};

struct List {
    Node *head;
    Node *tail;
};

void init(List &l) {
    l.head = l.tail = NULL;
}

bool empty(List l) {
    return l.head == NULL;
}

int Size(List l) {
    int count = 0;
    while(l.head != NULL) {
        ++count;
        l.head = l.head->next;
    }
    return count;
}

// Hàm tạo Node trong danh sách liên kết đơn
Node *makeNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

//! chen phan tu vao dau:
void addHead(List &l, int value) {
    Node *temp = makeNode(value);
    if (l.head == NULL) {
        l.head = l.tail = temp;
    } else {
        temp->next = l.head;
        l.head->previous = temp;
        l.head = temp;
    }
}

//! chen phan tu vao cuoi:
void addTail(List &l, int value) {
    Node *temp = makeNode(value);
    if (l.head == NULL) {
        l.head = l.tail = temp;
    } else {
        l.tail->next = temp;
        temp->previous = l.tail;
        l.tail = temp;
    }
}

//! chen phan tu vao giua:
void addMiddle(List &l, int value, int pos) {
    Node *p = l.head;
    Node *temp = makeNode(value);
    int size = Size(l);
    if (pos <= 0 || pos > size + 1) {
        cout << "Vi tri chen ko hop le!";
    } else if (pos == 1) {
        addHead(l, value);
    } else if (pos == size + 1) {
        addTail(l, value);
    } else {
        for(int i=1; i < pos-1; i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next->previous = temp;

        p->next = temp;
        temp->previous = p;        
    }
}

//! xóa phần tử đầu:
void deleteHead(List &l) {
    if (l.head == NULL) {
        return;
    } else {
        l.head = l.head->next;
        l.head->previous = NULL;
    }
}

//! xóa phần tử cuối:
void deleteTail(List &l) {
    if (l.head == NULL) {
        return;
    } else {
        l.tail = l.tail->previous;
        l.tail->next = NULL;
    }
}

//! xóa phần tử ở giữa:
void deleteMiddle(List &l, int pos) {
    int size = Size(l);
    if (pos < 0 || pos >= size) {
        return;
    } else if (pos == 0) {
        deleteHead(l);
    } else if (pos == size - 1) {
        deleteTail(l);
    } else {
        Node *p = l.head;
        for(int i=1; i<=pos; i++) {
            p = p->next;
        }
        p->previous->next = p->next;
        p->next->previous = p->previous;
    }
}

//! sắp xếp các phần tử tăng dân:
void SortDoubleLinkedList(List &l) {
    for(Node *p = l.head; p != NULL; p = p->next) {
        for(Node *q = p; q != NULL; q = q->next) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp; 
            }
        }
    }
}


//! đảo ngược danh sách liên kết đôi.
void reverseDoubleLinkedList(List &l) {
    Node *ptr1 = l.head;
    Node *ptr2 = l.head->next;

    ptr1->next = NULL;
    ptr1->previous = ptr2;

    while(ptr2 != NULL) {
        ptr2->previous = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->previous;
    }

    l.head = ptr1;
}


//! in danh sach:
void in_danh_sach(List l) {
    cout << "\n____________________________\n";
    Node *p = l.head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n____________________________\n";
}

int main() {
    List l;
    init(l);

    while(1) {
        cout << "\n___________MENU_____________\n";
        cout << "1. chen phan tu vao dau danh sach\n";
        cout << "2. chen phan tu vao cuoi danh sach\n";
        cout << "3. chen phan tu vao giua danh sach\n";
        cout << "4. xoa phan tu o dau danh sach\n";
        cout << "5. xoa phan tu o cuoi danh sach\n";
        cout << "6. xoa phan tu o giua danh sach\n";
        cout << "7. sap xep phan tu tang dan\n";
        cout << "8. xuat danh sach lien ket\n";
        cout << "9. dao nguoc danh sach lien ket doi\n";
        cout << "____________________________\n";
        cout << "\n---Nhap vao lua chon---: ";
        int lc; cin >> lc;
        if (lc == 1) {
            int value; cout << "Nhap gia tri can chen: "; cin >> value;
            addHead(l, value);
        } else if (lc == 2) {
            int value; cout << "Nhap gia tri can chen: "; cin >> value;
            addTail(l, value);
        } else if (lc == 3) {
            int value; cout << "Nhap gia tri can chen: "; cin >> value;
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            addMiddle(l, value, pos);
        } else if (lc == 4) {
            deleteHead(l);
        } else if (lc == 5) {
            deleteTail(l);
        } else if (lc == 6) {
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(l, pos);
        } else if (lc == 7) {
            SortDoubleLinkedList(l);
        } else if (lc == 8) {
            in_danh_sach(l);
        } else if (lc == 9) {
            reverseDoubleLinkedList(l);
        }
    }

    return 0;
}




