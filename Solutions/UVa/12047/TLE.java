import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static int p, t;
    static int[][] adj = new int[10010][10010];
    static int[][] cost = new int[10010][10010];
    static int[] len = new int[100010];
    static int res;

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

            while ((M--) > 0) {
                u = scanner.nextInt();
                v = scanner.nextInt();
                c = scanner.nextInt();
                adj[u][len[u]++] = v;
                cost[u][v] = c;
            }

            res = -1;
            find(s, 0, -1);
            writer.println(res);
        }
        writer.flush();
    }

    static void find(int cur, int curCost, int maxCost) {
        if (cur == t) {
            res = Math.max(res, maxCost);
            return;
        }

        for (int i = 0; i < len[cur]; i++) {
            int next = adj[cur][i];
            int nextCost = curCost + cost[cur][next];
            if (nextCost > p) continue;
            find(next, nextCost, (maxCost > cost[cur][next]) ? maxCost : cost[cur][next]);
        }

    }
}