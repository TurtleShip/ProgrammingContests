import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

// uva 11350 : Stern-Brocot Tree
class Main {
    /*
        Pre-creating the entire tree gets TLE.
        Split node on the fly.
     */
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N = scanner.nextInt();
        final Node tree = Solver.createTree();
        while ((N--) > 0) {
            final String sequence = scanner.next();
            final Node result = Solver.traverse(tree, sequence);

            writer.printf("%d/%d\n", result.a, result.b);
        }
        writer.flush();
    }
}

class Node {
    BigInteger a;
    BigInteger b;
    Node leftSibling;
    Node rightSibling;
    Node leftChild;
    Node rightChild;
}

class Solver {

    public static Node createTree() {
        final Node root = new Node();
        root.a = BigInteger.ONE;
        root.b = BigInteger.ONE;
        final Node zero = new Node();
        zero.a = BigInteger.ZERO;
        zero.b = BigInteger.ONE;
        final Node inf = new Node();
        inf.a = BigInteger.ONE;
        inf.b = BigInteger.ZERO;
        root.leftSibling = zero;
        root.rightSibling = inf;
        return root;
    }

    private static void split(Node node) {
        node.leftChild = new Node();
        node.leftChild.leftSibling = node.leftSibling;
        node.leftChild.rightSibling = node;
        node.leftChild.a = node.a.add(node.leftSibling.a);
        node.leftChild.b = node.b.add(node.leftSibling.b);

        node.rightChild = new Node();
        node.rightChild.leftSibling = node;
        node.rightChild.rightSibling = node.rightSibling;
        node.rightChild.a = node.a.add(node.rightSibling.a);
        node.rightChild.b = node.b.add(node.rightSibling.b);
    }

    public static Node traverse(Node root, String sequence) {
        Node res = root;
        for (char ch : sequence.toCharArray()) {
            if (res.leftChild == null) {
                split(res);
            }
            res = ch == 'L' ? res.leftChild : res.rightChild;
        }
        return res;
    }
}