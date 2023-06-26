/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package BaiTapUTT.Luong_Char.src.luong_char;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class NhanVien extends Person{
    private String Phongban;
    private float Hesoluong;
    private int Thamnien;
    private double Luongcoban;
    
    public NhanVien(){}
    public NhanVien(String Hoten,String Ngaysinh, String Diachi, String Gioitinh, String Phongban, float Hesoluong, int Thamnien, double Luongcoban){
        super();
        this.Phongban = Phongban;
        this.Hesoluong = Hesoluong;
        this.Thamnien = Thamnien;
        this.Luongcoban = Luongcoban;
    }

    public void setPhongban(String Phongban) {
        this.Phongban = Phongban;
    }

    public void setHesoluong(float Hesoluong) {
        this.Hesoluong = Hesoluong;
    }

    public void setThamnien(int Thamnien) {
        this.Thamnien = Thamnien;
    }

    public void setLuongcoban(double Luongcoban) {
        this.Luongcoban = Luongcoban;
    }

    public String getPhongban() {
        return Phongban;
    }

    public int getThamnien() {
        return Thamnien;
    }

    public double getLuongcoban() {
        return Luongcoban;
    }

    public float getHesoluong() {
        return Hesoluong;
    }
    
    public double Luongthuclinh(){
        return Luongcoban * (1 + Thamnien / 100) * Hesoluong;
    }
    
    public void Input(){
        super.Input();
                System.out.print("Nhap Phong Ban : ");
        this.setPhongban(new Scanner(System.in).nextLine());
                System.out.print("Nhap He So Luong : ");
        this.setHesoluong(new Scanner(System.in).nextFloat());
                System.out.print("Nhap Tham Nien : ");
        this.setThamnien(new Scanner(System.in).nextInt());
                System.out.print("Nhap Luong Co Ban : ");
        this.setLuongcoban(new Scanner(System.in).nextDouble());
    }   
    
    public void output(){
        super.Output();
        System.out.println("Phong ban : " + getPhongban());
        System.out.println("He so Luong : " + getHesoluong());
        System.out.println("Tham Nien : " + getThamnien());
        System.out.println("Luong co ban : " + getLuongcoban());
        System.out.println("Luong thuc linh  : " + Luongthuclinh());
    }
}
