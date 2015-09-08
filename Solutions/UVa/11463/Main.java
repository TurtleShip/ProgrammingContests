import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        final int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            final int N = scanner.nextInt();
            final int R = scanner.nextInt();
            final Graph graph = new Graph(N);

            for (int i = 0; i < R; i++)
                graph.addEdge(scanner.nextInt(), scanner.nextInt());

            writer.printf("Case %d: %d\n", cid, graph.solve(scanner.nextInt(), scanner.nextInt()));
        }
        writer.flush();
    }
}

class Graph {
    static int INF = 1_000_000;
    int N;
    int[][] cost;

    public Graph(int N) {
        this.N = N;
        cost = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cost[i][j] = INF;

        for (int i = 0; i < N; i++)
            cost[i][i] = 0;
    }

    public void addEdge(int x, int y) {
        cost[x][y] = cost[y][x] = 1;
    }

    /*
        Algorithm
        1. Find the shortest path cost between all possible pairs of nodes.
        2. For each node x, send commando src -> x -> dst.
           Therefore, the answer is
            Math.max(cost[base][x] + cost[x][rally]) amongst all x.
     */
    public int solve(int base, int rally) {
        // Floydd-Warshall
        for (int mid = 0; mid < N; mid++)
            for (int st = 0; st < N; st++)
                for (int dst = 0; dst < N; dst++)
                    cost[st][dst] = Math.min(cost[st][dst], cost[st][mid] + cost[mid][dst]);

        int res = cost[base][rally];
        for (int mid = 0; mid < N; mid++) {
            if (mid == base || mid == rally) continue;
            res = Math.max(res, cost[base][mid] + cost[mid][rally]);
        }

        return res;
    }
}
