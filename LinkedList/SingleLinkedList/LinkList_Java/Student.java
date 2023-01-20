package LinkedList.SingleLinkedList.LinkList_Java;

public class Student {
    public static int autoId;
    private int id;
    private String name;
    private int age;

    public Student(String name, int age) {
        this.id = Student.autoId++;
        this.name = name;
        this.age = age;
    }

    public int getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return this.age;
    }
    public void setAge(int age) {
        this.age = age;
    }

    public void printInfo() {
        System.out.print("\nId: " + this.id);
        System.out.print("\nName: " + this.name);
//		System.out.print("\nAge: " + this.age);
        System.out.print("\n------------------------");
    }
}
