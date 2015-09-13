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
            Grid grid = new Grid(R, C);
            for (int r = 1; r <= R; r++)
                for (int c = 1; c <= C; c++) {
                    if (scanner.nextInt() == 1)
                        grid.markMine(r, c);
                }
            writer.println(grid.solve(scanner.nextInt() + 1, scanner.nextInt() + 1,
                scanner.nextInt() + 1, scanner.nextInt() + 1, scanner.next()));
        }
        writer.flush();
    }
}

/*
    There are at most 50 x 50 = 2,500 blocks.
    There are 4 possible directions you can face per block.
    2,500 * 4 = 10,000 possible states.
    Simulation with memoization will work.


    To handle cases where isEmpty is checking blocks out side of grid, we are going to
    "pad" the grid. i.e. we are going to use 1-based index.
 */
class Grid {
    static int LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3;
    static int[][] MOVES = {
        {0, -1}, {-1, 0}, {0, 1}, {1, 0}
    };
    static int UNCHECKED = -1;
    int R, C;
    boolean[][] isEmpty;
    int[][][] dist;

    public Grid(int R, int C) {
        this.R = R;
        this.C = C;
        isEmpty = new boolean[R + 10][C + 10];
        dist = new int[R + 10][C + 10][4];

        for (int r = 0; r <= R + 1; r++)
            Arrays.fill(isEmpty[r], true);

        for (int r = 0; r <= R + 1; r++)
            for (int c = 0; c <= C + 1; c++)
                for (int dir = 0; dir <= 3; dir++)
                    dist[r][c][dir] = UNCHECKED;
    }

    public void markMine(int r, int c) {
        isEmpty[r][c] = false;
    }

    /*
        srcR, srcC, dstR, dstC must be provided as 1-indexed.
     */
    public int solve(int srcR, int srcC, int dstR, int dstC, String rawDir) {

        // damn edge cases
        if (!isEmpty[srcR][srcC]) return -1;
        if (!isEmpty[dstR][dstC]) return -1;
        if (srcR == dstR && srcC == dstC) {
            return 0;
        }

        int dir = getDir(rawDir);

        Queue<Move> queue = new LinkedList<>();
        queue.add(new Move(srcR, srcC, dir));
        dist[srcR][srcC][dir] = 0;

        int res = -1;
        while (!queue.isEmpty()) {
            final Move cur = queue.poll();
            if (cur.r == dstR && cur.c == dstC) {
                res = dist[cur.r][cur.c][cur.dir];
                break;
            }

            /*
                We need to check that we can keep going.
                If we get blocked at go=2, then we cannot proceed to go=3.
             */
            for (int go = 1; go <= 3; go++) {
                int nextR = cur.r + MOVES[cur.dir][0] * go;
                int nextC = cur.c + MOVES[cur.dir][1] * go;
                if (!canGo(nextR, nextC)) break;
                if (dist[nextR][nextC][cur.dir] == UNCHECKED) {
                    dist[nextR][nextC][cur.dir] = dist[cur.r][cur.c][cur.dir] + 1;
                    queue.add(new Move(nextR, nextC, cur.dir));
                }
            }

            // try turning
            int leftTurn = turnLeft(cur.dir);
            int rightTurn = turnRight(cur.dir);
            if (dist[cur.r][cur.c][leftTurn] == UNCHECKED) {
                dist[cur.r][cur.c][leftTurn] = dist[cur.r][cur.c][cur.dir] + 1;
                queue.add(new Move(cur.r, cur.c, leftTurn));
            }
            if (dist[cur.r][cur.c][rightTurn] == UNCHECKED) {
                dist[cur.r][cur.c][rightTurn] = dist[cur.r][cur.c][cur.dir] + 1;
                queue.add(new Move(cur.r, cur.c, rightTurn));
            }
        }
        return res;
    }

    private int turnLeft(int dir) {
        return (dir - 1 + 4) % 4;
    }

    private int turnRight(int dir) {
        return (dir + 1) % 4;
    }

    private int getDir(final String rawDir) {
        int dir;
        switch (rawDir) {
            case "north":
                dir = UP;
                break;
            case "west":
                dir = LEFT;
                break;
            case "south":
                dir = DOWN;
                break;
            case "east":
                dir = RIGHT;
                break;
            default:
                throw new RuntimeException("WTF");
        }
        return dir;
    }


    /*
        For a given block (r,c), block itself and blocks on its left, upper left, and up should be reachable.
        Fuck. Robot cannot move along the border due to its diameter.
     */
    private boolean canGo(int r, int c) {
        return 1 < r && r <= R && 1 < c && c <= C && isEmpty[r][c] &&
            isEmpty[r][c - 1] && isEmpty[r - 1][c - 1] && isEmpty[r - 1][c];
    }


}

class Move {
    int r, c, dir;

    public Move(int r, int c, int dir) {
        this.r = r;
        this.c = c;
        this.dir = dir;
    }
}