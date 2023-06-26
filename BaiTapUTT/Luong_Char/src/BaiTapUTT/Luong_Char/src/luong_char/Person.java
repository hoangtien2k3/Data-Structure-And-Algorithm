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
public class Person {
    private String Hoten;
    private String Ngaysinh;
    private String Diachi;
    private String Gioitinh;
    
    public Person(){}
    public Person(String Hoten,String Ngaysinh, String Diachi, String Gioitinh ){
        this.Hoten = Hoten;
        this.Ngaysinh = Ngaysinh;
        this.Diachi = Diachi;
        this.Gioitinh = Gioitinh;
    }

    public void setHoten(String Hoten) {
        this.Hoten = Hoten;
    }

    public void setNgaysinh(String Ngaysinh) {
        this.Ngaysinh = Ngaysinh;
    }

    public void setDiachi(String Diachi) {
        this.Diachi = Diachi;
    }

    public void setGioitinh(String Gioitinh) {
        this.Gioitinh = Gioitinh;
    }

    public String getHoten() {
        return Hoten;
    }

    public String getNgaysinh() {
        return Ngaysinh;
    }

    public String getDiachi() {
        return Diachi;
    }

    public String getGioitinh() {
        return Gioitinh;
    }
    
    public void Input(){
                System.out.print("Nhap vao ten: ");
        this.setHoten(new Scanner(System.in).nextLine());
                System.out.print("Nhap vao ngay sinh: ");
        this.setNgaysinh(new Scanner(System.in).nextLine());
                System.out.print("Nhap vao dia chi: ");
        this.setDiachi(new Scanner(System.in).nextLine());
                System.out.print("Nhap vao gioi tinh: ");
        this.setGioitinh(new Scanner(System.in).nextLine());
    }
    
    public void Output(){
        System.out.println("Ho va ten : " + getHoten());
        System.out.println("Ngay Sinh : " + getNgaysinh());
        System.out.println("Dia chi : " + getDiachi());
        System.out.println("Gioi tinh : " + getGioitinh());    
    }
    
    
}
