package BaiTapUTT.BaiTapGhiFileVoiLuongByte.Bai2;


import java.io.Serializable;

class Sinhvien implements Serializable {
    private String maSinhVien;
    private String hoTen;
    private String ngaySinh;
    private String gioiTinh;
    private double diemTrungBinh;

    public Sinhvien(String maSinhVien, String hoTen, String ngaySinh, String gioiTinh, double diemTrungBinh) {
        this.maSinhVien = maSinhVien;
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.gioiTinh = gioiTinh;
        this.diemTrungBinh = diemTrungBinh;
    }

    public void hienThiThongTin() {
        System.out.println("Mã sinh viên: " + maSinhVien);
        System.out.println("Họ tên: " + hoTen);
        System.out.println("Ngày sinh: " + ngaySinh);
        System.out.println("Giới tính: " + gioiTinh);
        System.out.println("Điểm trung bình: " + diemTrungBinh);
    }
}
