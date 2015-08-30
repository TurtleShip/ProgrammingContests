import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class ABear {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        final PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        int N = scanner.nextInt();
        int me = scanner.nextInt();
        int candies = 0;
        for(int i=0; i < N-1; i++) {
            pq.add(scanner.nextInt());
        }

        while(!pq.isEmpty()) {
            int top = pq.remove();
            if(top < me) break;
            top--;
            me++;
            candies++;
            pq.add(top);
        }

        writer.println(candies);
        writer.flush();
    }
}
