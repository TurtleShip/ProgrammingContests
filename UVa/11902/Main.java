import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// 11902 - Dominator
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=3053
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {

            int N = scanner.nextInt();

            boolean[][] adj = new boolean[N][N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    adj[i][j] = scanner.nextInt() == 1;

            final Solver solver = new Solver(adj);
            final boolean[][] dominate = solver.solve();
            final String line = printLine(N);
            writer.printf("Case %d:\n", cid);
            writer.println(line);
            for (int i = 0; i < N; i++) {
                writer.print("|");
                for (int j = 0; j < N; j++) {
                    writer.print(dominate[i][j] ? "Y|" : "N|");
                }
                writer.println();
                writer.println(line);
            }

        }
        writer.flush();
    }

    public static String printLine(int N) {
        StringBuilder line = new StringBuilder("+");
        for (int i = 0; i < (2 * N - 1); i++)
            line = line.append("-");
        return line.append("+").toString();
    }
}


class Solver {
    // adj[x][y] = true if node x and node y have an edge between them.
    private boolean[][] adj;
    // ways[x][y] = true if node x dominates node y.
    private boolean[][] dominate;
    private boolean[] canReach;
    private boolean[] isVisited;

    private int N;

    public Solver(boolean[][] adj) {
        this.adj = adj;
        this.N = adj.length;
        this.dominate = new boolean[N][N];
        this.canReach = new boolean[N];
        this.isVisited = new boolean[N];
    }

    public boolean[][] solve() {
        for (int i = 0; i < N; i++)
            Arrays.fill(dominate[i], false);

        // Find all nodes reachable from the start node.
        Arrays.fill(canReach, false);
        canReach[0] = true;
        reach(0);

        for (int cut = 0; cut < N; cut++) {
            Arrays.fill(isVisited, false);
            visit(0, cut);
            for (int end = 0; end < N; end++) {
                if (canReach[end] && !isVisited[end]) {
                    dominate[cut][end] = true;
                }
            }
        }
        return dominate;
    }

    private void reach(int cur) {
        for (int next = 0; next < N; next++) {
            if (adj[cur][next] && !canReach[next]) {
                canReach[next] = true;
                reach(next);
            }
        }
    }

    // visit all nodes from 'cur' node without visiting 'cut' node.
    private void visit(int cur, int cut) {
        if (cur != cut) {
            isVisited[cur] = true;
            for (int next = 0; next < N; next++) {
                if (adj[cur][next] && !isVisited[next]) {
                    visit(next, cut);
                }
            }
        }
    }

}