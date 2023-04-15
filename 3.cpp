#include <iostream>
#include <string>
using namespace std;

// Khai báo c?u trúc môn h?c
struct MonHoc {
    string maMon;
    string tenMon;
    int stclt;
    int stcth;
};

// Khai báo c?u trúc di?m thành ph?n
struct DiemThanhPhan {
    string maMon;
    int lanThi;
    float diem;
};

// Khai báo c?u trúc b?ng di?m
struct BangDiem {
    DiemThanhPhan* diemTP; // con tr? d?n m?ng di?m thành ph?n
    int n; // s? lu?ng di?m thành ph?n
};

// Khai báo c?u trúc sinh viên
struct SinhVien {
    string hoTen;
    string phai;
    string ngaySinh;
    string maSV;
    BangDiem bangDiem;
    float diemTB;
};

// Khai báo c?u trúc danh sách sinh viên
struct Node {
    SinhVien data;
    Node* next;
};

typedef Node* List;

// Hàm t?o 1 nút trong danh sách
Node* createNode(SinhVien sv) {
    Node* p = new Node;
    if (p == NULL) {
        return NULL;
    }
    p->data = sv;
    p->next = NULL;
    return p;
}

// Hàm thêm 1 sinh viên vào cu?i danh sách
void addStudent(List& l, SinhVien sv) {
    Node* p = createNode(sv);
    if (l == NULL) {
        l = p;
        return;
    }
    Node* q = l;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
}

// Hàm xu?t thông tin 1 sinh viên
void xuatSinhVien(SinhVien sv) {
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Phai: " << sv.phai << endl;
    cout << "Ngay sinh: " << sv.ngaySinh << endl;
    cout << "Ma sinh vien: " << sv.maSV << endl;
    cout << "Diem trung binh: " << sv.diemTB << endl;
    cout << "Bang diem: " << endl;
    for (int i = 0; i < sv.bangDiem.n; i++) {
        cout << "  Ma mon: " << sv.bangDiem.diemTP[i].maMon << endl;
        cout << "  Lan thi: " << sv.bangDiem.diemTP[i].lanThi << endl;
        cout << "  Diem: " << sv.bangDiem.diemTP[i].diem << endl;
    }
}

// Hàm xu?t danh sách sinh viên
void xuatDanhSachSinhVien(List l) {
    Node* p = l;
    while (p != NULL) {
        xuatSinhVien(p->data);
        p = p->next;
    }
}

// Hàm tìm sinh viên theo mã sinh viên
Node* timSinhVien(List l, string maSV) {	
    Node* p = l;
    while (p != NULL) {
        if (p->data.maSV == maSV) {

		return p;
	}
	p = p->next;
	}
	// không tìm th?y sinh viên
	return NULL;
}

// Hàm nh?p môn h?c
void nhapMonHoc(MonHoc& mh) {
cout << "Nhap ma mon: ";
cin >> mh.maMon;
cout << "Nhap ten mon: ";
cin >> mh.tenMon;
cout << "Nhap so tin chi ly thuyet: ";
cin >> mh.stclt;
cout << "Nhap so tin chi thuc hanh: ";
cin >> mh.stcth;
}

// Hàm xu?t môn h?c
void xuatMonHoc(MonHoc mh) {
cout << "Ma mon: " << mh.maMon << endl;
cout << "Ten mon: " << mh.tenMon << endl;
cout << "So tin chi ly thuyet: " << mh.stclt << endl;
cout << "So tin chi thuc hanh: " << mh.stcth << endl;
}

// Hàm nh?p di?m thành ph?n
void nhapDiemThanhPhan(DiemThanhPhan& dtp) {
cout << "Nhap ma mon: ";
cin >> dtp.maMon;
cout << "Nhap lan thi: ";
cin >> dtp.lanThi;
cout << "Nhap diem: ";
cin >> dtp.diem;
}

// Hàm xu?t di?m thành ph?n
void xuatDiemThanhPhan(DiemThanhPhan dtp) {
cout << "Ma mon: " << dtp.maMon << endl;
cout << "Lan thi: " << dtp.lanThi << endl;
cout << "Diem: " << dtp.diem << endl;
}

// Hàm nh?p b?ng di?m
void nhapBangDiem(BangDiem& bd) {
cout << "Nhap so luong diem thanh phan: ";
cin >> bd.n;
bd.diemTP = new DiemThanhPhan[bd.n];
for (int i = 0; i < bd.n; i++) {
cout << "Nhap diem thanh phan thu " << i + 1 << ":" << endl;
nhapDiemThanhPhan(bd.diemTP[i]);
}
}

// Hàm xu?t b?ng di?m
void xuatBangDiem(BangDiem bd) {
	for (int i = 0; i < bd.n; i++) {
		xuatDiemThanhPhan(bd.diemTP[i]);
	}
}


MonHoc* timMonHoc(Node* pMH, string maMon) {
    while (pMH != NULL) {
        if (pMH->data.maMon == maMon) {
            return &(pMH->data);
        }
        pMH = pMH->pNext;
    }
    return NULL;
}


// Hàm tính di?m trung bình c?a sinh viên
void tinhDiemTrungBinh(SinhVien& sv) {
    float tongDiem = 0;
    int tongSoTinChi = 0;
    for (int i = 0; i < sv.bangDiem.n; i++) {
        MonHoc mh;
        // Tìm thông tin môn h?c trong danh sách môn h?c
        // và tính t?ng s? tín ch?
        Node* pMH = timMonHoc(dsMH, sv.bangDiem.diemTP[i].maMon);
        if (pMH != NULL) {
            mh = pMH->data;
            tongSoTinChi += mh.stclt + mh.stcth;
        }
        // Tính di?m cho t?ng thành ph?n
        float diem = sv.bangDiem.diemTP[i].diem;
        float heSo = 0;
        if (sv.bangDiem.diemTP[i].lanThi == 1) {
            heSo = 0.3;
        } else if (sv.bangDiem.diemTP[i].lanThi == 2) {
            heSo = 0.7;
        }
        tongDiem += diem * heSo;
    }
    sv.diemTB = tongDiem / tongSoTinChi;
}



// Hàm s?p x?p danh sách sinh viên tang d?n theo di?m trung bình
void sapXepDanhSachSinhVien(List& l) {
	Node* p, * q, * end;
	end = NULL;
	while (end != l->next) {
	q = l;
	p = q->next;
	while (p != end) {
	if (tinhDiemTrungBinh(p->data) < tinhDiemTrungBinh(q->data)) {
	// hoán d?i hai sinh viên
	SinhVien temp = p->data;
	p->data = q->data;
	q->data = temp;
	}
	q = p;
	p = p->next;
	}
	end = q;
	}
}





int main() {
    // Khai báo bi?n
    int choice;
    bool flag = true;
    DanhSachSinhVien dsSinhVien;

    while (flag) {
    
    	cout << "===== MENU =====" << endl;
		cout << "1. Nhap mon hoc" << endl;
		cout << "2. Xuat mon hoc" << endl;
		cout << "3. Nhap sinh vien" << endl;
		cout << "4. Xuat sinh vien" << endl;
		cout << "5. Nhap diem thanh phan cua mot sinh vien" << endl;
		cout << "6. Liet ke danh sach cac mon hoc cua mot sinh vien" << endl;
		cout << "7. Xoa sinh vien theo ma sinh vien" << endl;
		cout << "8. Xoa diem thanh phan cua mot sinh vien theo ma mon hoc" << endl;
		cout << "9. Sap xep danh sach sinh vien theo diem trung binh" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "Nhap lua chon: ";
    
        displayMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                nhapMonHoc(dsMonHoc);
                break;
            case 2:
                xuatMonHoc(dsMonHoc);
                break;
            case 3:
                nhapSinhVien(dsSinhVien, dsMonHoc);
                break;
            case 4:
                xuatSinhVien(dsSinhVien, dsMonHoc);
                break;
            case 5:
                xoaSinhVien(dsSinhVien);
                break;
            case 6:
                xoaDiemThi(dsSinhVien);
                break;
            case 7:
                sapXepSinhVienTheoDiemTB(dsSinhVien);
                break;
            case 8:
                if (dsSinhVien.isEmpty()) {
                    cout << "Danh sach sinh vien rong, vui long nhap du lieu truoc!\n";
                } else {
                    string ten;
                    cout << "Nhap ten sinh vien can tim kiem: ";
                    getline(cin, ten);
                    dsSinhVien.timKiem(ten);
                }
                break;
            case 9:
                capNhatSinhVien(dsSinhVien, dsMonHoc);
                break;
            case 10:
                tinhDiemTrungBinh(dsSinhVien);
                break;
            case 0:
                flag = false;
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!\n";
                break;
        }

        // Pause console
        cout << "\nBam phim bat ky de tiep tuc...";
        cin.get();
        cout << endl;
    }

    return 0;
}








