package Sort.Quick_Sort;

import java.util.Arrays;

class QuickSort {
    public static void quicksort(int[] arr, int l, int r) {
        int pivot = arr[(l + r) / 2];
        int i = l, j = r;
        while(i < j) {
            while(arr[i] < pivot)
                i++;
            while(arr[j] > pivot)
                j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        if (l < j)
            quicksort(arr, l, j);
        if (i < r)
            quicksort(arr, i, r);
    }
}


public class QuickSort_Java {
    public static void main(String[] args) {
        int[] arr = { 5, 3, 8, 4, 2 };
        System.out.println("Mảng ban đầu: " + Arrays.toString(arr));
        QuickSort.quicksort(arr, 0, arr.length - 1);
        System.out.println("Mảng đã QuickSort: " + Arrays.toString(arr));
    }
}






