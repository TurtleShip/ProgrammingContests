import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// UVa 11080 Place the Guards
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2021
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            int N = scanner.nextInt();
            int E = scanner.nextInt();
            final Place place = new Place(N);
            for (int i = 0; i < E; i++) {
                int from = scanner.nextInt();
                int to = scanner.nextInt();
                place.link(from, to);
            }
            int res = place.solve();
            writer.println(res);
        }
        writer.flush();
    }
}

class Place {
    static int notColored = -1;
    static int guard = 0;

    // V <= 200. V^2 is small enough to use adj matrix.
    boolean adj[][];
    int N;
    int color[];
    boolean visited[];

    public Place(int n) {
        N = n;
        adj = new boolean[N][N];
        color = new int[N];
        visited = new boolean[N];
        Arrays.fill(color, notColored);
    }

    public void link(int x, int y) {
        adj[x][y] = adj[y][x] = true;
    }

    public int solve() {
        // do coloring
        boolean canPlace = true;
        int res = 0;
        for (int i = 0; canPlace && i < N; i++) {
            if (color[i] != notColored) continue;
            canPlace &= place(i, guard);
            if (canPlace) {
                int totalYes = 0;
                int totalNo = 0;
                for (int j = 0; j < N; j++) {
                    if (visited[j]) {
                        if (color[j] == guard) totalYes++;
                        else totalNo++;
                        visited[j] = false;
                    }
                }
                // edge case for a junction without any street
                if(totalYes + totalNo == 1) res++;
                else res += Math.min(totalYes, totalNo);
            } else {
                res = -1;
            }
        }
        return res;
    }

    private boolean place(int idx, int myColor) {
        int curColor = color[idx];
        if (curColor != notColored) {
            return curColor == myColor;
        } else {
            color[idx] = myColor;
            visited[idx] = true;
            int nextColor = (myColor + 1) % 2;
            boolean canPlace = true;
            for (int next = 0; next < N; next++)
                if (adj[idx][next])
                    canPlace &= place(next, nextColor);
            return canPlace;
        }
    }
}