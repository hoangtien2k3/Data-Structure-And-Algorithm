
//! DANH SÁCH LIÊN KẾT VÒNG ĐƠN:
/*
    + Danh sách liên kết vòng(Circular Linked List) là danh sách liên kết có thêm sự 
    kết nối giữa 2 phần tử đầu tiên và phần tử cuối cùng để tạo thành vòng khép kín.

    + Danh sách liên kết vòng khác danh sách liên kết đơn và danh sách liên kết đôi ở chỗ
    Phần tử đầu và phần tử cuối của danh sách liên kết vòng liên kết với nhau tạo thành một 
    vòng tròn kép kín.


*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

void init(List &l) {
    l.head = l.tail = NULL;
}

Node *makeNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = temp;
    return temp;
}

//! lấy số lượng Node:
int Size(List l) {
    Node *current = l.head;
    int i = 1;
    if (l.head == NULL) {
        return 0;
    } else {
        current = current->next;
        while(current != l.head) {
            i++;
            current = current->next;
        }
    }
    return i;
}

//! add vao dau:
void addHead(List &l, int value) {
    Node *temp = makeNode(value);
    if (l.head == NULL) {
        l.head = l.tail = temp;
        l.tail->next = l.head;
    } else {
        temp->next = l.head;
        l.head = temp;
        l.tail->next = l.head;
    }
}

//! add vao cuoi:
void addTail(List &l, int value) {
    Node *temp = makeNode(value);
    if (l.head == NULL) {
        l.head = l.tail = temp;
        l.tail->next = l.head;
    } else {
        l.tail->next = temp;
        l.tail = temp;
        l.tail->next = l.head;
    }
}

//! add vao vi tri bat ky:
void addMiddle(List &l, int value, int pos) {
    int size = Size(l);
    if (pos < 1 || pos > size + 1) {
        cout << "Vi tri chen khong hop le!";
    } else {
        if (l.head == NULL) addHead(l, value);
        Node *temp = makeNode(value);
        Node *p = l.head;
        for(int i=1; i<pos - 1; i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}


//! xóa phần tử đầu:
void deleteHead(List &l) {
    if (l.head == NULL) {
        return;
    } else {
        l.head = l.head->next;
        l.tail->next = l.head;
    }
}

//! xóa phần tử cuối:
void deleteTail(List &l) {
    if (l.head == NULL) {
        return;
    } else {
        Node *p = l.head;
        while(p->next->next != l.head) {
            p = p->next;
        }
        p->next = l.head;
    }
}


//! xóa theo vị trí bất kỳ:
void deleteMiddle(List &l, int pos) {
    int size = Size(l);
    Node *p = l.head;
    if (pos < 1 || pos > size) {
        cout << "Vi tri xoa khong hop le!";
    } else if (size == 1) {
        p = NULL;
        
    } else {
        Node *p = l.head;
        for(int i = 1; i < pos - 1; i++) {
            p = p->next;
        }   
        p->next = p->next->next;
    }
}



//! in danh sach:
void in_danh_sach(List l) {
    cout << "\n____________________\n";
    Node *p = l.head;
    if (l.head != NULL) {
        do {
            cout << p->data << " ";
            p = p->next;
        } while(p != l.head);
    }
    cout << "\n____________________\n";
}


int main() {
    List l;
    init(l);

    while(1) {
        cout << "_________Menu______________\n";
        cout << "1. them vao dau danh sach\n";
        cout << "2. them vao cuoi danh sach\n";
        cout << "3. them vao giua danh sach\n";
        cout << "4. xoa phan tu dau danh sach\n";
        cout << "5. xoa phan tu cuoi danh sach\n";
        cout << "6. xoa phan ti vi tri bat ky\n";
        cout << "7. xuat danh sach lien ket\n";
        cout << "____________________________\n";
        cout << "Nhap vao lua chon: ";
        int x; cin >> x;
        if (x == 1) {
            int value; cout << "Nhap gia tri chen: ";cin >> value;
            addHead(l, value);
        } else if (x == 2) {
            int value; cout << "Nhap gia tri chen: ";cin >> value;
            addTail(l, value);
        } else if (x == 3) {
            int value; cout << "Nhap gia tri chen: ";cin >> value;
            int pos; cout << "Nhap vi tri chen: "; cin >> pos;
            addMiddle(l, value, pos);
        } else if (x == 4) {
            deleteHead(l);
        } else if (x == 5) {
            deleteTail(l);
        } else if (x == 6) {
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(l, pos);
        } else if (x == 7) {
            in_danh_sach(l);
        }
    }

    return 0;
}


