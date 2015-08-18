import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
    Uva 12442 - Forwarding Emails
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3873
 */
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            int N = scanner.nextInt();
            final Solver solver = new Solver(N);
            while ((N--) > 0) {
                solver.link(scanner.nextInt() - 1, scanner.nextInt() - 1);
            }
            final int result = solver.solve();
            writer.printf("Case %d: %d\n", cid, result + 1);
        }
        writer.flush();
    }
}

/*
This is a dfs with cycle check.
Do dfs if this node hasn't been visited before. Otherwise, do full dfs.

imo, this solution got lucky because it doesn't optimize itself for cases where
there is a small cycle and a long line of nodes pointing to it.
ex>
1 <-> 2 <- 3 <- 4 <- 5 <- 6 ....
The solution calls dfs on every node except for node 2.
The solution got lucky because there was no such test case.

A better / more optimal solution would be
1) do dfs with cycle check if the current node has been checked before.
2) While doing dfs, utilize information from previous 'dfs's if possible.

I am too lazy to do step 2). :p
 */

class Solver {
    int N;
    int[] next; // next[x] = the id of node that node x forwards an email
    boolean[] isVisited; // isVisited[x] = true if it is visited in the current dfs
    boolean[] isChecked; // isChecked[x] = true if node x has been visited as a part of any dfs.

    public Solver(int n) {
        N = n;
        next = new int[N];
        isVisited = new boolean[N];
        isChecked = new boolean[N];
//        Arrays.fill(next, -1);
        Arrays.fill(isVisited, false);
        Arrays.fill(isChecked, false);
    }

    public void link(int from, int to) {
        next[from] = to;
    }

    public int solve() {
        int targetId = -1;
        int longest = 0;
        for (int i = 0; i < N; i++) {
            if (isChecked[i]) continue;
            int curLength = dfs(i);
            if (curLength > longest) {
                longest = curLength;
                targetId = i;
            }
        }
        return targetId;
    }

    private int dfs(int cur) {
//        if (cur == -1) return 0;
        if (isVisited[cur]) return 0;
        isVisited[cur] = isChecked[cur] = true;
        int res = 1 + dfs(next[cur]);
        isVisited[cur] = false;
        return res;
    }
}