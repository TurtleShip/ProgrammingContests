import java.util.*;

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
