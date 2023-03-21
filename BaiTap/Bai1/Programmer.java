package BaiTap.Bai1;

public class Programmer extends Student {
    private int experience;

    public Programmer(String name, int age, String gender, String studentId, int experience) {
        super(name, age, gender, studentId);
        this.experience = experience;
    }

    public int getExperience() {
        return experience;
    }
}
