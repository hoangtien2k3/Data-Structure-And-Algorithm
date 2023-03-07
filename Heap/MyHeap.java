package Heap;

public class MyHeap {
    private int MAX_SIZE = 100;
    private int[] arr = new int[MAX_SIZE + 1];
    private int size;

    public MyHeap() {
        size = 0;
    }

    public boolean isEmpty() {
        return size <= 0;
    }

    public int peek() {
        if (isEmpty()) {
            // throw exception
            System.out.println("Error: Heap is empty!");
        }
        return arr[1];
    }

    private void swap(int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public void add(int v) {
        size++;
        arr[size] = v;
        // heapify up
        int curIndex = size;
        int parentIndex = curIndex / 2;

        while(parentIndex != 0 && arr[parentIndex] > arr[curIndex]) {
            // swap
            swap(parentIndex, curIndex);
            parentIndex = curIndex / 2;
        }
    }

}
