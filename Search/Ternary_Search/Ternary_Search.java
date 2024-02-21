package Search.Ternary_Search;

// Độ phức tạp của tìm kiếm tam phân là O(log3 n)
// Tìm kiếm tam phân - Ternary Search
class TernarySearch {
    // Hàm tìm kiếm tam phân - O(log3(n)
    public int ternarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            if (arr[mid1] == target) {
                return mid1;
            }
            if (arr[mid2] == target) {
                return mid2;
            }

            if (target < arr[mid1]) {
                right = mid1 - 1;
            } else if (target > arr[mid2]) {
                left = mid2 + 1;
            } else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }

        return -1;
    }
}

public class Ternary_Search {
    public static void main(String[] args) {
        TernarySearch ternarySearch = new TernarySearch();

        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int target = 5;
        int result = ternarySearch.ternarySearch(arr, target);
        if (result != -1) {
            System.out.println("Element found at index " + result);
        } else {
            System.out.println("Element not found in the array");
        }
    }
}
