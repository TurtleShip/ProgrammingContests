import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;

// 1197 - The Suspects
public class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, M;
        while ((N = Integer.parseInt(scanner.next())) != 0 | (M = Integer.parseInt(scanner.next())) != 0) {
            final UnionFind uf = new UnionFind(N);
            while (M-- > 0) {
                int K = Integer.parseInt(scanner.next());
                int leader = Integer.parseInt(scanner.next());
                for (int i = 0; i < K - 1; i++) {
                    int member = Integer.parseInt(scanner.next());
                    uf.unionSet(leader, member);
                }
            }

            int suspects = uf.findSet(0);
            writer.println(uf.sizeOfSet(suspects));
        }
        writer.flush();
    }
}

class UnionFind {
    private Vector<Integer> p, rank, setSize;

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
                if (rank.get(x) == rank.get(y)) rank.set(y, rank.get(y) + 1);
            }
        }
    }

    public int sizeOfSet(int i) {
        return setSize.get(findSet(i));
    }
}