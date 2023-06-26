/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de17;

/**
 *
 * @author hoangtien2k3
 */
public class Person {
    private String hoTen;
    private String ngaySinh;
    private String diaChi;
    private String gioiTinh;
    
    public Person(String hoTen, String ngaySinh, String diaChi, String gioiTinh) {
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
        this.gioiTinh = gioiTinh;
    }
    
    public String getHoTen() {
        return hoTen;
    }
    
    public String getNgaySinh() {
        return ngaySinh;
    }
    
    public String getDiaChi() {
        return diaChi;
    }
    
    public String getGioiTinh() {
        return gioiTinh;
    }
    
    @Override
    public String toString() {
        String format = "| %-20s | %-15s | %-20s | %-15s |";
        return String.format(format, hoTen, ngaySinh, diaChi, gioiTinh);
    }
}