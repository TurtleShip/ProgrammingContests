import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

// 297 - quadtrees
class Main {
    public static void main(String args[]) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = Integer.parseInt(scanner.next());

        while (T-- > 0) {
            final String first = scanner.next();
            final String second = scanner.next();

            final Node firstTree = (new NodeReader(first)).read();
            final Node secondTree = (new NodeReader(second)).read();
            final Node merged = Solver.merge(firstTree, secondTree);

            writer.printf("There are %d black pixels.\n", Solver.countBlack(merged));
        }
        writer.flush();
    }
}

class Node {
    /*
        NW | NE
        -------
        SW | SE
     */
    public Node NE; // NorthWest
    public Node NW; // NorthEast
    public Node SW; // SouthEast
    public Node SE; // SouthWest
    boolean isLeaf = false;
    boolean isBlack = false;

    public Node(boolean isLeaf, boolean isBlack) {
        this.isLeaf = isLeaf;
        this.isBlack = isBlack;
    }
}


class NodeReader {
    String line;
    boolean[] isRead;

    public NodeReader(String line) {
        this.line = line;
        isRead = new boolean[line.length()];
    }

    public Node read() {
        // special case where the whole image is just one color.
        if (line.length() == 1) {
            return (line.charAt(0) == 'f') ? new Node(true, true) : new Node(true, false);
        }

        final Node tree = new Node(false, false);
        isRead[0] = true;
        read(tree, 1);
        return tree;
    }

    private void read(Node parent, int idx) {
        // need to find 4 children

        // find NE
        char ch = line.charAt(idx);
        isRead[idx] = true;
        idx++;
        if (ch == 'p') {
            parent.NE = new Node(false, true);
            read(parent.NE, idx);
        } else {
            parent.NE = ch == 'f' ? new Node(true, true) : new Node(true, false);
        }

        // find NW
        while (isRead[idx]) {
            idx++;
        }
        ch = line.charAt(idx);
        isRead[idx] = true;
        idx++;
        if (ch == 'p') {
            parent.NW = new Node(false, true);
            read(parent.NW, idx);
        } else {
            parent.NW = ch == 'f' ? new Node(true, true) : new Node(true, false);
        }

        // find SW
        while (isRead[idx]) {
            idx++;
        }
        ch = line.charAt(idx);
        isRead[idx] = true;
        idx++;
        if (ch == 'p') {
            parent.SW = new Node(false, true);
            read(parent.SW, idx);
        } else {
            parent.SW = ch == 'f' ? new Node(true, true) : new Node(true, false);
        }

        // find SE
        while (isRead[idx]) {
            idx++;
        }
        ch = line.charAt(idx);
        isRead[idx] = true;
        idx++;
        if (ch == 'p') {
            parent.SE = new Node(false, true);
            read(parent.SE, idx);
        } else {
            parent.SE = ch == 'f' ? new Node(true, true) : new Node(true, false);
        }
    }
}

class Solver {

    public static Node merge(Node one, Node two) {
        if (one.isLeaf && two.isLeaf) {
            return (one.isBlack || two.isBlack) ? new Node(true, true) : new Node(true, false);
        } else if (one.isLeaf) {
            return one.isBlack ? one : two;
        } else if (two.isLeaf) {
            return two.isBlack ? two : one;
        } else { // both have children
            final Node merged = new Node(false, true);
            merged.NE = merge(one.NE, two.NE);
            merged.NW = merge(one.NW, two.NW);
            merged.SW = merge(one.SW, two.SW);
            merged.SE = merge(one.SE, two.SE);
            return merged;
        }
    }

    public static int countBlack(Node tree) {
        return countBlack(tree, 1024);
    }

    private static int countBlack(Node tree, int pixels) {
        if (tree.isLeaf) {
            return tree.isBlack ? pixels : 0;
        } else {
            int next = pixels / 4;
            return countBlack(tree.NE, next)
                + countBlack(tree.NW, next)
                + countBlack(tree.SW, next)
                + countBlack(tree.SE, next);
        }
    }
}
