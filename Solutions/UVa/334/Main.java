import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/*
    This one is a shitty problem IMO.
    The problem doesn't specify limits of input size, which makes it impossible
    to tell if an algorithm will run in time or not.
    Also, there is a weird formatting issue with the problem judge.
    Check out the UVa forum on this here :
    https://uva.onlinejudge.org/board/viewtopic.php?f=35&t=20257&p=68030&hilit=334&sid=e396084e0e7053a32ac9e038cb66c960#p68030
 */
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, cid = 1;
        while ((N = scanner.nextInt()) != 0) {

            int total = 0; // the total number of nodes
            Map<String, Integer> ids = new HashMap<>();
            final Events events = new Events();
            for (int i = 0; i < N; i++) {
                int R = scanner.nextInt();
                for (int j = 0; j < R; j++) {
                    ids.put(scanner.next(), total);
                    if (j > 0) {
                        events.setCanGo(total - 1, total);
                    }
                    total++;
                }
            }

            int R = scanner.nextInt();
            for (int i = 0; i < R; i++) {
                final int from = ids.get(scanner.next());
                final int to = ids.get(scanner.next());
                events.setCanGo(from, to);
            }

            Map<Integer, String> names = new HashMap<>();
            for (Map.Entry<String, Integer> entry : ids.entrySet()) {
                names.put(entry.getValue(), entry.getKey());
            }
            final String result = events.solve(total, names);
            writer.printf("Case %d, %s\n", cid++, result);
        }

        writer.flush();
    }
}

class Events {
    private boolean[][] canGo = new boolean[200][200]; // randomly guessing the max size here... :(

    public void setCanGo(int x, int y) {
        canGo[x][y] = true;
    }

    public String solve(int N, final Map<Integer, String> names) {
        int foundSolution = 0;
        for (int mid = 0; mid < N; mid++)
            for (int st = 0; st < N; st++)
                for (int end = 0; end < N; end++) {
                    canGo[st][end] |= canGo[st][mid] && canGo[mid][end];
                }
        String pairs = "";
        for (int x = 0; x < N; x++)
            for (int y = x + 1; y < N; y++) {
                if (!canGo[x][y] && !canGo[y][x]) {
                    if (foundSolution < 2) {
                        pairs += String.format("(%s,%s) ", names.get(x), names.get(y));
                    }
                    foundSolution++;
                }
            }
        if (foundSolution == 0) return "no concurrent events.";
        return Integer.toString(foundSolution) + " concurrent events:\n" + pairs;
    }
}