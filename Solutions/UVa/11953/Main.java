import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

// 11953 - Battleships
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3104
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {

            int N = scanner.nextInt();
            String[] rows = new String[N];
            for (int r = 0; r < N; r++) {
                rows[r] = scanner.next();

            }
            final Solver solver = new Solver(N);
            solver.populateState(rows);
            writer.printf("Case %d: %d\n", cid, solver.solve());
        }
        writer.flush();
    }
}

class Solver {
    static int[][] moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static int CHECKED = 0;
    static int SHIP = 1;
    static int SUNK = 2;
    int[][] state;
    int N;

    public Solver(int N) {
        this.N = N;
        this.state = new int[N][N];
    }

    public void populateState(String[] rows) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char ch = rows[r].charAt(c);
                if (ch == 'x') {
                    state[r][c] = SHIP;
                } else if (ch == '@') {
                    state[r][c] = SUNK;
                } else {
                    state[r][c] = CHECKED;
                }
            }

        }
    }

    public int solve() {
        int res = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (state[r][c] != CHECKED) {
                    boolean hasShip = state[r][c] == SHIP;
                    state[r][c] = CHECKED;
                    hasShip |= fill(r, c);
                    if (hasShip) res++;
                }
            }
        }
        return res;
    }

    private boolean fill(int r, int c) {
        boolean hasShip = false;
        for (int[] move : moves) {
            int nr = r + move[0];
            int nc = c + move[1];
            if (0 <= nr && nr < N && 0 <= nc && nc < N && state[nr][nc] != CHECKED) {
                hasShip |= state[nr][nc] == SHIP;
                state[nr][nc] = CHECKED;
                hasShip |= fill(nr, nc);
            }
        }
        return hasShip;
    }
}