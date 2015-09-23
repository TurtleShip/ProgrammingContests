import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class B {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));

        int N = sc.nextInt();
        long diff = sc.nextLong();

        Friend[] friends = new Friend[N];

        for (int i = 0; i < N; i++) {
            friends[i] = new Friend(sc.nextLong(), sc.nextLong());
        }

        Arrays.sort(friends, new Comparator<Friend>() {
            @Override
            public int compare(Friend o1, Friend o2) {
                return Long.compare(o1.money, o2.money);
            }
        });

        if (N == 1) {
            System.out.println(friends[0].friendship);
        } else {
            long best;

            long sum = friends[0].friendship;
            int st = 0;
            int end = 1;
            while(end < N && (friends[end].money - friends[st].money) < diff) {
                sum += friends[end].friendship;
                end++;
            }

            best = sum;

            while(end < N) {
                sum -= friends[st].friendship;
                st++;
                while(end < N && (friends[end].money - friends[st].money) < diff) {
                    sum += friends[end].friendship;
                    end++;
                }
                best = Math.max(best, sum);
            }

            System.out.println(best);
        }
    }
}

class Friend {
    long money;
    long friendship;

    public Friend(long money, long friendship) {
        this.money = money;
        this.friendship = friendship;
    }
}