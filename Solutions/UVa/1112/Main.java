import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

// 1112 - Mice and Maze
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3553

/*
    Algorithm.
    1. Reverse the direction of edges.
    2. Run SSSR ( Single Sourced Shortest Path ) starting from exit node.
    3. The number of nodes whose dist[x] <= T is the answer.
 */
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int Y, N, E, T, M, INF = -1;

        // There are at most 100 cells.
        int[] len = new int[110];
        int[][] adj = new int[110][110];
        int[][] cost = new int[110][110];
        int[] dist = new int[110];

        Y = scanner.nextInt();

        for (int cid = 1; cid <= Y; cid++) {
            if (cid > 1) writer.println();
            N = scanner.nextInt();
            E = scanner.nextInt();
            T = scanner.nextInt();
            M = scanner.nextInt();

            Arrays.fill(len, 0);
            Arrays.fill(dist, INF);

            while ((M--) > 0) {
                // reverse the direction by reading the input in reverse order
                int to = scanner.nextInt();
                int from = scanner.nextInt();
                int c = scanner.nextInt();

                adj[from][len[from]++] = to;
                cost[from][to] = c;
            }

            // run SSSR
            final PriorityQueue<Edge> Q = new PriorityQueue<>(1, new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return Integer.compare(o1.cost, o2.cost);
                }
            });

            Q.add(new Edge(0, E)); // we start from the destination.
            dist[E] = 0;
            while (!Q.isEmpty()) {
                final Edge cur = Q.poll();
                for (int i = 0; i < len[cur.cell]; i++) {
                    int next = adj[cur.cell][i];
                    int nextDist = dist[cur.cell] + cost[cur.cell][next];
                    if (dist[next] == INF || nextDist < dist[next]) {
                        dist[next] = nextDist;
                        Q.add(new Edge(nextDist, next));
                    }
                }
            }
            int res = 0;
            for (int i = 1; i <= N; i++)
                if (dist[i] != INF && dist[i] <= T)
                    res++;

            writer.println(res);
        }
        writer.flush();
    }
}

class Edge {
    int cost, cell;

    public Edge(int cost, int cell) {
        this.cost = cost;
        this.cell = cell;
    }
}