package BaiTap.test;

abstract class Person {
    protected String name;
    protected int age;
    protected String gender;

    public Person(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
}

interface SalaryCalculator {
    double calculateSalary();
}

class Employee extends Person implements SalaryCalculator {
    protected double baseSalary;
    protected double coefficient;

    public Employee(String name, int age, String gender, double baseSalary, double coefficient) {
        super(name, age, gender);
        this.baseSalary = baseSalary;
        this.coefficient = coefficient;
    }

    @Override
    public double calculateSalary() {
        return coefficient * baseSalary;
    }
}

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

class Student extends BaiTap.Bai1.Person {
    protected String studentID;

    public Student(String name, int age, String gender, String studentID) {
        super(name, age, gender);
        this.studentID = studentID;
    }
}

class Programmer extends BaiTap.Bai1.Student {
    protected int experience;

    public Programmer(String name, int age, String gender, String studentID, int experience) {
        super(name, age, gender, studentID);
        this.experience = experience;
    }
}


public class bai1 {
    public static void main(String[] args) {
        System.out.println("\n=> Kết Qủa Chương Trình <= \n");

        BaiTap.Bai1.Person person = new BaiTap.Bai1.Person("Hoàng Tiến", 30, "Male");
        System.out.println("Name: " + person.getName());
        System.out.println("Age: " + person.getAge());
        System.out.println("Gender: " + person.getGender());

        System.out.println();

        BaiTap.Bai1.Employee employee = new BaiTap.Bai1.Employee("Thanh Thảo", 25, "Female", 1000, 1.5);
        System.out.println("Name: " + employee.getName());
        System.out.println("Age: " + employee.getAge());
        System.out.println("Gender: " + employee.getGender());
        System.out.println("Total Salary: " + employee.getTotalSalary());

        System.out.println();

        BaiTap.Bai1.Manager manager = new BaiTap.Bai1.Manager("Xuân Hiếu", 40, "Male", 2000, 2.0, 500);
        System.out.println("Name: " + manager.getName());
        System.out.println("Age: " + manager.getAge());
        System.out.println("Gender: " + manager.getGender());
        System.out.println("Total Salary: " + manager.getTotalSalary());

        System.out.println();

        BaiTap.Bai1.Student student = new BaiTap.Bai1.Student("Minh Vũ", 20, "Female", "12345");
        System.out.println("Name: " + student.getName());
        System.out.println("Age: " + student.getAge());
        System.out.println("Gender: " + student.getGender());
        System.out.println("Student ID: " + student.getStudentId());

        System.out.println();

        BaiTap.Bai1.Programmer programmer = new BaiTap.Bai1.Programmer("Thanh Xuân", 28, "Male", "67890", 3);
        System.out.println("Name: " + programmer.getName());
        System.out.println("Age: " + programmer.getAge());
        System.out.println("Gender: " + programmer.getGender());
        System.out.println("Student ID: " + programmer.getStudentId());
        System.out.println("Experience: " + programmer.getExperience());
    }
}