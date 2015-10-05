import java.io.BufferedInputStream;
import java.util.Scanner;

public class D_dp {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));

        int N = sc.nextInt();
        int T = sc.nextInt();
        int[] arr = new int[N];

        for (int i = 0; i < N; i++)
            arr[i] = sc.nextInt();

        /*
            For each repeating strip, we can choose one of the below
            1) choose the same number as the last number
            2) increase the number if possible

            Option 2) won't be available after at most N iterations,
            since there are at most N numbers.


            dpPrefix[t][y]
            = The length of maximum non-decreasing sequence when
            ending at index 'y', after repeating the array 't' times.
            i.e. The array itself is repeating the array 1 time.
         */
        int[][] dpPrefix = new int[2 * N + 10][N];
        // base case
        for (int i = 0; i < N; i++)
            dpPrefix[0][i] = 0; // if you don't use array at all, you get a sequence of length zero

        // O(N^3)
        for (int t = 1; t <= 2 * N; t++) {
            for (int i = 0; i < N; i++) {
                /*
                    An element before dpPrefix[t][i] could have been either
                        1) any element from a previous strip whose number <= arr[i].
                        2) an element from this strip whose number <= arr[i] and whose index < i
                 */

                // case 1
                for (int j = 0; j < N; j++) {
                    if (arr[j] <= arr[i])
                        dpPrefix[t][i] = Math.max(dpPrefix[t][i], 1 + dpPrefix[t - 1][j]);
                }

                // case 2
                for (int j = 0; j < i; j++) {
                    if (arr[j] <= arr[i])
                        dpPrefix[t][i] = Math.max(dpPrefix[t][i], 1 + dpPrefix[t][j]);
                }
            }
        }

        /*
            dpSuffix[t][x][y]
             = The length of maximum non-decreasing sequence whose elements are >= arr[x],
              ending at index 'y',
              after repeating the array 't' times.
            i.e. The array itself is repeating the array 1 time.
         */
        int[][][] dpSuffix = new int[N + 10][N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dpSuffix[0][i][j] = 0;

        for (int st = 0; st < N; st++) {
            for (int t = 1; t <= N; t++) {
                for (int i = 0; i < N; i++) {
                    if (arr[i] < arr[st]) continue;

                    for (int j = 0; j < N; j++) {
                        if (arr[st] <= arr[j] && arr[j] <= arr[i])
                            dpSuffix[t][st][i] = Math.max(dpSuffix[t][st][i], 1 + dpSuffix[t - 1][st][j]);
                    }

                    for (int j = 0; j < i; j++) {
                        if (arr[st] <= arr[j] && arr[j] <= arr[i])
                            dpSuffix[t][st][i] = Math.max(dpSuffix[t][st][i], 1 + dpSuffix[t][st][j]);
                    }
                }
            }
        }

        /*
            suffix[x] = the length of maximum non-decreasing sequence when starting at index x
            using the array exactly N times.
         */
        int[] suffix = new int[N];
        for (int st = 0; st < N; st++) {
            suffix[st] = 0;
            for (int end = 0; end < N; end++)
                suffix[st] = Math.max(suffix[st], dpSuffix[N][st][end]);
        }


        if (T <= 2 * N) {
            int res = 0;
            for (int i = 0; i < N; i++) {
                res = Math.max(res, dpPrefix[T][i]);
            }
            System.out.println(res);
        } else {
            int res = 0;
            for (int cut = 0; cut < N; cut++) {
                int repeat = 0;
                for (int i = 0; i < N; i++) {
                    if (arr[i] == arr[cut]) repeat++;
                }
                res = Math.max(res, dpPrefix[N][cut] + (T - 2 * N) * repeat + suffix[cut]);
            }
            System.out.println(res);
        }
    }
}
