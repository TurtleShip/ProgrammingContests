import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();
        int N, M, INF = 1_000_000_000;

        while ((T--) > 0) {
            N = scanner.nextInt();
            M = scanner.nextInt();
            final BellmanFord bf = new BellmanFord(N, INF);

            for (int i = 0; i < M; i++) {
                bf.addEdge(new Edge(scanner.nextInt(), scanner.nextInt(), scanner.nextInt()));
            }

            writer.println(bf.hasNegativeCycle() ? "possible" : "not possible");
        }
        writer.flush();
    }
}

/** 
 * An implementation of bellman-ford.
 * Edges are assumed to be 0-indexed.
 */
class BellmanFord {
    LinkedList<Edge> edges;
    int[] dist;
    int N;
    int INF;

    /**
     * @param N   Number of nodes in this Graph.
     * @param INF An integer to be used as 'infinity'.
     *            Pick a number that is gauranteed to be not an edge cost.
     */
    public BellmanFord(int N, int INF) {
        this.N = N;
        this.INF = INF;
        dist = new int[N + 10];
        edges = new LinkedList<>();
    }

    public void addEdge(Edge edge) {
        edges.add(edge);
    }

    // N = number of nodes in the Graph
    public boolean hasNegativeCycle() {
        Arrays.fill(dist, INF);
        for (int i = 0; i < N; i++) {
            for (Edge edge : edges) {
                int nextCost = dist[edge.from] + edge.cost;
                if (dist[edge.to] == INF || nextCost < dist[edge.to]) {
                    dist[edge.to] = nextCost;
                }
            }
        }
        for (Edge edge : edges) {
            int nextCost = dist[edge.from] + edge.cost;
            if (nextCost < dist[edge.to]) {
                return true;
            }
        }
        return false;
    }
}

class Edge {
    int from;
    int to;
    int cost;

    public Edge(int from, int to, int cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}