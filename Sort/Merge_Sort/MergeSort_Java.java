package Sort.Merge_Sort;


import java.util.Arrays;

class MergeSort_Solution {

    public static void merge(int[] arr, int l, int m, int r) {
        // tao ra 2 biến tạm.
        int n1 = m - l + 1; // số lượng phần tử (left -> mid + 1)
        int n2 = r - m;    // số lượng phần từ  (mid + 1 -> r)

        // tạo mảng tạm thời
        int[] L = new int[n1];
        int[] R = new int[n2];

        // sao chép dữ liệu cho mảng tạm thời đó.
        // arr[] là mảng ban dầu mà chúng ta muốn sắp xếp
        for(int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for(int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        // tạo ra 2 giá trị
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[l++] = L[i++];
            } else {
                arr[l++] = R[j++];
            }
        }

        // Sao chép các phần tử còn lại của L[] nếu có
        while(i < n1) {
            arr[l++] = L[i++];
        }
        while(j < n2) {
            arr[l++] = R[j++];
        }
    }


    public static void sort(int[] arr, int l, int r) {
        if (l < r) {
            int m = (l + r)/2; // lấy ra mid ở giữa mảng

            // sắp xếp nữa mảng đầu tiên, và nữa mảng sau:
            sort(arr, l, m); // áp dụng chia để trị: tách mảng đầu thành các phần tử đơn lẻ (từ left -> mid + 1)
            sort(arr, m + 1, r); // áp dụng chia để trị: tách mảng đầu thành các phần tử đơn lẻ (từ mid + 1 -> right)

            // merge hay ghép các nữa mảng lại với nhau:
            merge(arr, l, m, r);
        }
    }
}


public class MergeSort_Java {
    public static void main(String args[]) {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        System.out.println("Mảng ban đầu: " + Arrays.toString(arr));
        MergeSort_Solution.sort(arr, 0, arr.length - 1);
        System.out.println("Mảng đã MergeSort: " + Arrays.toString(arr));
    }
}
