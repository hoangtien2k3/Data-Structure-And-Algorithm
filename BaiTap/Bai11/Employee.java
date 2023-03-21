package BaiTap.Bai11;

class Employee extends Person implements SalaryCalculator{
    protected double baseSalary;
    protected double coefficient;

    public Employee(String name, int age, String gender, double baseSalary, double coefficient) {
        super(name, age, gender);
        this.baseSalary = baseSalary;
        this.coefficient = coefficient;
    }

    public double calculateSalary() {
        return coefficient * baseSalary;
    }
}