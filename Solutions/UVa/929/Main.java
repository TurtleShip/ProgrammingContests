import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

/*
    This problem lacks description.
    From the problem statement, it is not clear whether
    I should consider the cost to start at [0][0].
    I learned I should consider it by running through sample inputs
    at uDebug.
 */
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int R, C, T, INF = 1_000_000_000;
        int[][] dist = new int[1010][1010];
        int[][] cost = new int[1010][1010];
        int[][] moves = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        T = scanner.nextInt();
        while ((T--) > 0) {
            R = scanner.nextInt();
            C = scanner.nextInt();
            for (int r = 0; r < R; r++)
                for (int c = 0; c < C; c++)
                    dist[r][c] = INF;

            for (int r = 0; r < R; r++)
                for (int c = 0; c < C; c++)
                    cost[r][c] = scanner.nextInt();

            PriorityQueue<Edge> Q = new PriorityQueue<>(R * C, new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return Integer.compare(o1.cost, o2.cost);
                }
            });

            dist[0][0] = cost[0][0];
            Q.add(new Edge(0, 0, cost[0][0]));

            while (!Q.isEmpty()) {
                Edge cur = Q.poll();

                // Short circuiting while loop as below got me from TLE to
                // passing at 2.875 sec ( the time limit was 3 sec )
                if (cur.r == R - 1 && cur.c == C - 1) break;

                for (int[] move : moves) {
                    int nextR = cur.r + move[0];
                    int nextC = cur.c + move[1];
                    if (0 <= nextR && nextR < R &&
                        0 <= nextC && nextC < C &&
                        dist[nextR][nextC] > (dist[cur.r][cur.c] + cost[nextR][nextC])) {
                        dist[nextR][nextC] = dist[cur.r][cur.c] + cost[nextR][nextC];
                        Q.add(new Edge(nextR, nextC, dist[nextR][nextC]));
                    }
                }
            }
            writer.println(dist[R - 1][C - 1]);
        }

        writer.flush();
    }
}

class Edge {
    int r, c, cost;

    public Edge(int r, int c, int cost) {
        this.r = r;
        this.c = c;
        this.cost = cost;
    }
}