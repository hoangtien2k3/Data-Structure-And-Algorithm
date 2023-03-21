package BaiTap.Bai1;

public class Employee extends Person {
    private double basicSalary;
    private double bonus;

    public Employee(String name, int age, String gender, double basicSalary, double bonus) {
        super(name, age, gender);
        this.basicSalary = basicSalary;
        this.bonus = bonus;
    }

    public double getTotalSalary() {
        return basicSalary * bonus;
    }
}