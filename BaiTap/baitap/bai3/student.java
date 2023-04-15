package BaiTap.baitap.bai3;

import java.util.Scanner;


public class student extends person {

    public String className;
    
    public student() {
    }
    
    public student(String name, String address, String deparment) {
        super(name, address, deparment);
        this.className = className;
    }
    
    public String getClassName() {
        return className;
    }
    
    public void setClassName(String className) {
        this.className = className;
    }
    
    public void print() {
        super.print();
        System.out.println(" - " + className);
    }
    
    public void input(){
        super.input();
        System.out.print("\t + Nhap className: ");
        this.setClassName(new Scanner(System.in).nextLine());
    }
}
