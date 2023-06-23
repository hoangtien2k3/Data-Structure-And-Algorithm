package BaiTapUTT.BaiTapGhiFileVoiLuongByte.Bai1;

public class NhanVien extends Person {
    private String department;
    private double salaryFactor;
    private int seniority;
    private double baseSalary;

    public NhanVien(String fullName, String birthDate, String address, String gender,
                    String department, double salaryFactor, int seniority, double baseSalary) {
        super(fullName, birthDate, address, gender);
        this.department = department;
        this.salaryFactor = salaryFactor;
        this.seniority = seniority;
        this.baseSalary = baseSalary;
    }

    public double getNetSalary() {
        return baseSalary * salaryFactor * (1 + seniority / 100.0);
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Department: " + department);
        System.out.println("Net Salary: " + getNetSalary());
    }
}