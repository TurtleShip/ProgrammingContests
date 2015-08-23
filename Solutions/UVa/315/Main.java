import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

// 315 - Network
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=251
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        int N;
        while ((N = scanner.nextInt()) != 0) {
            final Graph graph = new Graph(N);
            scanner.nextLine();
            String str;
            while (!(str = scanner.nextLine()).equals("0")) {
                String[] split = str.split(" ");
                int from = Integer.parseInt(split[0]) - 1;
                for (int i = 1; i < split.length; i++) {
                    graph.addEdge(from, Integer.parseInt(split[i]) - 1);
                }
            }
            graph.findArticulations();
            int total = graph.totalArticulationPoints();
            writer.println(total);
        }
        writer.flush();
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

                if (minStep[child] >= step[curNode]) {
                    // every other node must go through 'curNode' to reach 'child'
                    isArticulationVertex[curNode] = true;
                }

//            if(minStep[child] > step[curNode]) {
//                System.out.printf("Edge from %d to %d is a bridge.\n", curNode, child);
//            }
                minStep[curNode] = Math.min(minStep[curNode], minStep[child]);
            } else if (child != parent[curNode]) { // a back edge and not direct cycle
                minStep[curNode] = Math.min(minStep[curNode], step[child]);
            }
        }

    }
}