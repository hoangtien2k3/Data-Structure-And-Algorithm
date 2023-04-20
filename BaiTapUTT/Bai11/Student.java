package BaiTap.Bai11;

class Student extends Person {
    protected String studentID;

    public Student(String name, int age, String gender, String studentID) {
        super(name, age, gender);
        this.studentID = studentID;
    }
}