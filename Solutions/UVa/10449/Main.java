import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, R, from, to, Q, query, cid =1, INF = 100_000_000;
        int[] junc = new int[250];
        Edge[][] adj = new Edge[250][250];
        boolean[] canReach = new boolean[250];
        boolean[] isInNegCycle = new boolean[250];
        int[] len = new int[250];
        int[] dist = new int[250];
        int[] moreDist;

        while (scanner.hasNextInt()) {
            writer.printf("Set #%d\n", cid++);
            N = scanner.nextInt();
            for (int i = 1; i <= N; i++)
                junc[i] = scanner.nextInt();

            Arrays.fill(len, 1, N + 1, 0);
            Arrays.fill(canReach, 1, N + 1, false);
            Arrays.fill(isInNegCycle, 1, N + 1, false);
            Arrays.fill(dist, 1, N + 1, INF);

            R = scanner.nextInt();
            while ((R--) > 0) {
                from = scanner.nextInt();
                to = scanner.nextInt();
                int diff = junc[to] - junc[from];
                int cost = diff * diff * diff;
                adj[from][len[from]++] = new Edge(to, cost);
            }

            Queue<Integer> queue = new LinkedList<>();
            queue.add(1);
            canReach[1] = true;
            while (!queue.isEmpty()) {
                int cur = queue.poll();
                for (int i = 0; i < len[cur]; i++) {
                    final Edge edge = adj[cur][i];
                    if (!canReach[edge.dst]) {
                        canReach[edge.dst] = true;
                        queue.add(edge.dst);
                    }
                }
            }
//            for(int i=1; i <= N; i++) {
//                System.out.printf("canReach[%d] = %s\n", i, canReach[i] ? "YES" : "NO");
//            }
            // relax edges
            dist[1] = 0;
            for (int i = 0; i < N - 1; i++) {
                for (int v = 1; v <= N; v++) {
                    if (!canReach[v]) continue;
                    for (int j = 0; j < len[v]; j++) {
                        Edge nextEdge = adj[v][j];
                        if (!canReach[nextEdge.dst]) continue;
                        dist[nextEdge.dst] = Math.min(dist[nextEdge.dst], dist[v] + nextEdge.cost);
                    }
                }
            }

            moreDist = Arrays.copyOf(dist, N + 1);
            // relax again
            for (int i = 0; i < N - 1; i++) {
                for (int v = 1; v <= N; v++) {
                    if (!canReach[v]) continue;
                    for (int j = 0; j < len[v]; j++) {
                        Edge nextEdge = adj[v][j];
                        if (!canReach[nextEdge.dst]) continue;
                        moreDist[nextEdge.dst] = Math.min(moreDist[nextEdge.dst], moreDist[v] + nextEdge.cost);
                    }
                }
            }

            for (int i = 1; i <= N; i++) {
                isInNegCycle[i] = moreDist[i] < dist[i];
            }

            Q = scanner.nextInt();
            while ((Q--) > 0) {
                query = scanner.nextInt();
//                System.out.printf("Dist[%d] = %d\n", query, dist[query]);
                if (isInNegCycle[query] || !canReach[query] || dist[query] < 3) writer.println("?");
                else writer.println(dist[query]);
            }
        }

        writer.flush();
    }
}

class Edge {
    int dst, cost;

    public Edge(int dst, int cost) {
        this.dst = dst;
        this.cost = cost;
    }
}