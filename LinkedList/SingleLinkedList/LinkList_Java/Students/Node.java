package LinkedList.SingleLinkedList.LinkList_Java.Students;

public class Node {
    public Student student;
    public Node next;

    public Node(Student student) {
        this.student = student;
        this.next = null;
    }

    public void printData() {
        student.printInfo();
    }

    public boolean hasStudent(int studentId) {
        return this.student.getId() == studentId;
    }
}
