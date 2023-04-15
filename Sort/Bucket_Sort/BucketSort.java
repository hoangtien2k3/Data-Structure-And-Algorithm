package Sort.Bucket_Sort;

import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public static void bucketSort(double[] arr) {
        int n = arr.length;

        // Tạo các danh sách con (buckets)
        ArrayList<Double>[] buckets = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        // Đưa các phần tử vào các danh sách con (buckets)
        for (int i = 0; i < n; i++) {
            int bucketIndex = (int) (n * arr[i]);
            buckets[bucketIndex].add(arr[i]);
        }

        // Sắp xếp các danh sách con (buckets)
        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }

        // Gộp các danh sách con (buckets) lại thành một mảng đầu ra
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i].get(j);
            }
        }
    }
}


public class BucketSort {
    public static void main(String[] args) {
        // Mảng đầu vào
        double[] arr = {0.3, 0.1, 0.6, 0.8, 0.7, 0.2, 0.4, 0.9, 0.5};

        System.out.println("Mảng đầu vào:");
        for (double num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Sắp xếp mảng bằng bucket sort
        Solution.bucketSort(arr);

        System.out.println("Mảng sau khi sắp xếp:");
        for (double num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
