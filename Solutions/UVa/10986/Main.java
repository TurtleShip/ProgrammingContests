import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int tt = scanner.nextInt();
        int N, M, S, T, INF = -1;
        int[] dist = new int[20_010];
        LinkedList<Edge>[] adj = new LinkedList[20_010];
        for (int cid = 1; cid <= tt; cid++) {
            N = scanner.nextInt();
            M = scanner.nextInt();
            S = scanner.nextInt();
            T = scanner.nextInt();

            for (int i = 0; i < N; i++)
                adj[i] = new LinkedList<>();

            for (int i = 0; i < N; i++)
                dist[i] = INF;

            for (int i = 0; i < M; i++) {
                int from = scanner.nextInt();
                int to = scanner.nextInt();
                int cost = scanner.nextInt();
                adj[from].add(new Edge(to, cost));
                adj[to].add(new Edge(from, cost));
            }

            PriorityQueue<Edge> Q = new PriorityQueue<>(1, new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return Integer.compare(o1.cost, o2.cost);
                }
            });

            dist[S] = 0;
            Q.add(new Edge(S, 0));

            while (!Q.isEmpty()) {
                Edge cur = Q.poll();
                int curNode = cur.node;
                for (final Edge nextEdge : adj[curNode]) {
                    int nextDist = dist[curNode] + nextEdge.cost;
                    if (dist[nextEdge.node] == INF ||
                        nextDist < dist[nextEdge.node]) {
                        dist[nextEdge.node] = nextDist;
                        Q.add(new Edge(nextEdge.node, nextDist));
                    }
                }
            }

            final String res = dist[T] == INF ? "unreachable" : Integer.toString(dist[T]);
            writer.printf("Case #%d: %s\n", cid, res);
        }
        writer.flush();
    }
}

class Edge {
    int node;
    int cost;

    public Edge(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }
}