import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));


        int N = sc.nextInt();
        int[] arr = new int[N];
        boolean[] taken = new boolean[N];
        for(int i=0; i < N; i++)
            arr[i] = sc.nextInt();

        Arrays.fill(taken, false);

        int info = 0;
        int res = -1;
        boolean toRight = true;

        while(info < N) {

            if(toRight) {
                for(int i=0; i < N; i++) {
                    if(!taken[i]) {
                        if(arr[i] <= info) {
                            info++;
                            taken[i] = true;
                        }
                    }
                }
            } else {
                for(int i=N-1; i >= 0; i--) {
                    if(!taken[i]) {
                        if(arr[i] <= info) {
                            info++;
                            taken[i] = true;
                        }
                    }
                }

            }
            res++;
            toRight = !toRight;
        }

        System.out.println(res);
    }
}
