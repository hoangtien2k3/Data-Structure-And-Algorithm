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
        for(int i=1; i <= pos - 1; i++) {
            p = p->next;
        }
        p->previous->next = p->next;
        p->next->previous = p->previous;
    }
}

//! in danh sach:
void in_danh_sach(List l) {
    cout << "\n____________________________\n";
    Node *p = l.head;
    while(p != NULL) {
        cout << p->data << "   ";
        p = p->next;
    }
    cout << "\n____________________________\n";
}

bool check_so_hoan_hao(int n) {
    int sum = 0;    //khai bao biem sum
    for(int i=1;i<=n/2;i++){
        if(n%i==0) 
            sum+=i;
    }
    if(sum==n) 
        return true;    // tra ve true
    return false;
}

void dem_so_luong_So_Hoan_Hao(List l) {
    int count = 0;
    int index = 0;
    Node *p = l.head;
    cout << "\nVi Tri Cac So Hoan Hao: "; 
    while(p != NULL) {
        if (check_so_hoan_hao(p->data)) {
            count++;
            cout << index << "  ";
        }
        p = p->next;
        index++;
    }
    cout << "\nSo Luong Cac So Hoan Hao: " << count;
}

void xoa_so_0_trong_danh_sach(List l) {
    cout << "\nXoa Tat Ca Cac So 0 Trong Danh Sach: " << endl;
    Node *p = l.head;
    int index = 1;
    while(p != NULL) {
        if (p->data == 0) {
            deleteMiddle(l, index);
        }
        p = p->next;
        index++;
    }

}

void dem_so_bang_k(List l) {
    int k; cout << "\nNhap vao so K: "; cin >> k;
    int count = 0;
    Node *p = l.head;
    int index = 1;
    while(p != NULL) {
        if (p->data == k) {
            count++;
        }
        p = p->next;
    }
    cout << "\nSo Luong So Bang K: " << count;
    if (count % 2 == 0) {
        cout << "\nLa So Chan !" << endl;
    } else {
        cout << "\nLa So Le !" << endl;
    }
}

void trung_binh_cong_so_le_duong(List l) {
    int count = 0;
    double sum = 0;
    Node *p = l.head;
    int index = 1;
    while(p != NULL) {
        if (((p->data) % 2 == 1) && ((p->data) > 0)) {
            sum = sum + (p->data);
            ++count;
        }
        p = p->next;
    }

    double result = (double)sum/count;
    cout << "\nTBC Cac So Le Duong: " << result << endl;
}

int main() {
    system("cls");
    List l;
    init(l);

    while(1) {
        cout << endl << endl;
        cout << "\n___________MENU_____________\n";
        cout << "1. chen phan tu vao cuoi danh sach\n";
        cout << "2. so luong va vi tri so hoan hao trong ds\n";
        cout << "3. xoa tat ca cac so 0 trong danh sach\n";
        cout << "4. nhap k, so luong so bang k la chan hay le\n";
        cout << "5. trung binh cong cac so le duong trong danh sach\n";
        cout << "6. xuat danh sach lien ket\n";
        cout << "____________________________\n";
        cout << "\n---Nhap vao lua chon---: ";
        int lc; cin >> lc;
        if (lc == 1) {
            string str; cout << "Nhap vao gia tri can chen: "; cin >> str;
            int index;
            for(int i = 0; i < str.length(); i++) 
                if (str[i] == '#') 
                    break;
            
            int value = stoi(str);
            addTail(l, value);
        } else if (lc == 2) {
            dem_so_luong_So_Hoan_Hao(l);
        } else if (lc == 3) {
            xoa_so_0_trong_danh_sach(l);
        } else if (lc == 4) {
            dem_so_bang_k(l);
        } else if (lc == 5) {
            trung_binh_cong_so_le_duong(l);
        } else if (lc == 6) {
            in_danh_sach(l);
        }
    }

    return 0;
}




