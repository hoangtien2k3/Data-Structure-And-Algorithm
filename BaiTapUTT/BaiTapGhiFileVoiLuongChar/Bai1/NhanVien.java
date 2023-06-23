package BaiTapUTT.BaiTapGhiFileVoiLuongChar.Bai1;

import java.util.Date;

public class NhanVien extends Person {
    private String phongBan;
    private double heSoLuong;
    private int thamNien;
    private double luongCoBan;

    public NhanVien(String hoTen, String ngaySinh, String diaChi, String gioiTinh, String phongBan, double heSoLuong, int thamNien, double luongCoBan) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.phongBan = phongBan;
        this.heSoLuong = heSoLuong;
        this.thamNien = thamNien;
        this.luongCoBan = luongCoBan;
    }

    public String getPhongBan() {
        return phongBan;
    }

    public void setPhongBan(String phongBan) {
        this.phongBan = phongBan;
    }

    public double getHeSoLuong() {
        return heSoLuong;
    }

    public void setHeSoLuong(double heSoLuong) {
        this.heSoLuong = heSoLuong;
    }

    public int getThamNien() {
        return thamNien;
    }

    public void setThamNien(int thamNien) {
        this.thamNien = thamNien;
    }

    public double getLuongCoBan() {
        return luongCoBan;
    }

    public void setLuongCoBan(double luongCoBan) {
        this.luongCoBan = luongCoBan;
    }

    public double tinhLuongThucLinh() {
        return luongCoBan * (1 + thamNien / 100.0) * heSoLuong;
    }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Phòng ban: " + phongBan);
        System.out.println("Hệ số lương: " + heSoLuong);
        System.out.println("Thâm niên: " + thamNien);
        System.out.println("Lương cơ bản: " + luongCoBan);
        System.out.println("Lương thực lĩnh: " + tinhLuongThucLinh());
    }
}