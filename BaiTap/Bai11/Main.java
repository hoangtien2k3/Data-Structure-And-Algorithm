package BaiTap.Bai11;

public class Main {
    public static void main(String[] args) {
        Employee emp = new Employee("Hoang Tiến", 30, "male", 1000.0, 1.5);
        Manager mgr = new Manager("Thanh Thủy", 35, "female", 1500.0, 1.8, 500.0);
        Student std = new Student("Thanh Xuân", 20, "male", "S001");
        Programmer prg = new Programmer("Ngọc Hà", 25, "female", "S002", 2);

        System.out.println(emp.name + " earns " + emp.calculateSalary() + " dollars per month.");
        System.out.println(mgr.name + " earns " + mgr.calculateSalary() + " dollars per month.");
        System.out.println(std.name + " is a student with ID " + std.studentID + ".");
        System.out.println(prg.name + " has " + prg.experience + " years of experience.");
    }
}
