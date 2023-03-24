package Stack.bai4;

public class Stack<T> {
    private Node<T> top;

    public Stack() {
        this.top = null;
    }

    public boolean isEmpty() {
        return this.top == null;
    }

    public void push(T data) {
        Node<T> temp = (Node<T>) new Node<>(data);
        temp.setNext(top); // temp->next = top;
        top = temp;
    }

    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }
        T data = (T) top.getData();
        top = top.getNext(); // top = top->next;
        return data;
    }

    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }
        return (T) top.getData();
    }


    public T sumOfElements() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }
        Integer sum = (Integer) Integer.valueOf(0);
        Node<T> temp = top;
        while(temp != null) {
            // lấy tổng sum;
            sum = (Integer) Integer.valueOf(sum.intValue() + ((Integer) temp.getData()).intValue());
            Node<T> tempnext = temp.getNext(); // lưu trữ nút tiếp theo.
            temp.setNext(null); // xóa liên kết phần tử hiện tại và phần tử tiếp theo.
            top = tempnext;
            temp = top;
        }
        return (T) sum;
    }

    public boolean search(T data) {
        Node<T> temp = top;
        while (temp != null) {
            if (temp.getData().equals(data))
                return true;
            temp = temp.getNext();
        }
        return false;
    }

    public void display() {
        Node<T> temp = top;
        while (temp != null) {
            System.out.print(temp.getData() + " ");
            temp = temp.getNext();
        }
        System.out.println();
    }
}
