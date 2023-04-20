#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Khai b�o c�c struct d? luu tr? th�ng tin
struct LopHoc {
    string maLop;
    string tenHocPhan;
    string tenGiaoVien;
    LopHoc* next;
};

struct Tre {
    string maTre;
    string hoLot;
    string ten;
    string ngaySinh;
    string hoTenPhuHuynh;
    string soDienThoai;
    string moiQuanHe;
    string maLop;
    Tre* next;
};

// H�m d?c danh s�ch l?p h?c t? file
LopHoc* docDanhSachLopHoc() {
    LopHoc* dsLopHoc = NULL;
    ifstream file("lophoc.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            LopHoc* lopHoc = new LopHoc;
            file >> lopHoc->maLop >> lopHoc->tenHocPhan >> lopHoc->tenGiaoVien;
            lopHoc->next = dsLopHoc;
            dsLopHoc = lopHoc;
        }
        file.close();
    }
    return dsLopHoc;
}

// H�m d?c danh s�ch tr? t? file
Tre* docDanhSachTre() {
    Tre* dsTre = NULL;
    ifstream file("tre.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            Tre* tre = new Tre;
            file >> tre->maTre >> tre->hoLot >> tre->ten >> tre->ngaySinh >> tre->hoTenPhuHuynh >> tre->soDienThoai >> tre->moiQuanHe >> tre->maLop;
            tre->next = dsTre;
            dsTre = tre;
        }
        file.close();
    }
    return dsTre;
}


// ghi danh sach lop hoc
void ghiDanhSachLopHocTre(LopHoc* dsLopHoc) {
	ofstream file("lophoc.txt");
	if (file.is_open()) {
		while (dsLopHoc != NULL) {
			file << dsLopHoc->maLop << ", " << dsLopHoc->tenHocPhan << ", " << dsLopHoc->tenGiaoVien << endl; 
			dsLopHoc = dsLopHoc->next;
		}
		file.close();
	}
	else {
		cout << "Khong mo duoc file de ghi danh sach lophoc.txt" << endl;
	}
}


// H�m ghi danh s�ch tr? v�o file
void ghiDanhSachTre(Tre* dsTre) {
	ofstream file("tre.txt");
	if (file.is_open()) {
		while (dsTre != NULL) {
			file << dsTre->maTre << ", " << dsTre->hoLot << ", " << dsTre->ten << ", " << dsTre->ngaySinh << ", " << dsTre->hoTenPhuHuynh << ", " << dsTre->soDienThoai << ", " << dsTre->moiQuanHe << ", " << dsTre->maLop << endl;
			dsTre = dsTre->next;
		}
		file.close();
	}
	else {
		cout << "Khong mo duoc file de ghi danh sach tre.txt" << endl;
	}
}


// them thong tin tre (file tre.txt)
void ThemThongTinTre(Tre* treMoi) {
	cout << "+ Nhap ma tre: ";
	getline(cin, treMoi->maTre);
	cout << "+ Nhap ho va ten lot: ";
	getline(cin, treMoi->hoLot);
	cout << "+ Nhap ten: ";
	getline(cin, treMoi->ten);
	cout << "+ Nhap ngay sinh: ";
	getline(cin, treMoi->ngaySinh);
	cout << "+ Nhap ho ten phu huynh: ";
	getline(cin, treMoi->hoTenPhuHuynh);
	cout << "+ Nhap so dien thoai: ";
	getline(cin, treMoi->soDienThoai);
	cout << "+ Nhap moi quan he: ";
	getline(cin, treMoi->moiQuanHe);
	cout << "+ Nhap ma lop: ";
	getline(cin, treMoi->maLop);
}


// them thong tin lophoc (file lophoc.txt)
void ThemThongLopHoc(LopHoc* lopHocMoi) {
	cout << "+ Nhap vao MaLop: ";
	getline(cin, lopHocMoi->maLop);
	cout << "+ Nhap vao Ten Hoc Phan: ";
	getline(cin, lopHocMoi->tenHocPhan);
	cout << "+ Nhap vao Ho Ten Giao Vien Phu Trach: ";
	getline(cin, lopHocMoi->tenGiaoVien);
}


// H�m th�m m?t tr? v�o danh s�ch tr?
void themLopHocTre(LopHoc* &dsLopHoc, LopHoc* lopHocMoi) {
    lopHocMoi->next = dsLopHoc;
    dsLopHoc = lopHocMoi;
}


// H�m th�m m?t tr? v�o danh s�ch tr?
void themTre(Tre* &dsTre, Tre* treMoi) {
    treMoi->next = dsTre;
    dsTre = treMoi;
}


// H�m t�m tr? theo ti�u ch� t�m ki?m: h? t�n gi�o vi�n, m� tr? ho?c t�n l?p
void timKiemTre(Tre* dsTre, string tieuChi, string giaTri) {
    bool timThay = false;
    while (dsTre != NULL) {
        if (tieuChi == "hoTenGiaoVien") {
            if (dsTre->maLop != "") {
                LopHoc* lopHoc = docDanhSachLopHoc();
                while (lopHoc != NULL) {
                    if (lopHoc->maLop == dsTre->maLop && lopHoc->tenGiaoVien == giaTri) {
						cout << "Ma tre: " << dsTre->maTre << endl;
						cout << "Ho v� t�n: " << dsTre->hoLot << " " << dsTre->ten << endl;
						cout << "Ng�y sinh: " << dsTre->ngaySinh << endl;
						cout << "Ho t�n phu huynh: " << dsTre->hoTenPhuHuynh << endl;
						cout << "So dien thoai: " << dsTre->soDienThoai << endl;
						cout << "Moi quan he: " << dsTre->moiQuanHe << endl;
						cout << "M� lop: " << dsTre->maLop << endl;
						cout << "-------------------------" << endl;
						timThay = true;
					}
					lopHoc = lopHoc->next;
				}
			}
		} else if (tieuChi == "maTre") {
			if (dsTre->maTre == giaTri) {
				cout << "M� tre: " << dsTre->maTre << endl;
				cout << "Ho v� t�n: " << dsTre->hoLot << " " << dsTre->ten << endl;
				cout << "Ng�y sinh: " << dsTre->ngaySinh << endl;
				cout << "Ho t�n phu huynh: " << dsTre->hoTenPhuHuynh << endl;
				cout << "So dien thoai: " << dsTre->soDienThoai << endl;
				cout << "Moi quan he: " << dsTre->moiQuanHe << endl;
				cout << "M� lop: " << dsTre->maLop << endl;
				cout << "-------------------------" << endl;
				timThay = true;
			}
		} else if (tieuChi == "tenLop") {
			if (dsTre->maLop != "") {
				LopHoc* lopHoc = docDanhSachLopHoc();
				while (lopHoc != NULL) {
					if (lopHoc->maLop == dsTre->maLop && lopHoc->tenHocPhan == giaTri) {
						cout << "M� tre: " << dsTre->maTre << endl;
						cout << "Ho v� t�n: " << dsTre->hoLot << " " << dsTre->ten << endl;
						cout << "Ng�y sinh: " << dsTre->ngaySinh << endl;
						cout << "Ho t�n phu huynh: " << dsTre->hoTenPhuHuynh << endl;
						cout << "So dien thoai: " << dsTre->soDienThoai << endl;
						cout << "Moi quan he: " << dsTre->moiQuanHe << endl;
						cout << "M� lop: " << dsTre->maLop << endl;
						cout << "-------------------------" << endl;
						timThay = true;
					}
					lopHoc = lopHoc->next;
				}
			}
		}
		dsTre = dsTre->next;
	}
	
	if (!timThay) {
	    cout << "Kh�ng t�m thay tre thoa m�n ti�u ch� t�m thay." << endl;
	}
}


// H�m t�m l?p h?c c� s? tr? tham gia nhi?u nh?t
string timLopHocCoNhieuTreNhat(LopHoc* dsLopHoc, Tre* dsTre) {
    int maxSoTre = 0; // Bi?n luu s? tr? nhi?u nh?t
    string maLopHocMaxSoTre; // Bi?n luu m� l?p h?c c� s? tr? nhi?u nh?t
    LopHoc* lopHoc = dsLopHoc;
    while (lopHoc != NULL) {
        int soTre = 0; // Bi?n luu s? tr? tham gia trong l?p h?c hi?n t?i
        Tre* tre = dsTre;
        while (tre != NULL) {
            if (tre->maLop == lopHoc->maLop) {
                soTre++;
            }
            tre = tre->next;
        }
        if (soTre > maxSoTre) {
            maxSoTre = soTre;
            maLopHocMaxSoTre = lopHoc->maLop;
        }
        lopHoc = lopHoc->next;
    }
    return maLopHocMaxSoTre;
}


// H�m s?p x?p danh s�ch tr? theo t�n l?p h?c v� t�n tr?
void sapXepDanhSachTre(Tre* &dsTre) {
    Tre* p, * q, * end;
    for (end = NULL; end != dsTre->next; end = p) {
        for (p = dsTre; p->next != end; p = p->next) {
            q = p->next;
            if (p->maLop > q->maLop || (p->maLop == q->maLop && p->hoLot + p->ten > q->hoLot + q->ten)) {
                // Swap th�ng tin gi?a p v� q
                string maTre = p->maTre;
                string hoLot = p->hoLot;
                string ten = p->ten;
                string ngaySinh = p->ngaySinh;
                string hoTenPhuHuynh = p->hoTenPhuHuynh;
                string soDienThoai = p->soDienThoai;
                string moiQuanHe = p->moiQuanHe;
                string maLop = p->maLop;

                p->maTre = q->maTre;
                p->hoLot = q->hoLot;
                p->ten = q->ten;
                p->ngaySinh = q->ngaySinh;
                p->hoTenPhuHuynh = q->hoTenPhuHuynh;
                p->soDienThoai = q->soDienThoai;
                p->moiQuanHe = q->moiQuanHe;
                p->maLop = q->maLop;

                q->maTre = maTre;
                q->hoLot = hoLot;
                q->ten = ten;
                q->ngaySinh = ngaySinh;
                q->hoTenPhuHuynh = hoTenPhuHuynh;
                q->soDienThoai = soDienThoai;
                q->moiQuanHe = moiQuanHe;
                q->maLop = maLop;
            }
        }
    }
}


// H�m in ra th�ng tin c?a tr? theo l?p do gi�o vi�n c� h? Tr?n gi?ng d?y
void inThongTinTreTheoLopGiangDay(Tre* dsTre, LopHoc* dsLopHoc, string hoTenGiaoVien) {
    LopHoc* lopHoc = dsLopHoc;
    int i = 0;
    while (lopHoc != NULL) {
        if (lopHoc->tenGiaoVien == hoTenGiaoVien) {
            Tre* tre = dsTre;
            while (tre != NULL) {
                if (tre->maLop == lopHoc->maLop) {
                    cout << "Ma tre: " << tre->maTre << endl;
                    cout << "Ho v� ten: " << tre->hoLot << " " << tre->ten << endl;
                    cout << "Ngay sinh: " << tre->ngaySinh << endl;
                    cout << "Ho t�n phu huynh: " << tre->hoTenPhuHuynh << endl;
                    cout << "So dien thoai: " << tre->soDienThoai << endl;
                    cout << "Moi quan he: " << tre->moiQuanHe << endl;
                    cout << "Ma lop: " << tre->maLop << endl;
                    cout << "-------------------------" << endl;
                }
                tre = tre->next;
            }
        }
        lopHoc = lopHoc->next;
        i++;
    }
    if (i == 0) {
    	cout << "Khong Tim Thay Giao Vien Co Ho Tran !!!" << endl;
	}
}


// H�m in ra th�ng tin c?a tr? c� ng�y sinh nh?t trong th�ng 12
void inThongTinTreSinhNhatThang12(Tre* dsTre) {
    bool timThay = false;
    while (dsTre != NULL) {
        if (dsTre->ngaySinh.substr(3, 2) == "12") {
            cout << "Ma tre: " << dsTre->maTre << endl;
            cout << "Ho v� ten: " << dsTre->hoLot << " " << dsTre->ten << endl;
            cout << "Ngay sinh: " << dsTre->ngaySinh << endl;
            cout << "Ho t�n phu huynh: " << dsTre->hoTenPhuHuynh << endl;
            cout << "So dien thoai: " << dsTre->soDienThoai << endl;
            cout << "Moi quan he: " << dsTre->moiQuanHe << endl;
            cout << "M� lop: " << dsTre->maLop << endl;
            cout << "-------------------------" << endl;
            timThay = true;
        }
        dsTre = dsTre->next;
    }
    if (!timThay) {
        cout << "Khong co tre nao sinh nhat trong thang 12." << endl;
    }
}


// H�m c?p nh?t th�ng tin c?a tr? d?a tr�n m� tr? v� luu v�o file log.txt
void capNhatThongTinTre(Tre* dsTre, string maTre) {
    Tre* tre = dsTre;
    bool timThay = false;
    while (tre != NULL) {
        if (tre->maTre == maTre) {
            cout << "Th�ng tin tre truoc khi cap nhat:" << endl;
            cout << "Ma tre: " << tre->maTre << endl;
            cout << "Ho v� ten: " << tre->hoLot << " " << tre->ten << endl;
            cout << "Ng�y sinh: " << tre->ngaySinh << endl;
            cout << "Ho t�n phu huynh: " << tre->hoTenPhuHuynh << endl;
            cout << "So dien thoai: " << tre->soDienThoai << endl;
            cout << "Moi quan he: " << tre->moiQuanHe << endl;
            cout << "Ma lop: " << tre->maLop << endl;
            cout << "-------------------------" << endl;

            cout << "Nhap th�ng tin moi cua tre (nhan Enter de bo qua):" << endl;
            cout << "Ho va ten: ";
            getline(cin, tre->hoLot);
            cout << "Ten: ";
            getline(cin, tre->ten);
            cout << "Ngay sinh (dd/MM/yyyy): ";
            getline(cin, tre->ngaySinh);
            cout << "Ho ten phu huynh: ";
            getline(cin, tre->hoTenPhuHuynh);
            cout << "So dien thoai: ";
            getline(cin, tre->soDienThoai);
            cout << "Moi quan he: ";
            getline(cin, tre->moiQuanHe);
            cout << "Ma lop: ";
            getline(cin, tre->maLop);

            // Ghi th�ng tin c?p nh?t v�o file log.txt
            ofstream fileLog("log.txt", ios::app);
            if (fileLog.is_open()) {
                fileLog << "Cap nhat thong tin tre:" << endl;
                fileLog << "Ma tre: " << tre->maTre << endl;
                fileLog << "Ho va ten: " << tre->hoLot << " " << tre->ten << endl;
                fileLog << "Ngay sinh: " << tre->ngaySinh << endl;
                fileLog << "Ho ten phu huynh: " << tre->hoTenPhuHuynh << endl;
                fileLog << "So dien thoai: " << tre->soDienThoai << endl;
                fileLog << "Moi quan he: " << tre->moiQuanHe << endl;
                fileLog << "Ma lop: " << tre->maLop << endl;
                fileLog << "-------------------------" << endl;
                fileLog.close();
            }
            cout << "Th�ng tin tre sau khi cap nhat:" << endl;
            cout << "Ma tre: " << tre->maTre << endl;
            cout << "Ho v� t�n: " << tre->hoLot << " " << tre->ten << endl;
            cout << "Ng�y sinh: " << tre->ngaySinh << endl;
            cout << "Ho ten phu huynh: " << tre->hoTenPhuHuynh << endl;
            cout << "So dien thoai: " << tre->soDienThoai << endl;
            cout << "Moi quan he: " << tre->moiQuanHe << endl;
            cout << "Ma lop: " << tre->maLop << endl;
            cout << "-------------------------" << endl;

            timThay = true;
            break;
        }
        tre = tre->next;
    }

    if (!timThay) {
        cout << "Khong tim thay thong tin tre voi ma tre: " << maTre << endl;
    }
}


// xoa danh sach lophoc
void xoaDanhSachLopHoc(LopHoc* &dsLopHoc) {
	while (dsLopHoc != NULL) {
		LopHoc* temp = dsLopHoc;
		dsLopHoc = dsLopHoc->next;
		delete temp;
	}
}

// H�m x�a danh s�ch tr?
void xoaDanhSachTre(Tre* &dsTre) {
	while (dsTre != NULL) {
		Tre* temp = dsTre;
		dsTre = dsTre->next;
		delete temp;
	}
}


// H�m ch�nh
int main() {
	LopHoc* dsLopHoc = docDanhSachLopHoc();
	Tre* dsTre = docDanhSachTre();

	while (true) {
		cout << "\n\n==================== QUAN LY TRE EM MAM NON ==================" << endl;
		cout << " 1. Them Tre" << endl;
		cout << " 2. Ghi danh sach tre vao file" << endl;
		cout << " 3. Tim kiem tre" << endl;
		cout << " 4. Lop Hoc Co So Luong Tre Hoc Nhieu Nhat" << endl;
		cout << " 5. Sap Xep Danh Sach Tre ... tang dan" << endl;
		cout << " 6. Tim Kiem Thong Tin Giao Vien Co Ho 'Tran'" << endl;
		cout << " 7. In ra thong tin cua tre co ngay sinh nhat thang 12" << endl;
		cout << " 8. Cap Nhat Thong Tin Tre Voi Ma Tre !!!" << endl;
		cout << " 9. Xoa danh sach tre" << endl;
		cout << " 10. Thoat" << endl;
		cout << "==============================================================" << endl;
		cout << "<=> Nhap lua chon cua ban: ";
		int luaChon;
		cin >> luaChon;
	
		switch (luaChon) {
			case 1: {
				// them thong tin Tre
				Tre* treMoi = new Tre;
				cin.ignore();
				ThemThongTinTre(treMoi);
				themTre(dsTre, treMoi);
							
				// them thong tin LopHoc
				cout << "- Nhap tiep vao thong tin Lop Hoc Tre !!!" << endl;
				LopHoc* lopHocMoi = new LopHoc;
				ThemThongLopHoc(lopHocMoi);
				themLopHocTre(dsLopHoc, lopHocMoi);

				cout << "=> Them Thong Tin Tre Thanh Cong! <=" << endl;
				break;
			} 
			case 2: {
				ghiDanhSachTre(dsTre);
				ghiDanhSachLopHocTre(dsLopHoc);
				cout << "Da ghi danh sach tre, lophoc vao file tre.txt va file lophoc.txt" << endl;
				break;
			}
			case 3: {
				string tieuChi, giaTri;
                cin.ignore(); // X�a b? d?m nh?p d? nh?p chu?i
                cout << "Nhap tieu chi tim kiem (hoTenGiaoVien, maTre, tenLop): ";
                getline(cin, tieuChi);
                cout << "Nhap gia tri tim kiem: ";
                getline(cin, giaTri);

                timKiemTre(dsTre, tieuChi, giaTri); // T�m ki?m tr? theo ti�u ch� v� gi� tr? nh?p v�o
                break;
			}
			case 4: {
				LopHoc* dsLopHoc = docDanhSachLopHoc();
			    Tre* dsTre = docDanhSachTre();
			    string maLopHocMaxSoTre = timLopHocCoNhieuTreNhat(dsLopHoc, dsTre);
			    cout << "Ma lop hoc c� so tre tham gia nhieu nhat: " << maLopHocMaxSoTre << endl;
				break;
			}
			case 5: {
				Tre* dsTre = docDanhSachTre();
				sapXepDanhSachTre(dsTre);
				cout << "Sap Xep Danh Sach Tre Thanh Cong !!!";
				break;
			}
			case 6: {
				LopHoc* dsLopHoc = docDanhSachLopHoc();
			    Tre* dsTre = docDanhSachTre();
				inThongTinTreTheoLopGiangDay(dsTre, dsLopHoc, dsLopHoc->tenGiaoVien);
				break;
			}
			case 7: {
				Tre* dsTre = docDanhSachTre();
				inThongTinTreSinhNhatThang12(dsTre);
				break;
			}
			case 8: {
				Tre* dsTre = docDanhSachTre();
				string maTre;
				cout << "Nhap vao Ma Tre: ";
				getline(cin, maTre);
				capNhatThongTinTre(dsTre, maTre);
				break;
			}
			case 9: {
				xoaDanhSachTre(dsTre);
				cout << "Da xoa danh sach tre." << endl;
				break;
			}
			case 10: {
				xoaDanhSachTre(dsTre);
				xoaDanhSachLopHoc(dsLopHoc);
				cout << "Cam on ban da su dung chuong trinh!" << endl;
				return 0;
			}
			default: {
				cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
				break;
			}
		}
	}
	
	return 0;
}
