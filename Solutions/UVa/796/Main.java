import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

// 796 - Critical Links
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=737
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, from, E, to;
        String tmp;
        while (scanner.hasNextInt()) {
            N = scanner.nextInt();
            if (N != 0) {
                Graph graph = new Graph(N);
                for (int i = 0; i < N; i++) {
                    from = scanner.nextInt();
                    tmp = scanner.next();
//                    System.out.println("tmp : [" + tmp + "]");
                    E = Integer.parseInt(tmp.substring(1, tmp.length() - 1));
                    for (int j = 0; j < E; j++) {
                        to = scanner.nextInt();
                        graph.addEdge(from, to);
                    }
                }
                graph.findArticulations();
                List<IntPair> bridges = graph.bridges;
                writer.printf("%d critical links\n", bridges.size());
                Collections.sort(bridges, new Comparator<IntPair>() {
                    @Override
                    public int compare(IntPair o1, IntPair o2) {
                        int compFirst = Integer.compare(o1.first, o2.first);
                        if (compFirst != 0) return compFirst;
                        return Integer.compare(o1.second, o2.second);
                    }
                });
                for (IntPair pair : bridges) {
                    writer.printf("%d - %d\n", pair.first, pair.second);
                }
            } else {
                writer.println("0 critical links");
            }

            writer.println();
        }

        writer.flush();
    }
}

class IntPair {
    int first, second;

    public IntPair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

/*
    Nodes should be numbered [0...N-1]
    This is for un-directed graph.
 */
class Graph {
    static int UNVISITED = -1;
    int N; // the total number of nodes
    // step[x] = the number of steps taken to get to node x during dfs starting at its root node.
    int step[];
    // minStep[x] = the min(step[y]) where y are nodes reacheable from a subtree whose root is x.
    int minStep[];
    int parent[];
    ArrayList<List<Integer>> adj;
    List<IntPair> bridges;

    boolean isArticulationVertex[];
    int totalStep;
    int root;
    int rootChildren;

    public Graph(int N) {
        this.N = N;
        this.step = new int[N];
        this.minStep = new int[N];
        this.parent = new int[N];
        this.adj = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            adj.add(i, new ArrayList<Integer>());
        this.isArticulationVertex = new boolean[N];
        this.totalStep = 0;
        this.bridges = new ArrayList<>();
        Arrays.fill(step, UNVISITED);
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

    public int totalArticulationPoints() {
        int res = 0;
        for (boolean isArt : isArticulationVertex)
            if (isArt)
                res++;
        return res;
    }

    private void findArticulationPointAndBridge(int curNode) {
        step[curNode] = minStep[curNode] = totalStep++;
        for (int child : adj.get(curNode)) {
            if (step[child] == UNVISITED) {
                parent[child] = curNode;
                if (curNode == root) rootChildren++;

                findArticulationPointAndBridge(child);

//                if (minStep[child] >= step[curNode]) {
//                    // every other node must go through 'curNode' to reach 'child'
//                    isArticulationVertex[curNode] = true;
//                }

                if (minStep[child] > step[curNode]) {
                    bridges.add(new IntPair(Math.min(curNode, child), Math.max(curNode, child)));
                }
                minStep[curNode] = Math.min(minStep[curNode], minStep[child]);
            } else if (child != parent[curNode]) { // a back edge and not direct cycle
                minStep[curNode] = Math.min(minStep[curNode], step[child]);
            }
        }

    }
}