package BaiTapUTT.BaiTapGhiFileVoiLuongByte.Bai1;

import java.io.Serializable;

public class Person implements Serializable {
    private String fullName;
    private String birthDate;
    private String address;
    private String gender;

    public Person(String fullName, String birthDate, String address, String gender) {
        this.fullName = fullName;
        this.birthDate = birthDate;
        this.address = address;
        this.gender = gender;
    }

    public void displayInfo() {
        System.out.println("Full Name: " + fullName);
        System.out.println("Birth Date: " + birthDate);
        System.out.println("Address: " + address);
        System.out.println("Gender: " + gender);
    }
}