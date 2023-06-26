/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de19;

/**
 *
 * @author hoang
 */
public class CanBo extends Person {
    private String phongBan;
    private double heSoLuong;
    private double luongCoBan;
    private double thuong;
    private double phat;

    public CanBo(String hoTen, String ngaySinh, String diaChi, String gioiTinh, String phongBan, double heSoLuong, double luongCoBan, double thuong, double phat) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.phongBan = phongBan;
        this.heSoLuong = heSoLuong;
        this.luongCoBan = luongCoBan;
        this.thuong = thuong;
        this.phat = phat;
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

    public double getLuongCoBan() {
        return luongCoBan;
    }

    public void setLuongCoBan(double luongCoBan) {
        this.luongCoBan = luongCoBan;
    }

    public double getThuong() {
        return thuong;
    }

    public void setThuong(double thuong) {
        this.thuong = thuong;
    }

    public double getPhat() {
        return phat;
    }

    public void setPhat(double phat) {
        this.phat = phat;
    }

    public double tinhLuongThucLinh() {
        return luongCoBan * heSoLuong + thuong - phat;
    }

    @Override
    public String toString() {
        String format = " %-18s | %-12s | %-12s | %-10s | %-10s | %-20s |\n";
        return super.toString() + String.format(format, phongBan, heSoLuong, luongCoBan, thuong, phat, tinhLuongThucLinh());  
    }

}