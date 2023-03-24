package Stack.bai4;

public class Node<T> {
    private T data;
    private Node<T> next;

    public Node(T data) {
        this.data = data;
        this.next = null;
    }

    public void setData(T data) {
        this.data = data;
    }

    public void setNext(Node<T> top) {
        this.next = top;
    }

    public T getData() {
        return data;
    }

    public Node<T> getNext() {
        return next;
    }
}
