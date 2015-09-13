import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        final int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            if (cid > 1) writer.println();
            String word;
            final Dictionary dictionary = new Dictionary();
            while (!(word = scanner.next()).equals("*")) {
                dictionary.addWord(word);
            }
            dictionary.getReady();

            String line = scanner.nextLine();
            while (scanner.hasNextLine() && !(line = scanner.nextLine()).equals("")) {
                String[] split = line.split(" ");
                writer.println(dictionary.query(split[0], split[1]));
            }
        }

        writer.flush();
    }
}

class Dictionary {
    int N = 0; // the total number of words
    String[] words = new String[210];
    int[] len = new int[210];
    int[][] neighbors = new int[210][210];
    int[] dist = new int[210];
    Map<String, Integer> ids = new HashMap<>();


    public void addWord(final String word) {
        words[N] = word;
        ids.put(word, N);
        N++;
    }

    public void getReady() {
        Arrays.fill(len, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (canGo(words[i], words[j])) {
                    neighbors[i][len[i]++] = j;
                    neighbors[j][len[j]++] = i;
                }
            }
        }
    }

    public String query(final String from, final String to) {
        final int src = ids.get(from);
        final int dst = ids.get(to);
        Arrays.fill(dist, 0, N, -1);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        dist[src] = 0;

        while (!queue.isEmpty()) {
            final int cur = queue.poll();
            if (cur == dst) break;

            for (int i = 0; i < len[cur]; i++) {
                int next = neighbors[cur][i];
                if (dist[next] > -1) continue;
                dist[next] = dist[cur] + 1;
                queue.add(next);
            }
        }

        return from + " " + to + " " + dist[dst];
    }

    private boolean canGo(final String from, final String to) {
        if (from.length() != to.length()) return false;
        boolean sawDiff = false;
        for (int i = 0; i < from.length(); i++) {
            if (from.charAt(i) != to.charAt(i)) {
                if (sawDiff) return false;
                else sawDiff = true;
            }
        }
        return true;
    }
}