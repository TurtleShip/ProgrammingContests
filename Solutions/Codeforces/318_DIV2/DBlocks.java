import java.io.BufferedInputStream;
import java.util.Scanner;

public class DBlocks {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));

        int N = scanner.nextInt();
        int[] height = new int[N + 1];
        int[] shutdown = new int[N + 1];

        for (int i = 1; i <= N; i++)
            height[i] = scanner.nextInt();

        int cascade = 0;
        for (int i = 1; i <= N; i++) {
            cascade = Math.min(cascade, height[i] - i); // note that cascade is always a non-positive number
            shutdown[i] = i + cascade;
        }

        cascade = 0;
        for (int i = N; i >= 1; i--) {
            cascade = Math.min(cascade, height[i] - (N - i + 1));
            shutdown[i] = Math.min(shutdown[i], (N - i + 1) + cascade);
        }

        int minTime = 0;
        for (int i = 1; i <= N; i++)
            minTime = Math.max(minTime, shutdown[i]);

        System.out.println(minTime);
    }
}