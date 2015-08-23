/*
    Nodes should be numbered [0...N-1]
    This is for un-directed graph.
 */
class Graph {
    static int UNVISITED = -1;
    int N; // the total number of nodes
    int step[]; // step[x] = the number of steps taken to get to node x during dfs starting at its root node.
    int minStep[]; // minStep[x] = the min(step[y]) where y are nodes reacheable from a subtree whose root is x.
    int parent[];
    int totalStep;
    int root;
    int rootChildren;

    ArrayList<List<Integer>> adj;
    List<IntPair> bridges;
    boolean isArticulationVertex[];


    public Graph(int N) {
        this.N = N;
        this.step = new int[N];
        this.minStep = new int[N];
        this.parent = new int[N];
        this.totalStep = 0;
        this.adj = new ArrayList<>(N);
        this.bridges = new ArrayList<>();
        this.isArticulationVertex = new boolean[N];

        Arrays.fill(step, UNVISITED);
        for (int i = 0; i < N; i++)
            adj.add(i, new ArrayList<Integer>());
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

    public List<Integer> getArticulationPoints() {
        List<Integer> points = new ArrayList<>();
        for (int i = 0; i < N; i++)
            if (isArticulationVertex[i])
                points.add(i);
        return points;
    }

    // Must call findArticulations first. Returns all bridges sorted in ascending order.
    public List<IntPair> getBridges() {
        Collections.sort(bridges, new Comparator<IntPair>() {
            @Override
            public int compare(IntPair o1, IntPair o2) {
                int compFirst = Integer.compare(o1.first, o2.first);
                if (compFirst != 0) return compFirst;
                return Integer.compare(o1.second, o2.second);
            }
        });
        return bridges;
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
