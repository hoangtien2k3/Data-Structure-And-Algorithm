package BaiTap.Bai1;

public class Main {
    public static void main(String[] args) {
        System.out.println("\n=> Kết Qủa Chương Trình <= \n");

        Person person = new Person("Hoàng Tiến", 30, "Male");
        System.out.println("Name: " + person.getName());
        System.out.println("Age: " + person.getAge());
        System.out.println("Gender: " + person.getGender());

        System.out.println();

        Employee employee = new Employee("Thanh Thảo", 25, "Female", 1000, 1.5);
        System.out.println("Name: " + employee.getName());
        System.out.println("Age: " + employee.getAge());
        System.out.println("Gender: " + employee.getGender());
        System.out.println("Total Salary: " + employee.getTotalSalary());

        System.out.println();

        Manager manager = new Manager("Xuân Hiếu", 40, "Male", 2000, 2.0, 500);
        System.out.println("Name: " + manager.getName());
        System.out.println("Age: " + manager.getAge());
        System.out.println("Gender: " + manager.getGender());
        System.out.println("Total Salary: " + manager.getTotalSalary());

        System.out.println();

        Student student = new Student("Minh Vũ", 20, "Female", "12345");
        System.out.println("Name: " + student.getName());
        System.out.println("Age: " + student.getAge());
        System.out.println("Gender: " + student.getGender());
        System.out.println("Student ID: " + student.getStudentId());

        System.out.println();

        Programmer programmer = new Programmer("Thanh Xuân", 28, "Male", "67890", 3);
        System.out.println("Name: " + programmer.getName());
        System.out.println("Age: " + programmer.getAge());
        System.out.println("Gender: " + programmer.getGender());
        System.out.println("Student ID: " + programmer.getStudentId());
        System.out.println("Experience: " + programmer.getExperience());
    }
}