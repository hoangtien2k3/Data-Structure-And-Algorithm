package HashTable.HashSetJava;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

public class HashSetJava {
    public static void main(String[] args) {
        Set<String> mySet = new LinkedHashSet<>();

        mySet.add("1");
        mySet.add("22");
        mySet.add("333");
        mySet.add("1");
        mySet.add("22");

        System.out.println(mySet.size());

        for(String s : mySet) {
            System.out.println(s);
        }

    }
}
