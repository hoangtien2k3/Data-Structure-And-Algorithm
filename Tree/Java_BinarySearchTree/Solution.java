package Tree.Java_BinarySearchTree;

import java.util.Scanner;

public class Solution {
    public static void JavaBinarySearchTree() {
        Scanner input = new Scanner(System.in);
        BinarySearchTree binarySearchTree = new BinarySearchTree();

        while(true) {
            System.out.println("\n_____________Menu______________\n");
            System.out.println("1. Nhap du lieu cay");
            System.out.println("2. Xuat danh sach cay");
            System.out.println("3. Tim phan tu trong cay");
            System.out.println("4. Xuat danh sach cay co 2 con !");
            System.out.println("5. Xuat danh sach cay co 1 con !");
            System.out.println("6. Xuat danh sach cay co Node La !");
            System.out.println("7. Tim Max cua danh sach cay");
            System.out.println("8. Tim Min cua danh sach cay");
            System.out.println("9. Xoa Node bat ky trong danh sach cay");
            System.out.println("10. Xoa cay nhi phan tim kiem");
            System.out.println("11. Bac cua cay nhi phan tim kiem");
            System.out.println("0. Khet thuc!!!");
            System.out.println("_________________________________\n");

            System.out.print("Nhap vao lua chon: ");
            int lc = input.nextInt();
            switch (lc) {
                case 1: {
                    System.out.print("Nhap vao gia tri can them vao: ");
                    int x = input.nextInt();
                    binarySearchTree.root = binarySearchTree.addNode(binarySearchTree.root, x);
                    break;
                }
                case 2: {
                    System.out.println("Xuat du lieu cay theo NLR: ");
                    binarySearchTree.Print_NLR(binarySearchTree.root);
                    break;
                }
                case 3: {
                    System.out.print("Danh Sach: ");
                    binarySearchTree.Print_NLR(binarySearchTree.root);
                    System.out.print("\nNhap vao phan tu can tim kiem: ");
                    int x = input.nextInt();
                    if (binarySearchTree.searchInTree(binarySearchTree.root, x) == null) {
                        System.out.println("Phan tu '" +x + "' khong ton tai trong cay!");
                    } else {
                        System.out.println("Phan tu '" + x + "' co ton tai trong cay!");
                    }
                    break;
                }
                case 4: {
                    System.out.println("Xuat danh sach cay co 2 con: ");
                    binarySearchTree.Print_Node_2_Element(binarySearchTree.root);
                    break;
                }
                case 5: {
                    System.out.println("Xuat danh sach cay co 1 con: ");
                    binarySearchTree.Print_Node_1_Element(binarySearchTree.root);
                    break;
                }
                case 6: {
                    System.out.println("Xuat danh sach cay co Node La: ");
                    binarySearchTree.Print_Node_La(binarySearchTree.root);
                    break;
                }
                case 7: {
                    System.out.print("Max cua danh sach cay: " + binarySearchTree.findMax(binarySearchTree.root));
                    break;
                }
                case 8: {
                    System.out.print("Min cua danh sach cay: " + binarySearchTree.findMin(binarySearchTree.root));
                    break;
                }
                case 9: {
                    System.out.print("Nhap vao gia tri can xoa: ");
                    int x = input.nextInt();
                    binarySearchTree.deleteNode(binarySearchTree.root, x);
                    break;
                }
                case 10: {
                    binarySearchTree.DestroyTree(binarySearchTree.root);
                    System.out.println("Đã xoa cay nhi phan tim kiem!!!");
                    break;
                }
                case 11: {
                    System.out.print("Bậc của cây nhị phân: " + binarySearchTree.TreeLevel(binarySearchTree.root));
                    break;
                }
                case 0: return;
            }
        }
    }
}
