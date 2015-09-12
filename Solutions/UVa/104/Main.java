import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        while (scanner.hasNextInt()) {
            final int N = scanner.nextInt();
            final Arbitrage arbitrage = new Arbitrage(N);
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    if (i == j) arbitrage.setConversion(i, j, 1.0);
                    else arbitrage.setConversion(i, j, scanner.nextDouble());
            writer.println(arbitrage.solve());
        }
        writer.flush();
    }
}

class Arbitrage {
    double[][] conversion; // conversion[x][y] = conversion rate from changing currency x to y
    /*
        best[x][y][step]
        = the best conversion rate you can get from sequence of length 'step' that starts at
        currency x and ends at currency y
     */
    double[][][] best;
    /*
        parent[x][y][step]
        = the currency immediately before 'y' in the sequence that yields best[x][y][step]
     */
    int[][][] parent;
    int N;

    public Arbitrage(int N) {
        this.N = N;
        conversion = new double[N + 1][N + 1];
        best = new double[N + 1][N + 1][N + 1];
        parent = new int[N + 1][N + 1][N + 1];
    }

    public void setConversion(int x, int y, double rate) {
        conversion[x][y] = rate;
    }


    public String solve() {

        // initialize best
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                best[i][j][1] = conversion[i][j];
                parent[i][j][1] = i;
            }

        // use dp
        boolean foundProfit = false;
        int seqLength = 0;
        int target = 0;
        for (int step = 2; !foundProfit && step <= N; step++) {
            for (int start = 1; !foundProfit && start <= N; start++) {
                for (int end = 1; !foundProfit && end <= N; end++) {
                    best[start][end][step] = 0.0;
                    for (int mid = 1; mid <= N; mid++) {
                        double curRate = best[start][mid][step - 1] * best[mid][end][1];
                        if (curRate > best[start][end][step]) {
                            best[start][end][step] = curRate;
                            parent[start][end][step] = mid;
                        }
                    }
                    if (start == end && best[start][end][step] > 1.01) {
                        foundProfit = true;
                        target = start;
                        seqLength = step;
                    }
                }
            }
        }

        if (foundProfit) {
            Stack<Integer> stack = new Stack<>();
            stack.push(target);
            int cur = target;
            while (seqLength > 0) {
                stack.push(parent[target][cur][seqLength]);
                cur = parent[target][cur][seqLength];
                seqLength--;
            }

            final StringBuilder res = new StringBuilder(Integer.toString(stack.pop()));
            while (!stack.empty()) {
                res.append(" ").append(Integer.toString(stack.pop()));
            }
            return res.toString();
        } else {
            return "no arbitrage sequence exists";
        }
    }
}