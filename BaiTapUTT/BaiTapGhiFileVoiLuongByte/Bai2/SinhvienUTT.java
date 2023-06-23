package BaiTapUTT.BaiTapGhiFileVoiLuongByte.Bai2;

import java.io.Serializable;

class SinhvienUTT extends Sinhvien implements Serializable {
    private String donVi;
    private double luong;

    public SinhvienUTT(String maSinhVien, String hoTen, String ngaySinh, String gioiTinh, double diemTrungBinh, String donVi, double luong) {
        super(maSinhVien, hoTen, ngaySinh, gioiTinh, diemTrungBinh);
        this.donVi = donVi;
        this.luong = luong;
    }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Đơn vị: " + donVi);
        System.out.println("Lương: " + luong);
    }
}