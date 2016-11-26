// Solves Maximum Cardinality Bipartite Matching
// Runtime : O(V * E)
class MCBM {
    private static int UNMATCHED = -1;
    private int L; // number of nodes on the left
    private int R; // number of nodes on the right
    private int N; // the total number of nodes
    private List<List<Integer>> adjList;
    private boolean[] visited; // visited[i] = true if node i has been visited
    private int[] matched; // matched[i] = j if node i is matched to node j.   j = -1 is node is unmatched

    public MCBM(int L, int R) {
        this.L = L;
        this.R = R;
        N = L + R;
        adjList = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            adjList.add(new LinkedList<>());
        }
        visited = new boolean[N];
        matched = new int[N];
    }

    /*
        Links node "left" to node "right"
        Note that 0 <= left < L,  0 <= right < R
     */
    public void link(int left, int right) {
        adjList.get(left).add(L + right);
        adjList.get(L + right).add(left);
    }

    // returns the maximum number of possible matches
    public int maxMatching() {
        Arrays.fill(matched, -1);

        int numMatch = 0;
        for (int i = 0; i < L; i++) {
            Arrays.fill(visited, false);
            if (canMatch(i)) numMatch++;
        }

        return numMatch;
    }

    // Returns true if the current node can be matched to a node on the other side
    private boolean canMatch(int node) {
        if(visited[node]) return false;
        visited[node] = true;

        for (int next : adjList.get(node)) {
            if (matched[next] == UNMATCHED || canMatch(matched[next])) {
                matched[next] = node;
                return true;
            }
        }

        return false;
    }
}
