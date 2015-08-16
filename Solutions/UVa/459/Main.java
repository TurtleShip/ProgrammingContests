import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// 459 - Graph Connectivity
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=400
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            if (cid != 1) writer.println();
            int maxNode = num(scanner.next().charAt(0));
            final Graph graph = new Graph(maxNode + 1);
            scanner.nextLine();
            String pair;
            while (scanner.hasNext() && (pair = scanner.nextLine()).length() > 0) {
                graph.update(num(pair.charAt(0)), num(pair.charAt(1)));
            }
            writer.println(graph.findCC());
        }
        writer.flush();
    }

    private static int num(char ch) {
        return ch - 'A';
    }
}


class Graph {
    private boolean[][] adj;
    private boolean[] visited;
    private int N;

    public Graph(int N) {
        this.N = N;
        this.adj = new boolean[N][N];
        this.visited = new boolean[N];
        for (int i = 0; i < N; i++)
            Arrays.fill(adj[i], false);
        Arrays.fill(visited, false);
    }

    public void update(int x, int y) {
        adj[x][y] = adj[y][x] = true;
    }

    public int findCC() { // find the total number of connected components
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                res++;
                visited[i] = true;
                dfs(i);
            }
        }
        return res;
    }

    public void dfs(int cur) {
        for (int next = 0; next < N; next++) {
            if (adj[cur][next] && !visited[next]) {
                visited[next] = true;
                dfs(next);
            }
        }
    }
}

