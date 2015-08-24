import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

// UVa 247 - Calling Circles
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=183
class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        int N, M, cid = 1;
        String from, to;
        while ((N = scanner.nextInt()) != 0 && (M = scanner.nextInt()) != 0) {

            final Graph graph = new Graph(N);
            Map<String, Integer> names = new HashMap<>();
            int id = 0;
            while ((M--) > 0) {
                from = scanner.next();
                to = scanner.next();
                if (!names.containsKey(from)) names.put(from, id++);
                if (!names.containsKey(to)) names.put(to, id++);
                graph.addEdge(names.get(from), names.get(to));
            }
            Map<Integer, String> ids = new HashMap<>();
            for (Map.Entry<String, Integer> entry : names.entrySet()) {
                ids.put(entry.getValue(), entry.getKey());
            }
            List<List<Integer>> scc = graph.findSCC();

            if (cid > 1) writer.println();
            writer.printf("Calling circles for data set %d:\n", cid++);
            for (List<Integer> circle : scc) {
                StringBuilder res = new StringBuilder();
                String delim = "";
                for (int x : circle) {
                    res.append(delim).append(ids.get(x));
                    delim = ", ";
                }
                writer.println(res.toString());
            }
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
    List<List<Integer>> scc;

    public Graph(int N) {
        this.N = N;
        this.minSteps = new int[N];
        this.steps = new int[N];
        this.isVisited = new boolean[N];
        path = new Stack<>();
        adj = new ArrayList<>(N);
        scc = new ArrayList<>();
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
    public List<List<Integer>> findSCC() {
        totalSteps = 0;

        Arrays.fill(steps, UNVISITED);
        Arrays.fill(isVisited, false);
        for (int i = 0; i < N; i++)
            if (steps[i] == UNVISITED)
                tarjanSCC(i);
        return scc;
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
            List<Integer> curScc = new ArrayList<>();
            do {
                tmp = path.pop();
                curScc.add(tmp);
                isVisited[tmp] = false;
            } while (curNode != tmp);
            scc.add(curScc);
        }
    }
}