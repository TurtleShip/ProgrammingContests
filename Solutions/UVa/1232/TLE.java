import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
    UVa 1232 - SKYLINE
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3673
    https://uva.onlinejudge.org/external/12/1232.pdf
 */
public class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        final int maxRange = 100000;

        int C = Integer.parseInt(scanner.next());
        while(C-- > 0) {
            int buildings = Integer.parseInt(scanner.next());
            final Tree tree = new Tree(maxRange);
            int res = 0;
            int l,r,h;
            while(buildings-- > 0) {
                l = Integer.parseInt(scanner.next());
                r = Integer.parseInt(scanner.next());
                h = Integer.parseInt(scanner.next());
                res += tree.findOverlaps(l, r, h);
            }
            writer.println(res);
        }
        writer.flush();
    }
}

/*
    Approach.

    We keep 2 segment trees (segTree for short ). 1 segTree called "minTree",
    and another segTree called "maxTree."
    minTree keeps the minimum height in a given range.
    i.e. minTree.rangeQuery(a,b) => The shortest height in [a,b)
    maxTree keeps the maximum height in a given range.
    i.e. maxTree.rangeQuery(a,b) => The tallest height in [a,b)

   For each building, we have
   L = the left endpoint of the building
   R = the right endpoint of the building + 1 ( Note that I added one to make it convenient for my algorithm ).
   H = the height of the building

   We process buildings from back to front. For each building b, we do the below
     search(b.L, b.R) and check
     1) If minTree.rangeQuery(b.L,b.R) > b.H, then b is not overlapping anything.
        Update minTree(b.L,b.R) = b.H and return 0.

     2) If maxTree.rangeQuery(b.L,b.R) <= b.H, then b is overlapping all buildings behind it.
        Update maxTree(b.L,b.R) = b.H, and return 0.

     3) If minTree.rangeQuery(L,R) <= b.H < maxTree.rangeQuery(L,R),
        then b is overlapping in some range, but not in other ranges.
        Do subquery search(b.L, (b.L + b.R)/2, ((b.L + b.R)/2) + 1, b.R)
        until we hit 1) or 2)

   The answer is the sum of search(b.L, b.R) for all buildings.
 */

// TODO: Do lazy initialization if I get TLE.
class Tree {
    /*
        minTree[i] = the minimum height in range [a,b] where a, b is defined as below
        minTree[1] = range [1, N]
        minTree[i] = range [a,b]
        minTree[(1<<i)] = range[a, (a+b)/2]
        minTree[(1<<i)+1] = range[((a+b)/2) + 1, b]

        maxTree[i] = the maximum height in range [a,b] where a, b is defined the same as minTree.
     */
    int[] minTree;
    int[] maxTree;
    int N;

    public Tree(int N) {
        this.N = N;
        minTree = new int[4 * N + 10];
        maxTree = new int[4 * N + 10];
        Arrays.fill(minTree, 0);
        Arrays.fill(maxTree, 0);
    }

    private int left(int idx) {
        return 1 << idx;
    }

    private int right(int idx) {
        return (1 << idx) + 1;
    }


    /*
        Return the length of overlaps in [L,R]
        If [a,b] where a <= b is an overlap, then the height of all buildings within that range <= H
     */
    public int findOverlaps(int L, int R, int H) {
        update(L, R, H);
        return findOverlaps(1, 1, N, L, R, H);
    }

    private int findOverlaps(int idx, int curL, int curR, int targetL, int targetR, int targetH) {

        // The current range doesn't overlap with the target range at all.
        if (targetR < curL || curR < targetL) {
            return 0;
        }

        // range collapsed to a single point.
        if (curL >= curR) {
            return 0;
        }

        /* Current range is completely in target range. */
        if (targetL <= curL && curR <= targetR) {
            // overlaps the entire range
            if (maxTree[idx] <= targetH) {
                return curR - curL;
            }

            // no overlap
            if (minTree[idx] > targetH) {
                return 0;
            }
        }

        // overlaps some part.
        int mid = (curL + curR) / 2;
        return findOverlaps(left(idx), targetL, targetR, curL, mid, targetH)
            + findOverlaps(right(idx), targetL, targetR, mid + 1, curR, targetH);
    }

    public void update(int L, int R, int H) {
        updateTree(1, 1, N, L, R, H);
    }

    private void updateTree(int idx, int curL, int curR, int targetL, int targetR, int targetH) {
        // The current range doesn't overlap with the target range at all.
        if (targetR < curL || curR < targetL) {
            return;
        }

        if (minTree[idx] > targetH) {
            minTree[idx] = targetH;
        }

        if (maxTree[idx] < targetH) {
            maxTree[idx] = targetH;
        }

        if (curL != curR) {
            int mid = (curL + curR) / 2;
            updateTree(left(idx), curL, mid, targetL, targetR, targetH);
            updateTree(right(idx), mid + 1, curR, targetL, targetR, targetH);
        }
    }
}