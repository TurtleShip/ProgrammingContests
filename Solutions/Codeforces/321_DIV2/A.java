import java.io.BufferedInputStream;
import java.util.Scanner;

public class A {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int N = sc.nextInt();

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        int maxLength = 1;
        int cur = 1;
        for (int i = 1; i < N; i++) {
            if (arr[i] >= arr[i - 1]) {
                cur++;
            } else {
                maxLength = Math.max(maxLength, cur);
                cur = 1;
            }
        }
        maxLength = Math.max(maxLength, cur);
        System.out.println(maxLength);

    }
}