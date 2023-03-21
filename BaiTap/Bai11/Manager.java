package BaiTap.Bai11;

class Manager extends Employee implements SalaryCalculator {
    protected double quizSalary;

    public Manager(String name, int age, String gender, double baseSalary, double coefficient, double quizSalary) {
        super(name, age, gender, baseSalary, coefficient);
        this.quizSalary = quizSalary;
    }

    public double calculateSalary() {
        return super.calculateSalary() + quizSalary;
    }
}