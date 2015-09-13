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
        int R, C;

        while ((R = scanner.nextInt()) != 0 & (C = scanner.nextInt()) != 0) {
            final int bombR = scanner.nextInt();

            final Graph graph = new Graph(R, C);
            for (int i = 0; i < bombR; i++) {
                int r = scanner.nextInt();
                int bombC = scanner.nextInt();
                for (int j = 0; j < bombC; j++) {
                    int c = scanner.nextInt();
                    graph.markMine(r, c);
                }
            }

            final int res = graph.solve(scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
            writer.println(res);
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

class Graph {
    static int[][] moves = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    int R, C;
    boolean[][] canGo;
    int[][] dist;

    public Graph(int r, int c) {
        R = r;
        C = c;
        canGo = new boolean[R][C];
        dist = new int[R][C];
        for (int i = 0; i < R; i++)
            Arrays.fill(canGo[i], true);
    }

    public void markMine(int r, int c) {
        canGo[r][c] = false;
    }

    public int solve(int srcR, int srcC, int dstR, int dstC) {

        Queue<Loc> queue = new LinkedList<>();
        queue.add(new Loc(srcR, srcC));
        for (int r = 0; r < R; r++)
            Arrays.fill(dist[r], -1);
        dist[srcR][srcC] = 0;
        boolean foundDst = srcR == dstR && srcC == dstC;
        while (!queue.isEmpty() && !foundDst) {
            Loc cur = queue.poll();
            for (int[] move : moves) {
                int nextR = cur.r + move[0];
                int nextC = cur.c + move[1];
                if (0 <= nextR && nextR < R &&
                    0 <= nextC && nextC < C &&
                    canGo[nextR][nextC] &&
                    dist[nextR][nextC] == -1) {
                    dist[nextR][nextC] = dist[cur.r][cur.c] + 1;
                    foundDst |= nextR == dstR && nextC == dstC;
                    queue.add(new Loc(nextR, nextC));
                }
            }
        }

        return dist[dstR][dstC];
    }
}