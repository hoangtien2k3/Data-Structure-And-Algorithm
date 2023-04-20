package BaiTap.Bai1;

public class Manager extends Employee {
    private double responsibilityAllowance;

    public Manager(String name, int age, String gender, double basicSalary, double bonus, double responsibilityAllowance) {
        super(name, age, gender, basicSalary, bonus);
        this.responsibilityAllowance = responsibilityAllowance;
    }

    public double getTotalSalary() {
        return super.getTotalSalary() + responsibilityAllowance;
    }
}
