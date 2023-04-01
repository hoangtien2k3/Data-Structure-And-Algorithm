package HashTable.MashMap;

import java.util.ArrayList;

public class MyHashMap {
    private class Data {
        int key;
        int value;
        Data(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public boolean equals(Object other) {
            if (other instanceof Data) { // Object thuộc kiểu Data
                return this.key == ((Data) other).key;
            }
            return false;
        }
    }


    private final int SIZE = 1000;
    private ArrayList<Data> myBuckets[];

    public MyHashMap() {
        myBuckets = new ArrayList[SIZE];
        for(int i = 0; i < myBuckets.length; i++) {
            myBuckets[i] = new ArrayList<>();
        }
    }

    public int hashFunction(int key) {
        return key % SIZE;
    }


    public void put(int key, int value) {
        int hashValueIndex = hashFunction(key); // hashValueIndex nó chỉ là 1 key của myBuckets list đó thôi
        ArrayList<Data> bucket = myBuckets[hashValueIndex];

        Data temp = new Data(key, value);

        int keyIndex = bucket.indexOf(temp);
        if (keyIndex >= 0) {
            bucket.get(keyIndex).value = value; // update lai gia tri value
        } else {
            bucket.add(temp);
        }
    }


    public void remove(int key) {
        int hashValueIndex = hashFunction(key);
        ArrayList<Data> bucket = myBuckets[hashValueIndex];
        Data temp = new Data(key, 0); // tao object co cung key roi xoa object do.
        bucket.remove(temp);
    }


    public int get(int key) {
        int hashValueIndex = hashFunction(key);
        ArrayList<Data> bucket = myBuckets[hashValueIndex];

        Data temp = new Data(key, 0);
        int keyIndex = bucket.indexOf(temp);
        if (keyIndex >= 0) {
            return bucket.get(keyIndex).value;
        }

        return -1;
    }


    public static void main(String[] args) {
        MyHashMap myMap = new MyHashMap();
        myMap.put(1, 1);
        myMap.put(1, 2);
        myMap.put(10, 2);

        System.out.println("myMap.get(1): " + myMap.get(1));
        System.out.println("myMap.get(2): " + myMap.get(2));

        myMap.remove(1);
        System.out.println("myMap.get(1): " + myMap.get(1));
        System.out.println("myMap.get(10): " + myMap.get(10));

    }
}
