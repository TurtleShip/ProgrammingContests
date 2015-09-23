import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

/*
    mem[x][bitMask]
    = The best satisfaction you can get from now on when you start with
      dish 'x' and took dishes in 'bitMask' already.
 */
public class D {
    static long[] sat;
    static long[][] bonus;
    static long[][] mem;
    static long INF = -1L;
    static int N, M;

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));

        N = sc.nextInt();
        M = sc.nextInt();
        int K = sc.nextInt();

        sat = new long[N];
        bonus = new long[N][N];
        mem = new long[N][1 << N];
        for (int i = 0; i < N; i++)
            sat[i] = sc.nextLong();

        for (int i = 0; i < K; i++)
            bonus[sc.nextInt() - 1][sc.nextInt() - 1] = sc.nextLong();

        for (int i = 0; i < N; i++)
            Arrays.fill(mem[i], INF);

        long res = 0L;
        for (int i = 0; i < N; i++)
            res = Math.max(res, sat[i] + find(i, 1 << i, 1));

        System.out.println(res);
    }

    public static long find(int curDish, int bitMask, int used) {
        if (used == M) return 0;

        if (mem[curDish][bitMask] == INF) {
            mem[curDish][bitMask] = 0;
            for (int nextDish = 0; nextDish < N; nextDish++) {
                if ((bitMask & (1 << nextDish)) == 0) {
                    mem[curDish][bitMask] = Math.max(mem[curDish][bitMask],
                        sat[nextDish] + bonus[curDish][nextDish] +
                            find(nextDish, bitMask | (1 << nextDish), used + 1));
                }
            }
        }

        return mem[curDish][bitMask];
    }
}
