import java.io.BufferedInputStream;
import java.util.*;

public class C {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));

        // max(N * N) = 250,000
        int N = sc.nextInt();

        PriorityQueue<Integer> queue = new PriorityQueue<>(N * N, Collections.reverseOrder());
        for (int i = 0; i < N * N; i++)
            queue.add(sc.nextInt());

        int[] res = new int[N];
        Map<Integer, Integer> seen = new HashMap<>();

        for (int found = 0; found < N; found++) {
            // find the maximum

            int max = -1;
            while (!queue.isEmpty()) {
                max = queue.poll();
                if (seen.containsKey(max) && seen.get(max) > 0) {
                    seen.put(max, seen.get(max) - 1);
                } else {
                    break;
                }
            }

            res[found] = max;

            for (int i = 0; i < found; i++) {
                int gcd = GCD(max, res[i]);
                if (!seen.containsKey(gcd))
                    seen.put(gcd, 0);
                seen.put(gcd, seen.get(gcd) + 2);
            }

        }

        for (int i = 0; i < N; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(res[i]);
        }
    }


    //a and b cannot both be 0
    // Greatest Common Denominator
    public static int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }
}

