import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

class Main {
    public static void main(String[] args) {

        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, M, P, V, W;
        while ((N = scanner.nextInt()) != 0 && (M = scanner.nextInt()) != 0) {

            final Graph graph = new Graph(N);

            while ((M--) > 0) {
                V = scanner.nextInt() - 1;
                W = scanner.nextInt() - 1;
                P = scanner.nextInt();
                graph.addEdge(V, W);
                if (P == 2)
                    graph.addEdge(W, V);
            }

            int res = graph.findSCC();
            writer.println(res == 1 ? "1" : "0");
        }
        writer.flush();
    }
}


/*
    Directed Graph. Nodes are numbered [0.N-1]
 */
class Graph {
    static int UNVISITED = -1;
    int minSteps[];
    int steps[];
    int N;
    int totalSteps;
    boolean[] isVisited;
    Stack<Integer> path;
    List<List<Integer>> adj;
    int sccCount;

    public Graph(int N) {
        this.N = N;
        this.minSteps = new int[N];
        this.steps = new int[N];
        this.isVisited = new boolean[N];
        path = new Stack<>();
        adj = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            adj.add(new ArrayList<Integer>());
    }

    public void addEdge(int from, int to) {
        adj.get(from).add(to);
    }

    /*
        finds all in Strongly Connected Components, and return them.
        ( In a SCC, each vertex has a path to all other vertex ).
        Uses Tarjan's algorithm.
      */
    public int findSCC() {
        totalSteps = 0;
        sccCount = 0;
        Arrays.fill(steps, UNVISITED);
        Arrays.fill(isVisited, false);
        for (int i = 0; i < N; i++)
            if (steps[i] == UNVISITED)
                tarjanSCC(i);
        return sccCount;
    }

    private void tarjanSCC(int curNode) {
        minSteps[curNode] = steps[curNode] = totalSteps++;
        path.push(curNode);
        isVisited[curNode] = true;
        for (int neighbor : adj.get(curNode)) {
            if (steps[neighbor] == UNVISITED)
                tarjanSCC(neighbor);
            if (isVisited[neighbor])
                minSteps[curNode] = Math.min(minSteps[curNode], minSteps[neighbor]);
        }

        if (minSteps[curNode] == steps[curNode]) {
            int tmp;
            do {
                tmp = path.pop();
                isVisited[tmp] = false;
            } while (curNode != tmp);
            sccCount++;
        }
    }
}