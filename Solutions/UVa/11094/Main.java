import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// UVa - 11094 Continents
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2035
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        while (scanner.hasNext()) {
            int M = scanner.nextInt();
            int N = scanner.nextInt();
            final String[] rows = new String[M];
            for (int i = 0; i < M; i++) {
                rows[i] = scanner.next();
            }
            boolean[][] isLand = new boolean[M][N];
            int kingR = scanner.nextInt();
            int kingC = scanner.nextInt();
            char land = rows[kingR].charAt(kingC);
            for (int r = 0; r < M; r++)
                for (int c = 0; c < N; c++)
                    isLand[r][c] = rows[r].charAt(c) == land;

            final World world = new World(M, N, isLand);
            writer.printf("%d\n", world.solve(kingR, kingC));
        }
        writer.flush();
    }
}

class World {
    static int[][] moves = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int M, N;
    boolean[][] isVisited;
    boolean[][] isLand;
    int[] continentSize;
    int numContinent;

    public World(int m, int n, boolean[][] isLand) {
        M = m;
        N = n;
        isVisited = new boolean[M][N];
        this.isLand = isLand;
        continentSize = new int[M * N];
    }

    public int solve(int kingR, int kingC) {
        for (int i = 0; i < M; i++)
            Arrays.fill(isVisited[i], false);
        Arrays.fill(continentSize, 0);

        int best = 0;

        // first, populate the king's continent
        fill(kingR, kingC, 0);
        numContinent = 1;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (!isVisited[r][c] && isLand[r][c]) {
                    isVisited[r][c] = true;
                    fill(r, c, numContinent);
                    best = Math.max(best, continentSize[numContinent]);
                    numContinent++;
                }
            }
        }
        return best;
    }

    private void fill(int r, int c, int id) {
        continentSize[id]++;
        for (int[] move : moves) {
            int nr = r + move[0];
            int nc = (c + move[1] + N) % N; // loop around
            if (0 <= nr && nr < M && 0 <= nc && nc < N && !isVisited[nr][nc] && isLand[nr][nc]) {
                isVisited[nr][nc] = true;
                fill(nr, nc, id);
            }
        }
    }
}