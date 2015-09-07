import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {

        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int[][] dist = new int[110][110];
        int INF = 1_000_000;

        int from, to, cid = 1;
        Set<Integer> all = new HashSet<>();


        while ((from = scanner.nextInt()) != 0 && (to = scanner.nextInt()) != 0) {
            // initialize
            all.clear();
            for (int i = 1; i <= 100; i++)
                for (int j = 1; j <= 100; j++)
                    dist[i][j] = INF;
            for (int i = 1; i <= 100; i++)
                dist[i][i] = 0;

            do {
                all.add(from);
                all.add(to);
                dist[from][to] = 1;
            } while ((from = scanner.nextInt()) != 0 & (to = scanner.nextInt()) != 0);

            // run Floyd-Warshall
            for (int mid : all) {
                for (int src : all) {
                    for (int dst : all) {
                        dist[src][dst] = Math.min(dist[src][dst], dist[src][mid] + dist[mid][dst]);
                    }
                }
            }

            int sum = 0;
            int ct = 0;
            for (int src : all)
                for (int dst : all) {
                    if (dst == src) continue;
                    sum += dist[src][dst];
                    ct++;
                }
            double res = (double) sum / (double) ct;
            writer.printf("Case %d: average length between pages = %.3f clicks\n", cid++, res);
        }
        writer.flush();
    }
}
