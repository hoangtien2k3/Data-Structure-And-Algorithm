package LinkedList.SingleLinkedList.LinkList_Java.Test;

public class Main {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<String>();
        list.addLinkedList("apple");
        list.addLinkedList("banana");
        list.addLinkedList("cherry");

        System.out.println("Size of list: " + list.size()); // Size of list: 3
        System.out.println("Element at index 1: " + list.get(1)); // Element at index 1: banana
        list.removeNode("banana");

        System.out.println("Size of list after removing banana: " + list.size()); // Size of list after removing banana: 2
        System.out.println("Element at index 1 after removing banana: " + list.get(1)); // Element at index 1 after removing banana: cherry
    }
}
