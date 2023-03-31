package BaiTap.test4;

import java.util.*;
interface NodeMethods {
     boolean isEmpty();
     void push(int data);
     int pop();
     int peek();
     int sumOfElements();
     boolean search(int data);
     void display();
}

class Node {
    private int data;
    private Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }

    public void setData(int data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public int getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }
}


class Stack implements NodeMethods {
    private Node top;

    @Override
    public boolean isEmpty() {
        return this.top == null;
    }

    @Override
    public void push(int data) {
        Node temp = new Node(data);
        temp.setNext(top); // temp.next = top;
        top = temp;
    }

    @Override
    public int pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }
        int data = top.getData();
        top = top.getNext(); // top = top.next;
        return data;
    }

    @Override
    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }
        return top.getData();
    }

    @Override
    public int sumOfElements() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }

        // cách 1:
//        int sum = 0;
//        Node current = top;
//        while (current != null) { // cách 1
//            sum += (int)current.getData();
//            current = current.getNext();
//        }
//        return sum;

        // cách 2:
        List<Integer> list = new ArrayList<>();
        Node current = top;
        while(current != null) {
            list.add(current.getData());
            current = current.getNext();
        }
        // parallelStream() để thực hiện đa luồng.
        return list.parallelStream().mapToInt(Integer::intValue).sum();
    }

    @Override
    public boolean search(int data) {
        Node temp = top;
        while (temp != null) {
            if (temp.getData() == data)
                return true;
            temp = temp.getNext();
        }
        return false;
    }

    @Override
    public void display() {
        Node temp = top;
        while (temp != null) {
            System.out.print(temp.getData() + " ");
            temp = temp.getNext();
        }
        System.out.println();
    }
}

class Solution {
    public static void getSolution() {
        Scanner input = new Scanner(System.in);
        Stack myStack = new Stack();
        while(true) {
            System.out.println("______________ Menu ______________");
            System.out.println("1. Them gia tri vao Stack");
            System.out.println("2. Xoa gia tri khoi Stack");
            System.out.println("3. Kiem tra rong");
            System.out.println("4. Tong cac gia tri trong Stack");
            System.out.println("5. Tim kiem gia tri trong Stack");
            System.out.println("6. Xuat danh sach Stack");
            System.out.println("7. Ket Thuc Chuong Trinh");
            System.out.println("__________________________________\n");
            System.out.print("=> Nhap lua chon: ");
            int lc = input.nextInt();
            switch (lc) {
                case 1: {
                    System.out.print("Them gia tri: ");
                    int value = input.nextInt();
                    myStack.push(value);
                    System.out.println("Da them gia tri " + value + " vao Stack !");
                    break;
                }
                case 2: {
                    System.out.println("Xoa thanh cong gia tri dau = " + myStack.peek() + " khoi Stack");
                    myStack.pop();
                    break;
                }
                case 3: {
                    if (myStack.isEmpty()){
                        System.out.println("Stack rong: true");
                    } else {
                        System.out.println("Stack khong rong: flase");
                    }
                    break;
                }
                case 4: {
                    System.out.println("Tong cac gia tri trong Stack: " + myStack.sumOfElements());
                    break;
                }
                case 5: {
                    System.out.print("Tim kiem gia tri: ");
                    int value = input.nextInt();
                    if (myStack.search(value)) {
                        System.out.println("Gia tri " + value + " co ton tai trong Stack!!!");
                    } else {
                        System.out.println("Gia tri " + value + " khong co trong Stack!!!");
                    }
                    break;
                }
                case 6: {
                    System.out.print("\nXuat danh sach Stack: ");
                    myStack.display();
                    break;
                }
                case 7:
                    System.out.print("Ket thuc chuong trinh !!!");
                    return;
                default:
                    System.out.println("=> Nhap lai chua chon !!!\n");
                    break;
            }
        }
    }
}


public class test4 {
    public static void main(String[] args) {
        Solution.getSolution();
    }
}

