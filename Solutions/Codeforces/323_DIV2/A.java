import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N = sc.nextInt();

        boolean[] hs = new boolean[N+10];
        boolean[] vs= new boolean[N+10];

        Arrays.fill(hs, false);
        Arrays.fill(vs, false);

        int ct = 0;
        for(int i=1; i <= N*N; i++) {
            int h = sc.nextInt();
            int v = sc.nextInt();
            if(!hs[h] && !vs[v]) {
                hs[h] = vs[v] = true;
                if(ct > 0) writer.print(" ");
                writer.print(i);
                ct++;
            }
        }

        writer.flush();
    }
}
