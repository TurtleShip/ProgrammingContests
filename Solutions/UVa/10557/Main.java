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

        int N, INF = -1_000_000;
        int[] energies = new int[110];
        int[][] adj = new int[110][110];
        int[] len = new int[110];
        int[] dist = new int[110];
        boolean[] canReach = new boolean[110];

        while ((N = scanner.nextInt()) != -1) {

            for (int i = 1; i <= N; i++) {
                energies[i] = scanner.nextInt();
                len[i] = scanner.nextInt();
                for (int j = 0; j < len[i]; j++)
                    adj[i][j] = scanner.nextInt();
            }

            Arrays.fill(canReach, 1, N + 1, false);
            Queue<Integer> queue = new LinkedList<>();
            queue.add(1);
            canReach[1] = true;

            while (!queue.isEmpty()) {
                int cur = queue.poll();
                for (int i = 0; i < len[cur]; i++) {
                    int next = adj[cur][i];
                    if (!canReach[next]) {
                        canReach[next] = true;
                        queue.add(next);
                    }
                }
            }

            if (!canReach[N]) {
                writer.println("hopeless");
                continue;
            }

            /*
                 Just brute force : relax so many times that you positive cycles
                 will eventually make you reach the destination if possible :)
             */
            Arrays.fill(dist, 1, N + 1, INF);
            dist[1] = 100; // starts with 100 energy
            for (int t = 0; t < 500 * N; t++) {
                for (int v = 1; v <= N; v++) {
                    if (!canReach[v]) continue;
                    if (dist[v] <= 0) continue;
                    for (int i = 0; i < len[v]; i++) {
                        int next = adj[v][i];
                        if (!canReach[next]) continue;
                        int nextDist = dist[v] + energies[next];
                        if (nextDist > dist[next] && nextDist > 0) {
                            dist[next] = nextDist;
                        }
                    }
                }
            }

            if (dist[N] > 0) writer.println("winnable");
            else writer.println("hopeless");
        }

        writer.flush();
    }
}
