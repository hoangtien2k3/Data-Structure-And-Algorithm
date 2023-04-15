package BaiTap.baitap.bai3;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class className {
    public String name;
    List<student> studentList = new ArrayList<>();
    public int numOfStudent;
    public teacher advisor;

    public className(){}
    
    public className(String name, int numOfStudent, teacher advisor) {
        this.name = name;
        this.numOfStudent = numOfStudent;
        this.advisor = advisor;
    }

    public String getName() {
        return name;
    }

    public List<student> getStudentList() {
        return studentList;
    }

    public int getNumOfStudent() {
        return numOfStudent;
    }

    public teacher getAdvisor() {
        return advisor;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setStudentList(List<student> studentList) {
        this.studentList = studentList;
    }

    public void setNumOfStudent(int numOfStudent) {
        this.numOfStudent = numOfStudent;
    }

    public void setAdvisor(teacher advisor) {
        this.advisor = advisor;
    }
    
    public void input(){
        System.out.println("________________ Nhập Thông Tin ________________");
        System.out.print("\t + Nhap ten lop: ");
        this.setName(new Scanner(System.in).nextLine());
        System.out.print("\t + Nhap so luong sinh vien: ");
        this.setNumOfStudent(new Scanner(System.in).nextInt());
        student st = null;
        for(int i = 0; i < this.getNumOfStudent(); i++){
           st = new student();
           st.input();
           st.setClassName(st.getClassName());
           studentList.add(st);
        }
        System.out.println("\t <=> Nhap Thong Tin Giao Vien Chu Nhiem <=>");
        teacher tc = new teacher();
        tc.input();
        System.out.println();
        this.setAdvisor(tc);
    }

    public void print(){
        System.out.println("____________________ Menu _____________________");
        System.out.println("\t - Ten Lop: " + this.getName() + "\n\t - Si so lop: " + this.getNumOfStudent());
        System.out.println("\n=> -- Thong Tin GVCN -- <=");
        System.out.println("Họ Tên - \tĐịa Chỉ - \tClassName - \tRank");
        this.getAdvisor().print();
        System.out.println("\n ___ Danh sach lop ___");
        System.out.println("STT - Họ Tên - \tĐịa Chỉ - \tPhòng Ban - \tClassName");
        student st = null;
        for(int i = 0; i < studentList.size(); i++){
            st = studentList.get(i);
            System.out.print((i+1)+": ");
            st.print();
        }
        System.out.println("_______________________________________________");
    }
}
