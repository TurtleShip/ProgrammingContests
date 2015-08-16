import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// 12086 - Potentiometers
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=3238
class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N;
        int caseId = 1;
        while ((N = scanner.nextInt()) != 0) {
            if (caseId > 1) {
                writer.println();
            }

            final SegTree tree = new SegTree(N);
            for (int i = 0; i < N; i++) {
                int val = scanner.nextInt();
                tree.update(i, val);
            }
            writer.printf("Case %d:\n", caseId++);
            // Don't for get to decrease index by 1 when using seg tree.
            String command;
            while (!(command = scanner.next()).equals("END")) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();

                if (command.equals("S")) {
                    tree.update(x - 1, y);
                } else {
                    writer.println(tree.query(x - 1, y - 1));
                }
            }
        }
        writer.flush();
    }
}


class SegTree {
    int N;
    int[] sum;
    int[] arr;

    public SegTree(int N) {
        this.N = N;
        this.arr = new int[N];
        sum = new int[4 * N + 1000];
        Arrays.fill(arr, 0);
        Arrays.fill(sum, 0);
    }

    public int query(int left, int right) {
        return query(1, 0, N - 1, left, right);
    }

    private int query(int idx, int curLeft, int curRight, int targetLeft, int targetRight) {
        if (targetRight < curLeft || curRight < targetLeft) {
            return 0;
        }

        if (targetLeft <= curLeft && curRight <= targetRight) {
            return sum[idx];
        }

        int mid = (curLeft + curRight) / 2;
        return query(left(idx), curLeft, mid, targetLeft, targetRight)
            + query(right(idx), mid + 1, curRight, targetLeft, targetRight);
    }

    public void update(int pos, int val) {
        int diff = val - arr[pos];
        arr[pos] = val;
        update(1, 0, N - 1, pos, diff);
    }

    private void update(int idx, int left, int right, int pos, int diff) {
        if (left <= pos && pos <= right) {
            sum[idx] += diff;
            if (left != right) {
                int mid = (left + right) / 2;
                update(left(idx), left, mid, pos, diff);
                update(right(idx), mid + 1, right, pos, diff);
            }
        }
    }

    private int left(int idx) {
        return idx << 1;
    }

    private int right(int idx) {
        return (idx << 1) + 1;
    }
}