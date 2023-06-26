/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de1;

/**
 *
 * @author hoangtien2k3
 */
// phần của bài 1: ý b
class Student extends Person {
    String maSinhVien;
    String email;
    float diemTongKet;

    public Student(String hoTen, String ngaySinh, String diaChi, String gioiTinh, String maSinhVien, String email, float diemTongKet) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.maSinhVien = maSinhVien;
        this.email = email;
        this.diemTongKet = diemTongKet;
    }

    @Override
    public void hienThiThongTin() {
        System.out.println("+----------------------+-----------------+----------------------+-----------------+-----------------+---------------------------+---------------+");
        String format1 = "| %-20s | %-15s | %-20s | %-15s | %-15s | %-25s | %-10s |\n";
        System.out.format(format1, "Họ tên", "Ngày sinh", "Địa chỉ", "Giới tính", "Mã SV", "Email", "Điểm tổng kết");
        System.out.println("+----------------------+-----------------+----------------------+-----------------+-----------------+---------------------------+---------------+");
        super.hienThiThongTin();
        String format2 = " %-15s | %-25s | %-13s |\n";
        System.out.format(format2, maSinhVien, email, diemTongKet );
        System.out.println("+----------------------+-----------------+----------------------+-----------------+-----------------+---------------------------+---------------+");
    }

    public String getMaSinhVien() {
        return maSinhVien;
    }

    public void setMaSinhVien(String maSinhVien) {
        this.maSinhVien = maSinhVien;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public float getDiemTongKet() {
        return diemTongKet;
    }

    public void setDiemTongKet(float diemTongKet) {
        this.diemTongKet = diemTongKet;
    }
    
}