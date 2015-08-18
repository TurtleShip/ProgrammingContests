import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

// Uva 11906 - Knight in a War Grid
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3057
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            final Board board = new Board(scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
            int W = scanner.nextInt();
            for (int i = 0; i < W; i++) {
                board.isWet[scanner.nextInt()][scanner.nextInt()] = true;
            }
            board.solve();
            writer.printf("Case %d: %d %d\n", cid, board.even, board.odd);
        }
        writer.flush();
    }
}

class Board {
    int[][] board;
    boolean[][] isChecked;
    boolean[][] isWet;
    int[][] moves;
    int even;
    int odd;
    int R, C, M, N;

    public Board(int R, int C, int m, int n) {
        this.R = R;
        this.C = C;
        this.M = Math.min(m, n);
        this.N = Math.max(m, n);
        this.board = new int[R][C];
        this.isChecked = new boolean[R][C];
        this.isWet = new boolean[R][C];
        this.even = this.odd = 0;

        // I got a few Wrong Answers because of this.
        if (M == 0) {
            this.moves = new int[][]{{M, N}, {M, -N}, {N, M}, {-N, M}};
        } else if (M == N) {
            this.moves = new int[][]{{M, N}, {M, -N}, {-M, N}, {-M, -N}};
        } else {
            this.moves = new int[][]{{M, N}, {M, -N}, {-M, N}, {-M, -N},
                {N, M}, {N, -M}, {-N, M}, {-N, -M}};
        }


    }

    public void solve() {
        // The problem description guarantees that the starting spot (0,0) is not wet.
        // x + y > 0
        isChecked[0][0] = true;
        check(0, 0);
    }

    private void check(int row, int col) {
        int total = 0;
        for (int i = 0; i < moves.length; i++) {
            int nextR = row + moves[i][0];
            int nextC = col + moves[i][1];
            if (isInRange(nextR, nextC) && !isWet[nextR][nextC]) {
                total++;
                if (!isChecked[nextR][nextC]) {
                    isChecked[nextR][nextC] = true;
                    check(nextR, nextC);
                }
            }
        }
        if (total % 2 == 0) even++;
        else odd++;
    }

    private boolean isInRange(int row, int col) {
        return 0 <= row && row < R && 0 <= col && col < C;
    }
}