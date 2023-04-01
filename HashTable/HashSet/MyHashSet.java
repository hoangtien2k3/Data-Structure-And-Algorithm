package HashTable.HashSet;

import java.util.ArrayList;
import java.util.Arrays;

public class MyHashSet {
    private final int SIZE = 1000;
    private ArrayList<Integer> myBuckets[];


    public MyHashSet() {
        myBuckets = new ArrayList[SIZE];
        for(int i = 0; i < myBuckets.length; i++) {
            myBuckets[i] = new ArrayList<>();
        }
    }

    // return HashValue
    public int hashFunction(int key) {
        return key % SIZE;
    }

    public void add(int key) {
        int hashValueIndex = hashFunction(key); // băm index
        ArrayList<Integer> bucket = myBuckets[hashValueIndex];
        int keyIndex = bucket.indexOf(key);
        if (keyIndex < 0) {
            bucket.add(key);
        }
    }

    public void remove(int key) {
        int hashValueIndex = hashFunction(key); //
        ArrayList<Integer> bucket = myBuckets[hashValueIndex];
        int keyIndex = bucket.indexOf(key);
        if (keyIndex >= 0) {
            bucket.remove(keyIndex);
        }
    }

    public boolean contains(int key) {
        int hashValueIndex = hashFunction(key);
        ArrayList<Integer> bucket = myBuckets[hashValueIndex];
        int keyIndex = bucket.indexOf(key);
        return keyIndex >= 0;
    }


    public static void main(String[] args) {
        MyHashSet mySet = new MyHashSet();
        mySet.add(1);
        mySet.add(1);
        mySet.add(2);
        System.out.println("mySet.contains(1): " + mySet.contains(1));
        mySet.remove(1);
        System.out.println("mySet.contains(1): " + mySet.contains(1));

    }



}
