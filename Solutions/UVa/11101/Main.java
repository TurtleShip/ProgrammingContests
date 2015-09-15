import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int P;
        int[][] dist = new int[2010][2010];
        int[][] moves = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        int INF = 1_000_000;

        while ((P = scanner.nextInt()) != 0) {

            for (int r = 0; r <= 2000; r++)
                for (int c = 0; c <= 2000; c++)
                    dist[r][c] = INF;

            final Queue<Loc> Q = new LinkedList<>();
            for (int i = 0; i < P; i++) {
                int r = scanner.nextInt();
                int c = scanner.nextInt();
                dist[r][c] = 0;
                Q.add(new Loc(r, c));
            }

            while (!Q.isEmpty()) {
                Loc cur = Q.poll();
                for (int[] move : moves) {
                    int nextR = cur.r + move[0];
                    int nextC = cur.c + move[1];
                    if (0 <= nextR && nextR <= 2000 &&
                        0 <= nextC && nextC <= 2000 &&
                        dist[nextR][nextC] == INF) {
                        dist[nextR][nextC] = dist[cur.r][cur.c] + 1;
                        Q.add(new Loc(nextR, nextC));
                    }
                }
            }

            int best = INF;
            P = scanner.nextInt();
            for (int i = 0; i < P; i++) {
                best = Math.min(best, dist[scanner.nextInt()][scanner.nextInt()]);
            }
            writer.println(best);
        }

        writer.flush();
    }
}

class Loc {
    int r, c;

    public Loc(int r, int c) {
        this.r = r;
        this.c = c;
    }
}