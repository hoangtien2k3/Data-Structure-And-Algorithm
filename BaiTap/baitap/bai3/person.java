package BaiTap.baitap.bai3;

import java.util.Scanner;


public class person {
    public String name;
    public String address;
    public String deparment;

    public person(){}
    
    public person(String name, String address, String deparment) {
        this.name = name;
        this.address = address;
        this.deparment = deparment;
    }
    
    
    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public String getDeparment() {
        return deparment;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public void setDeparment(String deparment) {
        this.deparment = deparment;
    }
    
    
    public void print(){
        System.out.print(name + " - " + address + " - " + deparment );
    }
    
    public void input(){
        System.out.print("\t + Nhap ho ten: ");
        this.setName(new Scanner(System.in).nextLine());
        
        System.out.print("\t + Nhap dia chi: ");
        this.setAddress(new Scanner(System.in).nextLine());
        
        System.out.print("\t + Nhap phong ban: ");
        this.setDeparment(new Scanner(System.in).nextLine());
    }
}
