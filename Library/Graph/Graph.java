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

           if(minStep[child] > step[curNode]) {
               System.out.printf("Edge from %d to %d is a bridge.\n", curNode, child);
           }
                minStep[curNode] = Math.min(minStep[curNode], minStep[child]);
            } else if (child != parent[curNode]) { // a back edge and not direct cycle
                minStep[curNode] = Math.min(minStep[curNode], step[child]);
            }
        }

    }
}
