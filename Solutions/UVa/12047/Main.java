import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    static int p, t;
    static LinkedList<Edge>[] adj = new LinkedList[10010];
    static int[] dist = new int[10010];

    // reverse graph where all edges are reversed.
    static LinkedList<Edge>[] rvAdj = new LinkedList[10010];
    static int[] rvDist = new int[10010];


    // edge info
    static int[] froms = new int[100_010];
    static int[] tos = new int[100_010];
    static int[] costs = new int[100_010];
    static int INF = 1_000_000;
    static int res, numEdges;

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();
        int N, M, s, u, v, c;

        while ((T--) > 0) {
            N = scanner.nextInt();
            M = scanner.nextInt();
            s = scanner.nextInt();
            t = scanner.nextInt();
            p = scanner.nextInt();

            for(int i=1; i <= N; i++)
                adj[i] = new LinkedList<>();
            for(int i=1; i <= N; i++)
                rvAdj[i] = new LinkedList<>();

            numEdges = 0;

            while ((M--) > 0) {
                u = scanner.nextInt();
                v = scanner.nextInt();
                c = scanner.nextInt();
                adj[u].add(new Edge(v, c));
                rvAdj[v].add(new Edge(u, c));
                froms[numEdges] = u;
                tos[numEdges] = v;
                costs[numEdges] = c;
                numEdges++;
            }

            Arrays.fill(dist, 1, N + 1, INF);
            Arrays.fill(rvDist, 1, N + 1, INF);

            PriorityQueue<Edge> pq = new PriorityQueue<>(1, new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return Integer.compare(o1.cost, o2.cost);
                }
            });

            pq.add(new Edge(s, 0));
            dist[s] = 0;
            while (!pq.isEmpty()) {
                final Edge cur = pq.poll();
                int curNode = cur.dst;
                for(Edge nextEdge : adj[curNode]) {
                    int nextCost = dist[curNode] + nextEdge.cost;
                    if (nextCost < dist[nextEdge.dst]) {
                        dist[nextEdge.dst] = nextCost;
                        pq.add(new Edge(nextEdge.dst, nextCost));
                    }
                }
            }

            pq.add(new Edge(t, 0));
            rvDist[t] = 0;
            while (!pq.isEmpty()) {
                final Edge cur = pq.poll();
                int curNode = cur.dst;
                for(Edge nextEdge : rvAdj[curNode]) {
                    int nextCost = rvDist[curNode] + nextEdge.cost;
                    if (nextCost < rvDist[nextEdge.dst]) {
                        rvDist[nextEdge.dst] = nextCost;
                        pq.add(new Edge(nextEdge.dst, nextCost));
                    }
                }
            }

            res = -1;

            // go through all edges
            for (int i = 0; i < numEdges; i++) {
                int from = froms[i];
                int to = tos[i];
                if ((dist[from] + costs[i] + rvDist[to]) <= p && res < costs[i])
                    res = costs[i];
            }

            writer.println(res);
        }
        writer.flush();
    }
}

class Edge {
    int dst;
    int cost;

    public Edge(int dst, int cost) {
        this.dst = dst;
        this.cost = cost;
    }
}