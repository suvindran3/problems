import java.util.ArrayList;
import java.util.List;

class HeapTree {
    private List<Node> tree = new ArrayList<>();

    public HeapTree() {}

    public void addNode(Node node) {
        final int level = this.findLevel(this.tree.size());
        System.out.printf("Level: %d\n", level);
        if (level == 1) {
            tree.add(node);
            System.out.printf("%d value node added to tree\n", node.getValue());
            return;
        }
        final int[] capacity = this.findLevelCapacity(level); 
        final int[] previousCapacity = this.findLevelCapacity(level - 1);
        final int insertIndex = Math.floorDiv((this.tree.size() - capacity[0]), 2) + previousCapacity[0];
        System.out.printf("Insert index: %d\n", insertIndex);
        final Node parent = tree.get(insertIndex);
        parent.linkNode(node);
        tree.add(node);
    }

    private int findLevel(int index) {
        if (index == 0) {
            return 1;
        }
        int level = 2;
        while (true) {
            if (index < Math.pow(2, level) - 1 && index >= Math.pow(2, level - 1) - 1) {
                return level;
            }
            level++;
        }
    }

    private int[] findLevelCapacity(int level) {
        if (level == 1) {
            return new int[]{0, 1, 1};
        }
        final int start = (int)Math.pow(2, level - 1) - 1;
        final int end = (int)Math.pow(2, level) - 1;
        return new int[]{start, end, end - start};
    }
}

class Node {
    private int value;
    private Node leftNode;
    private Node rightNode;

    public Node (int value) {
        this.value = value;
    }

    public void linkNode(Node node) {
        if (this.leftNode == null) {
            System.out.printf("%d value node linked to %d value node to the left\n", node.value, this.value);
            this.leftNode = node;
            return;
        }
        if (this.rightNode != null) {
            throw new ArithmeticException();
        }
        System.out.printf("%d value node linked to %d value node to the right\n", node.value, this.value);
        this.rightNode = node;
    }

    public Node getLeftNode() {
        return leftNode;
    }

    public Node getRightNode() {
        return rightNode;
    }

    public int getValue() {
        return value;
    }
}

class Heap {
    public static void main(String args[]) {
        final int[] nums = {9, 10, 0, 5, 4, 12};
        final HeapTree tree = new HeapTree();
        for (int i : nums) {
            final Node node = new Node(i);
            tree.addNode(node);
        }
    }
}