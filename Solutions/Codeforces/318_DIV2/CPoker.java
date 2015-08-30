import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class CPoker {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        int N = scanner.nextInt();

        int[] clean = new int[N];
        for(int i=0; i < N; i++) {
            int cur = scanner.nextInt();
            while(cur % 2 == 0)
                cur /= 2;
            while(cur % 3 == 0)
                cur /= 3;
            clean[i] = cur;
        }

        // now everyone should be the same as others
        boolean good = true;
        for(int i=1; good && i < N; i++)
            good &= clean[i] == clean[0];
        writer.println(good ? "YES" : "NO");
        writer.flush();
    }
}
