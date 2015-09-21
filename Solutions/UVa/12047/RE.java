import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    static int p, t;
    static int[][] adj = new int[10010][10010];
    static int[][] cost = new int[10010][10010];
    static int[] dist = new int[10010];
    static int[] len = new int[10010];

    // reverse graph where all edges are reversed.
    static int[][] rvAdj = new int[10010][10010];
    static int[][] rvCost = new int[10010][10010];
    static int[] rvDist = new int[10010];
    static int[] rvLen = new int[10010];

    // edge info
    static int[] froms = new int[100_010];
    static int[] tos = new int[100_010];
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

            Arrays.fill(len, 1, N + 1, 0);
            Arrays.fill(rvLen, 1, N + 1, 0);
            numEdges = 0;

            while ((M--) > 0) {
                u = scanner.nextInt();
                v = scanner.nextInt();
                c = scanner.nextInt();
                adj[u][len[u]++] = v;
                cost[u][v] = c;
                rvAdj[v][rvLen[v]++] = u;
                rvCost[v][u] = c;
                froms[numEdges] = u;
                tos[numEdges] = v;
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
                for (int i = 0; i < len[curNode]; i++) {
                    int nextNode = adj[curNode][i];
                    int nextCost = dist[curNode] + cost[curNode][nextNode];
                    if (nextCost < dist[nextNode]) {
                        dist[nextNode] = nextCost;
                        pq.add(new Edge(nextNode, nextCost));
                    }
                }
            }

            pq.add(new Edge(t, 0));
            rvDist[t] = 0;
            while (!pq.isEmpty()) {
                final Edge cur = pq.poll();
                int curNode = cur.dst;
                for (int i = 0; i < rvLen[curNode]; i++) {
                    int nextNode = rvAdj[curNode][i];
                    int nextCost = rvDist[curNode] + rvCost[curNode][nextNode];
                    if (nextCost < rvDist[nextNode]) {
                        rvDist[nextNode] = nextCost;
                        pq.add(new Edge(nextNode, nextCost));
                    }
                }
            }

            res = -1;

            // go through all edges
            for (int i = 0; i < numEdges; i++) {
                int from = froms[i];
                int to = tos[i];
//                System.out.printf("dist[%d] = %d, rvDist[%d] = %d, cost[%d][%d] = %d, sum = %d, res = %d\n",
//                    from, dist[from], to, rvDist[to], from, to, cost[from][to], dist[from] + cost[from][to] + rvDist[to], res);
                if ((dist[from] + cost[from][to] + rvDist[to]) <= p && res < cost[from][to])
                    res = cost[from][to];
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