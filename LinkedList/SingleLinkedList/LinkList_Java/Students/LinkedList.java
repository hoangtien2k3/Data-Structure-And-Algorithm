package LinkedList.SingleLinkedList.LinkList_Java.Students;

public class LinkedList {
    private int size;
    private Node head;
    private Node tail;

    public LinkedList() {
        Student.autoId = 1;
        this.size = 0;
        this.head = null;
        this.tail = null;
    }

    public int size() {
        return this.size;
    }

    public Node search(int studentId) {
        Node currentNode = this.head;
        while (currentNode != null) {
            if (currentNode.hasStudent(studentId)) {
                return currentNode;
            }
            currentNode = currentNode.next;
        }

        return null;
    }

    public void insertAt(Node node, int position) {
        if (position < 1 || this.size == 0) {
            node.next = this.head;
            this.head = node;

            if (this.tail == null) {
                this.tail = node;
            }

            this.size++;
            return;
        }
        if (position >= this.size) {
            if (this.tail != null) {
                this.tail.next = node;
            }
            this.tail = node;

            if (this.head == null) {
                this.head = node;
            }

            this.size++;
            return;
        }
        Node preNode = null;
        Node currentNode = this.head;
        int counter = 0;
        while (counter < position) {
            counter++;
            preNode = currentNode;
            currentNode = currentNode.next;
        }
        node.next = currentNode;
        preNode.next = node;
        this.size++;
    }

    public void delete(int studentId) {
        Node preNode = null;
        Node currentNode = this.head;
        int counter = 0;
        while (currentNode != null) {
            if (currentNode.hasStudent(studentId)) {
                if (counter == 0) {
                    // delete first
                    this.head = this.head.next;
                    if (this.head == null) {
                        this.tail = null;
                    }
                } else if (counter == this.size - 1) {
                    // delete last
                    preNode.next = null;
                    this.tail = preNode;
                } else {
                    // delete in the middle
                    preNode.next = currentNode.next;
                }
                this.size--;
                return;
            }
            counter++;
            preNode = currentNode;
            currentNode = currentNode.next;
        }
    }

    public void printList() {
        System.out.print("\n-----------");
        System.out.print("\nSize = " + this.size);
        System.out.print("\n------------------------");
        Node currentNode = this.head;
        while (currentNode != null) {
            currentNode.printData();
            currentNode = currentNode.next;
        }
    }
}
