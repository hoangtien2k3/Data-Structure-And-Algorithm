package BaiTapUTT.BaiTapGhiFileVoiLuongByte.Bai2;

import java.io.Serializable;

class SinhvienHTTT extends Sinhvien implements Serializable {
    private double hocPhi;

    public SinhvienHTTT(String maSinhVien, String hoTen, String ngaySinh, String gioiTinh, double diemTrungBinh, double hocPhi) {
        super(maSinhVien, hoTen, ngaySinh, gioiTinh, diemTrungBinh);
        this.hocPhi = hocPhi;
    }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Học phí: " + hocPhi);
    }
}