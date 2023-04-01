package Tree.Java_BinarySearchTree;

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



