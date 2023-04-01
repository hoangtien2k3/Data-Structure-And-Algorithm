package HashTable.HashMapJava;

import java.util.HashMap;
import java.util.Map;


class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> myMap = new HashMap<>();

        for(int i = 0; i < s.length(); i++) {
            char charIndex = s.charAt(i);
            if (myMap.containsKey(charIndex) == false) {
                myMap.put(charIndex, 1);
            } else {
                myMap.put(charIndex, myMap.get(charIndex) + 1);
            }
        }

        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (myMap.get(c) == 1)
                return i;
        }

        return -1;
    }
}



public class HashMapJava {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 1, 1, 2};
        Map<Integer, Integer> myMap = new HashMap<>();

        // key: là giá trị của phần tử trong mảng
        // value: số lần xuất hiêện của phần tử trong mảng.
        for(int i : arr) {
            if (myMap.containsKey(i) == false) {
                // i chưa xuất hiện trong map
                myMap.put(i, 1);
            } else {
                // i la số lần xuất hiện trước đó.
                int soLanXuatHien = myMap.get(i);
                soLanXuatHien++;
                myMap.put(i, soLanXuatHien);
            }
        }

        for(Map.Entry entry : myMap.entrySet()) {
            System.out.println(entry.getKey() + " xuất hiện " + entry.getValue() + " lần !");
        }


        System.out.println();





        String s = "loveleetcode";
        Solution solution = new Solution();
        System.out.println(solution.firstUniqChar(s));


    }
}
