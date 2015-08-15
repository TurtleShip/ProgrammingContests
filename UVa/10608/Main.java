import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        int T = Integer.parseInt(scanner.next());
        while (T-- > 0) {
            int N = Integer.parseInt(scanner.next());
            int M = Integer.parseInt(scanner.next());
            final UnionFind uf = new UnionFind(N);
            while (M-- > 0) {
                int a = Integer.parseInt(scanner.next()) - 1;
                int b = Integer.parseInt(scanner.next()) - 1;
                uf.unionSet(a, b);
            }
            int best = Collections.max(uf.setSize);
            writer.println(best);
        }
        writer.flush();
    }
}


class UnionFind {
    public Vector<Integer> p, rank, setSize;

    public UnionFind(int N) {
        p = new Vector<Integer>(N);
        rank = new Vector<Integer>(N);
        setSize = new Vector<Integer>(N);
        for (int i = 0; i < N; i++) {
            p.add(i);
            rank.add(0);
            setSize.add(1);
        }
    }

    public int findSet(int i) {
        if (p.get(i) == i) return i;
        else {
            int ret = findSet(p.get(i));
            p.set(i, ret);
            return ret;
        }
    }

    public Boolean isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    public void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank.get(x) > rank.get(y)) {
                p.set(y, x);
                setSize.set(x, setSize.get(x) + setSize.get(y));
            } else {
                p.set(x, y);
                setSize.set(y, setSize.get(y) + setSize.get(x));
                if (rank.get(x).equals(rank.get(y))) rank.set(y, rank.get(y) + 1);
            }
        }
    }
}
