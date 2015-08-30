import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class BMusketeers {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        final Graph graph = new Graph(N, M);

        for (int i = 0; i < M; i++) {
            graph.addEdge(scanner.nextInt() - 1, scanner.nextInt() - 1, i);
        }

        int res = graph.solve();
        writer.println(res);
        writer.flush();
    }
}

class Triple {
    int x, y, z;

    public Triple(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class Graph {
    int N;
    int M;
    boolean[] isVisited;
    int[] from; // edge list
    int[] to; // edge list
    List<Set<Integer>> neighbor;
    List<Triple> candidates;

    public Graph(int N, int M) {
        this.N = N;
        this.M = M;
        neighbor = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            neighbor.add(i, new HashSet<>());
        candidates = new LinkedList<>();
        isVisited = new boolean[N];
        from = new int[M];
        to = new int[M];
    }


    public void addEdge(int x, int y, int idx) {
        neighbor.get(x).add(y);
        neighbor.get(y).add(x);
        from[idx] = x;
        to[idx] = y;

    }

    public int solve() {
        // do search
//        for (int i = 0; i < N; i++) {
//            if (!isVisited[i]) {
//                isVisited[i] = true;
//                dfs(-1, -1, i);
//            }
//        }

        // do search on edge list. This is M * N ~ 16,000,000. Good enough.
        for (int i = 0; i < M; i++) {
            // from , to are already connected. Check which node they both connect
            for (int possible : neighbor.get(from[i])) {
                if (neighbor.get(to[i]).contains(possible)) {
                    candidates.add(new Triple(from[i], to[i], possible));
                }
            }
        }

        if (candidates.size() == 0) return -1;

        int best = 100_000_000;
        for (Triple now : candidates) {
            // recognition is the size of neighbors
            int cur = Math.max(0, neighbor.get(now.x).size() - 2)
                + Math.max(0, neighbor.get(now.y).size() - 2)
                + Math.max(0, neighbor.get(now.z).size() - 2);
            best = Math.min(cur, best);
        }

        return best;
    }

}