import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

// UVa 11297 Census
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2272
public class Main {

    public static void main(String[] args) {

        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        int N = scanner.nextInt();
        int[][] population = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                population[i][j] = scanner.nextInt();
            }

        final City city = new City(population);
        int Q = scanner.nextInt();
        while ((Q--) > 0) {
            final String cmd = scanner.next();
            if (cmd.equals("q")) {
                int r1 = scanner.nextInt() - 1;
                int c1 = scanner.nextInt() - 1;
                int r2 = scanner.nextInt() - 1;
                int c2 = scanner.nextInt() - 1;
                int max = city.getMax(r1, c1, r2, c2);
                int min = city.getMin(r1, c1, r2, c2);
                writer.printf("%d %d\n", max, min);
            } else {
                final int r = scanner.nextInt() - 1;
                final int c = scanner.nextInt() - 1;
                final int v = scanner.nextInt();
                city.update(r, c, v);
            }
        }

        writer.flush();
    }
}

class City {

    private SegMaxTree[] rowMax;
    private SegMinTree[] rowMin;
    int N;

    public City(int[][] population) {
        this.N = population[0].length;
        rowMax = new SegMaxTree[N];
        rowMin = new SegMinTree[N];

        for (int i = 0; i < N; i++) {
            rowMax[i] = new SegMaxTree(population[i]);
            rowMin[i] = new SegMinTree(population[i]);
        }
    }

    public void update(int row, int col, int val) {
        rowMax[row].update(col, val);
        rowMin[row].update(col, val);
    }

    public int getMax(int r1, int c1, int r2, int c2) {
        int res = rowMax[r1].query(c1, c2);
        int r = r1 + 1;
        while (r <= r2) {
            res = Math.max(res, rowMax[r].query(c1, c2));
            r++;
        }
        return res;
    }

    public int getMin(int r1, int c1, int r2, int c2) {
        int res = rowMin[r1].query(c1, c2);
        int r = r1 + 1;
        while (r <= r2) {
            res = Math.min(res, rowMin[r].query(c1, c2));
            r++;
        }
        return res;
    }
}


class SegMinTree {
    int N;
    int[] segTree;


    public SegMinTree(int[] arr) {
        this.N = arr.length;
        segTree = new int[4 * N + 1000];
        build(1, 0, N - 1, arr);
    }

    private void build(int idx, int left, int right, int[] arr) {
        if (left == right) {
            segTree[idx] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(left(idx), left, mid, arr);
            build(right(idx), mid + 1, right, arr);
            segTree[idx] = Math.min(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    public int query(int left, int right) {
        return query(1, 0, N - 1, left, right);
    }

    private int query(int idx, int curLeft, int curRight, int targetLeft, int targetRight) {
        // Completely out of range
        if (targetRight < curLeft || curRight < targetLeft) {
            return Integer.MAX_VALUE;
        }

        if (targetLeft <= curLeft && curRight <= targetRight) {
            return segTree[idx];
        }

        int mid = (curLeft + curRight) / 2;
        return Math.min(query(left(idx), curLeft, mid, targetLeft, targetRight),
            query(right(idx), mid + 1, curRight, targetLeft, targetRight));
    }

    public void update(int pos, int val) {
        update(1, 0, N - 1, pos, val);
    }

    private void update(int idx, int left, int right, int pos, int val) {

        if (left == right) {
            if (pos == right) segTree[idx] = val;
            return;
        }

        if (left <= pos && pos <= right) {
            int mid = (left + right) / 2;
            update(left(idx), left, mid, pos, val);
            update(right(idx), mid + 1, right, pos, val);
            segTree[idx] = Math.min(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    private int left(int idx) {
        return idx << 1;
    }

    private int right(int idx) {
        return (idx << 1) + 1;
    }
}


class SegMaxTree {
    int N;
    int[] segTree;


    public SegMaxTree(int[] arr) {
        this.N = arr.length;
        segTree = new int[4 * N + 1000];
        build(1, 0, N - 1, arr);
    }

    private void build(int idx, int left, int right, int[] arr) {
        if (left == right) {
            segTree[idx] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(left(idx), left, mid, arr);
            build(right(idx), mid + 1, right, arr);
            segTree[idx] = Math.max(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    public int query(int left, int right) {
        return query(1, 0, N - 1, left, right);
    }

    private int query(int idx, int curLeft, int curRight, int targetLeft, int targetRight) {
        // Completely out of range
        if (targetRight < curLeft || curRight < targetLeft) {
            return Integer.MIN_VALUE;
        }

        if (targetLeft <= curLeft && curRight <= targetRight) {
            return segTree[idx];
        }

        int mid = (curLeft + curRight) / 2;
        return Math.max(query(left(idx), curLeft, mid, targetLeft, targetRight),
            query(right(idx), mid + 1, curRight, targetLeft, targetRight));
    }

    public void update(int pos, int val) {
        update(1, 0, N - 1, pos, val);
    }

    private void update(int idx, int left, int right, int pos, int val) {

        if (left == right) {
            if (left == pos) segTree[idx] = val;
            return;
        }
        if (left <= pos && pos <= right) {
            int mid = (left + right) / 2;
            update(left(idx), left, mid, pos, val);
            update(right(idx), mid + 1, right, pos, val);
            segTree[idx] = Math.max(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    private int left(int idx) {
        return idx << 1;
    }

    private int right(int idx) {
        return (idx << 1) + 1;
    }
}