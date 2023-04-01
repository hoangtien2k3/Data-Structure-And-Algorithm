
## Binary Search Tree

Tạo Node cho cây BinarySearchTree
```java
public class Node {
    int data;
    Node left;
    Node right;

    public Node() {
    }
    public Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}
```

Hàm xử lý BinarySearchTree:
```java
public class BinarySearchTree {
    Node root;

    public BinarySearchTree() {
        root = null;
    }

    public Node addNode(Node root, int value) {
        Node temp = new Node(value);
        if (root == null) {
            root = temp;
        } else {
            if (value < root.data) {
                root.left = addNode(root.left, value);
            } else {
                root.right = addNode(root.right, value);
            }
        }
        return root;
    }


    public Node searchInTree(Node root, int x) {
        if (root == null) {
            return null;
        } else {
            if (x < root.data) {
                return searchInTree(root.left, x);
            } else if (x > root.data) {
                return searchInTree(root.right, x);
            } else {
                return root;
            }
        }
    }


    public Node deleteNode(Node root, int x) {
        if (root == null) {
            return null;
        } else {
            if (x < root.data) {
                root.left = deleteNode(root.left, x);
            } else if (x > root.data) {
                root.right = deleteNode(root.right, x);
            } else {
                Node p = root;
                if (root.left == null) {
                    root = root.right;
                } else if (root.right == null) {
                    root = root.left;
                } else {
                    findAndReplace(p, root.right);
                }
                p = null;
            }
        }
        return root;
    }


    public Node findAndReplace(Node p, Node tree) {
        if (tree.left != null) {
            tree.left = findAndReplace(p, tree.left);
        } else {
            p.data = tree.data;
            p = tree;
            tree = tree.right;
        }
        return p;
    }

    public int findMax(Node root) {
        int max = root.data;
        if (root.left == null && root.right == null) {
            return max;
        }
        if (root.right != null) {
            int data_right = findMax(root.right);
            if (max < data_right) {
                max = data_right;
            }
        }
        return max;
    }

    public int findMin(Node root) {
        int min = root.data;
        if (root.left == null && root.right == null) {
            return min;
        }
        if (root.left != null) {
            int data_left = findMin(root.left);
            if (min > data_left) {
                min = data_left;
            }
        }
        return min;
    }

    public void DestroyTree(Node root) {
        if (root != null) {
            DestroyTree(root.left);
            DestroyTree(root.right);
            root = null;
        }
    }


    public int TreeLevel(Node root) {
        if (root == null) {
            return -1;
        }
        return 1 + Math.max(TreeLevel(root.left), TreeLevel(root.right));
    }


    //! in node có 2 con:
    public void Print_Node_2_Element(Node root) {
        if (root != null) {
            if (root.left != null && root.right != null) {
                System.out.print(root.data + " ");
            }
            Print_Node_2_Element(root.left);
            Print_Node_2_Element(root.right);
        }
    }


    //! in node co 1 con:
    public void Print_Node_1_Element(Node root) {
        if (root != null) {
            if ((root.left != null && root.right == null) || (root.left == null && root.right != null)) {
                System.out.print(root.data + " ");
            }
            Print_Node_1_Element(root.left);
            Print_Node_1_Element(root.right);
        }
    }


    //! in node la:
    public void Print_Node_La(Node root) {
        if (root != null) {
            if (root.left == null && root.right == null) {
                System.out.print(root.data + " ");
            }
            Print_Node_La(root.left);
            Print_Node_La(root.right);
        }
    }


    //! in cây theo NLR
    public void Print_NLR(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            Print_NLR(root.left);
            Print_NLR(root.right);
        }
    }

}
```

Hàm Solution xử lý thông tin:
```java
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
```

Hàm Main:
```java
public class Main {
    public static void main(String[] args) {
        Solution.JavaBinarySearchTree();
    }
}
```