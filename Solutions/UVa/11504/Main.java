import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

// UVa 11504 - Dominos
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2499
class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        int T, N, M;
        T = scanner.nextInt();
        while ((T--) > 0) {
            N = scanner.nextInt();
            M = scanner.nextInt();
            final Domino domino = new Domino(N);
            while ((M--) > 0) {
                domino.addEdge(scanner.nextInt() - 1, scanner.nextInt() - 1);
            }
            final int res = domino.knock();
            writer.println(res);
        }

        writer.flush();
    }
}

/*
    Sample test cases
1
5 4
1 2
3 2
2 4
2 5
This should output 2

1
4 5
1 2
2 1
3 2
3 4
4 3

This should output 1
 */
class Domino {
    Set<Integer> seen;
    boolean[] isVisited;
    boolean[] hasParent;
    int N;
    List<List<Integer>> adj;

    public Domino(int N) {
        this.N = N;
        seen = new HashSet<>();
        isVisited = new boolean[N];
        hasParent = new boolean[N];
        adj = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            adj.add(i, new ArrayList<Integer>());
    }

    public void addEdge(int from, int to) {
        adj.get(from).add(to);
        hasParent[to] = true;
    }

    public int knock() {
        int res = 0;
        // go through the ones without incoming edge
        for (int i = 0; i < N; i++) {
            if (!hasParent[i]) {
                isVisited[i] = true;
                fill(i);
                res++;
            }
        }

        // take care of cycles
        for (int i = 0; i < N; i++) {
            if (!isVisited[i]) {
                isVisited[i] = true;
                if (fill(i)) res++;
            }
        }
        return res;
    }

    private boolean fill(int cur) {
        boolean needsPush = false;
        for (int neighbor : adj.get(cur)) {
            needsPush |= isVisited[neighbor];
            if (!isVisited[neighbor]) {
                isVisited[neighbor] = true;
                fill(neighbor);
            }
        }
        return needsPush;
    }
}