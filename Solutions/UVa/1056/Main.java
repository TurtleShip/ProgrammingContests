import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, R, cid = 1;
        while ((N = scanner.nextInt()) != 0 & (R = scanner.nextInt()) != 0) {
            final Graph graph = new Graph(N);
            for (int i = 0; i < R; i++)
                graph.add(scanner.next(), scanner.next());
            writer.printf("Network %d: %s\n\n", cid++, graph.solve());
        }

        writer.flush();
    }
}

class Graph {
    static int INF = 1_000_000;
    int N;
    int freeId;
    int[][] dist;
    Map<String, Integer> ids;

    public Graph(int N) {
        this.N = N;
        dist = new int[N][N];
        ids = new HashMap<>();
        freeId = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = INF;
        for (int i = 0; i < N; i++)
            dist[i][i] = 0;
    }

    public void add(String x, String y) {
        final int xId = getId(x);
        final int yId = getId(y);
        dist[xId][yId] = dist[yId][xId] = 1;
    }

    public String solve() {
        for (int mid = 0; mid < N; mid++)
            for (int st = 0; st < N; st++)
                for (int end = 0; end < N; end++)
                    dist[st][end] = Math.min(dist[st][end], dist[st][mid] + dist[mid][end]);
        int maxDist = 0;
        boolean isDisconnected = false;
        for (int i = 0; !isDisconnected && i < N; i++)
            for (int j = 0; !isDisconnected && j < N; j++) {
                if (i == j) continue;
                maxDist = Math.max(maxDist, dist[i][j]);
                isDisconnected = dist[i][j] == INF;
            }

        if (isDisconnected) return "DISCONNECTED";
        else return Integer.toString(maxDist);
    }

    private int getId(String x) {
        if (!ids.containsKey(x)) {
            ids.put(x, freeId++);
        }
        return ids.get(x);
    }
}