package BaiTap.baitap.bai3;

import java.util.Scanner;


public class teacher extends person {
    private String rank;

    public teacher(){}

    public teacher(String name, String address, String deparment) {
        super(name, address, deparment);
        this.rank = rank;
    }

    public String getRank() {
        return rank;
    }

    public void setRank(String rank) {
        this.rank = rank;
    }
    
    public void print(){
        super.print();
        System.out.println(" - " + rank);
    }
    
    public void input(){
        super.input();
        System.out.print("\t + Nhap rank: ");
        this.setRank(new Scanner(System.in).nextLine());       
    }
    
    
    
}
