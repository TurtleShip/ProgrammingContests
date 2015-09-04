import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

// UVa 10765 - Doves and bombs
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, M, x, y;

        while ((N = scanner.nextInt()) != 0 && (M = scanner.nextInt()) != 0) {
            final Graph graph = new Graph(N);
            while ((x = scanner.nextInt()) != -1 & (y = scanner.nextInt()) != -1) {
                graph.addEdge(x, y);
            }

            graph.findArticulations();
            List<IntPair> result = graph.articulationPointsWithPigeon();
            for (int i = 0; i < M; i++)
                writer.printf("%d %d\n", result.get(i).node, result.get(i).pigeon);
            writer.println();
        }
        writer.flush();
    }
}

class IntPair {
    int node;
    int pigeon;

    public IntPair(int node, int pigeon) {
        this.node = node;
        this.pigeon = pigeon;
    }
}

/*
    Nodes should be numbered [0...N-1]
    This is for un-directed graph.
 */
class Graph {
    static int UNVISITED = -1;
    int N; // the total number of nodes
    int step[]; // step[x] = the number of steps taken to get to node x during dfs starting at its root node.
    int minStep[]; // minStep[x] = the min(step[y]) where y are nodes reachable from a subtree whose root is x.
    int parent[];
    int totalStep;
    int root;
    int rootChildren;
    boolean[] visited;

    ArrayList<List<Integer>> adj;
    boolean isArticulationVertex[];


    public Graph(int N) {
        this.N = N;
        this.step = new int[N];
        this.minStep = new int[N];
        this.parent = new int[N];
        this.totalStep = 0;
        this.adj = new ArrayList<>(N);
        this.isArticulationVertex = new boolean[N];
        this.visited = new boolean[N];
        Arrays.fill(step, UNVISITED);
        for (int i = 0; i < N; i++)
            adj.add(i, new LinkedList<Integer>());
    }

    public void addEdge(int x, int y) {
        adj.get(x).add(y);
        adj.get(y).add(x);
    }

    public void findArticulations() {
        for (int i = 0; i < N; i++) {
            if (step[i] == UNVISITED) {
                root = i;
                rootChildren = 0;
                findArticulationPointAndBridge(root);
                isArticulationVertex[root] = rootChildren > 1;
            }
        }
    }

    public List<IntPair> articulationPointsWithPigeon() {
        List<IntPair> result = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (isArticulationVertex[i]) {
                int pigeon = 0;
                Arrays.fill(visited, false);
                visited[i] = true;
                // naive approach.
                for (int child : adj.get(i)) {
                    if (visited[child]) continue;
                    visited[child] = true;
                    pigeon++;
                    fill(child);
                }
                result.add(new IntPair(i, pigeon));
            }
        }

        for (int i = 0; i < N; i++)
            if (!isArticulationVertex[i])
                result.add(new IntPair(i, 1));

        Collections.sort(result, new Comparator<IntPair>() {
            @Override
            public int compare(IntPair o1, IntPair o2) {
                int pigeonComp = Integer.compare(o2.pigeon, o1.pigeon);
                if (pigeonComp != 0) return pigeonComp;
                return Integer.compare(o1.node, o2.node);
            }
        });

        return result;
    }

    private void fill(int cur) {
        for (int child : adj.get(cur)) {
            if (!visited[child]) {
                visited[child] = true;
                fill(child);
            }
        }
    }

    private void findArticulationPointAndBridge(int curNode) {
        step[curNode] = minStep[curNode] = totalStep++;
        for (int child : adj.get(curNode)) {
            if (step[child] == UNVISITED) {
                parent[child] = curNode;
                if (curNode == root) rootChildren++;

                findArticulationPointAndBridge(child);

                if (minStep[child] >= step[curNode]) {
                    // every other node must go through 'curNode' to reach 'child'
                    isArticulationVertex[curNode] = true;
                }

                minStep[curNode] = Math.min(minStep[curNode], minStep[child]);
            } else if (child != parent[curNode]) { // a back edge and not direct cycle
                minStep[curNode] = Math.min(minStep[curNode], step[child]);
            }
        }
    }
}