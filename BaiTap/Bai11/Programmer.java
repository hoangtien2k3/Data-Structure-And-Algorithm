package BaiTap.Bai11;

class Programmer extends Student {
    protected int experience;

    public Programmer(String name, int age, String gender, String studentID, int experience) {
        super(name, age, gender, studentID);
        this.experience = experience;
    }
}