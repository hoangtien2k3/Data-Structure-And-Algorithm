package BaiTap.Bai1;

public class Student extends Person {
    private String studentId;

    public Student(String name, int age, String gender, String studentId) {
        super(name, age, gender);
        this.studentId = studentId;
    }

    public String getStudentId() {
        return studentId;
    }
}