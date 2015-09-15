import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int L, U, R, cid = 1;
        int INF = 1_000_000;
        int[] dist = new int[10_000];
        int[] buttons = new int[10_000];
        while (!((L = sc.nextInt()) == 0 & (U = sc.nextInt()) == 0 & (R = sc.nextInt()) == 0)) {
            Arrays.fill(dist, INF);
            for (int i = 0; i < R; i++)
                buttons[i] = sc.nextInt();

            Queue<Integer> Q = new LinkedList<>();
            Q.add(L);
            dist[L] = 0;
            while (!Q.isEmpty()) {
                int cur = Q.poll();
                if (cur == U) break;

                for (int i = 0; i < R; i++) {
                    int next = (cur + buttons[i]) % 10_000;
                    if (dist[next] == INF) {
                        dist[next] = dist[cur] + 1;
                        Q.add(next);
                    }
                }
            }
            writer.printf("Case %d: ", cid++);
            writer.println(dist[U] == INF ? "Permanently Locked" : dist[U]);
        }
        writer.flush();
    }
}