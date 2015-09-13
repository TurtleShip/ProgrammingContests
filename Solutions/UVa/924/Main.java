import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        final int N = scanner.nextInt();
        final Graph graph = new Graph(N);

        for (int i = 0; i < N; i++) {
            int E = scanner.nextInt();
            for (int j = 0; j < E; j++) {
                graph.addNeighbor(i, scanner.nextInt());
            }
        }

        final int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            final int src = scanner.nextInt();
            writer.println(graph.solve(src));
        }

        writer.flush();
    }
}

class Graph {
    int N;
    int len[];
    int adj[][];
    int dist[];
    int boom[];

    public Graph(int n) {
        N = n;
        len = new int[N];
        adj = new int[N][20];
        dist = new int[N];
        boom = new int[N];
    }

    public void addNeighbor(int from, int to) {
        adj[from][len[from]++] = to;
    }

    public String solve(int src) {
        if (len[src] == 0) return "0";
        Arrays.fill(dist, -1);
        Arrays.fill(boom, 0);

        dist[src] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int i = 0; i < len[cur]; i++) {
                int next = adj[cur][i];
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    boom[dist[next]]++;
                    queue.add(next);
                }
            }
        }


        int maxBoomSize = -1;
        int maxBoomDay = 0;
        for (int i = 1; i < N; i++) {
            if (boom[i] > maxBoomSize) {
                maxBoomSize = boom[i];
                maxBoomDay = i;
            }
        }

        return maxBoomSize + " " + maxBoomDay;
    }
}