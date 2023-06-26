/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de17;

/**
 *
 * @author hoang
 */
public class HocSinh extends Person {
    private String maHS;
    private String lop;
    private double diemTK;
    
    public HocSinh(String hoTen, String ngaySinh, String diaChi, String gioiTinh, String maHS, String lop, double diemTK) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.maHS = maHS;
        this.lop = lop;
        this.diemTK = diemTK;
    }
    
    public String getMaHS() {
        return maHS;
    }
    
    public String getLop() {
        return lop;
    }
    
    public double getDiemTK() {
        return diemTK;
    }
    
    @Override
    public String toString() {
        String format = " %-15s | %-10s | %-10s |\n";
        return super.toString() + String.format(format, maHS, lop, diemTK);
    }
}
